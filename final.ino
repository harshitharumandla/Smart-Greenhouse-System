#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial gsm(10, 11);

// Relay Pins
#define FAN 8      // IN1
#define PUMP 7     // IN3
#define BULB 6     // IN4

// Sensor Pins
#define LDR A0
#define SOIL A1

// 3 Hours Interval
unsigned long previousMillis = 0;
const unsigned long interval = 10800000;  // 3 hours

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();

  pinMode(FAN, OUTPUT);
  pinMode(PUMP, OUTPUT);
  pinMode(BULB, OUTPUT);

  digitalWrite(FAN, HIGH);
  digitalWrite(PUMP, HIGH);
  digitalWrite(BULB, HIGH);
}

void sendSMS(String message) {
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+916302462873\"");
  delay(1000);
  gsm.print(message);
  gsm.write(26);
  delay(5000);
}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int ldrValue = analogRead(LDR);
  int soilValue = analogRead(SOIL);

  // Fan Control
  if (temp > 35) {
    digitalWrite(FAN, LOW);
  } else {
    digitalWrite(FAN, HIGH);
  }

  // Bulb Control
  if (ldrValue >300) {
    digitalWrite(BULB,HIGH);
  } else {
    digitalWrite(BULB, LOW);
  }

  // Pump Control
  if (soilValue >600) {
    digitalWrite(PUMP, LOW);
  } else {
    digitalWrite(PUMP, HIGH);
  }

  // LCD Display
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C H:");
  lcd.print(hum);

  lcd.setCursor(0,1);
  lcd.print("Soil:");
  lcd.print(soilValue);
  lcd.print("    ");

  // SMS Every 3 Hours
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    String message = "Temp: " + String(temp) + " C\n";
    message += "Humidity: " + String(hum) + " %\n";
    message += "Soil: " + String(soilValue);

    sendSMS(message);
  }

  delay(2000);
}