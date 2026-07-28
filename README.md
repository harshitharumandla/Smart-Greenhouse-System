# Smart Greenhouse System

## Overview

The Smart Greenhouse System is an Arduino-based project that automatically monitors and controls environmental conditions inside a greenhouse. It helps maintain suitable conditions for plant growth by monitoring temperature, humidity, soil moisture, and light intensity.

## Features

* Automatic irrigation based on soil moisture
* Temperature and humidity monitoring
* Light intensity monitoring
* Automatic control of connected devices using relay modules
* Real-time sensor data display

## Components Used

* Arduino Uno
* DHT11 Temperature and Humidity Sensor
* Soil Moisture Sensor
* LDR (Light Dependent Resistor)
* Relay Module
* GSM Module (if used)
* Water Pump
* Jumper Wires
* Breadboard
* Power Supply

## Software Used

* Arduino IDE
* Embedded C

## Working

The sensors continuously monitor the greenhouse environment. When the soil moisture level falls below a predefined threshold, the relay activates the water pump for irrigation. Temperature, humidity, and light intensity are also monitored to help maintain optimal growing conditions.

## Project Structure

```text
Smart_Greenhouse_System.ino
README.md
```

## Future Improvements

* IoT monitoring using Wi-Fi
* Mobile application for remote monitoring
* Cloud-based data logging
* AI-based plant health prediction

## Author

Harshitha Rumandla
