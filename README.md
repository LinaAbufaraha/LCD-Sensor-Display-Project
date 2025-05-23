# 📟 LCD Sensor Display – Arduino Project

This project demonstrates how to build a simple Arduino system that reads data from two analog/digital sensors and displays the results on a 16x2 LCD using custom icons. The values switch every 2 seconds between temperature/humidity and light level.

---

## 🧠 Overview

The system reads:
- 🌡️ **Temperature and humidity** from a **DHT11** sensor on pin **A0**
- 💡 **Light level** from an **LDR** sensor on pin **A1**

The LCD shows:
- A custom **thermometer icon** with temperature and humidity
- A custom **light bulb icon** with light level

The display alternates every **2 seconds**, using only built-in Arduino functions (no external libraries).

---

## 🔧 Features

- Reads temperature, humidity, and light intensity
- Uses DHT11 and LDR sensors
- Custom icons are drawn manually (bit-by-bit) without graphics libraries on the LCD
- Alternating display every 2 seconds
- Built first in simulation, then implemented practically
- Documented with photos, video, and written report

---

## ⚙️ Circuit Design

The circuit was designed in **Tinkercad**, then built and tested physically in the lab.

### 🧰 Components used:
- 1 x Arduino Uno
- 1 x DHT11 sensor
- 1 x LDR sensor
- 1 x 16x2 LCD
- Resistors and jumper wires
- Breadboard

---

## 🔌 Wiring Diagram

The following image shows the full wiring of the circuit including DHT11, LDR, and LCD connections:

![Wiring Diagram](photos/wiring_diagram.jpg)

---

## 🖼️ LCD Output – Screenshots

### 🔹 Tinkercad Simulation Output:
![Tinkercad LCD Screenshot](photos/tinkercad_lcd.jpg)

### 🔹 Real Lab Output:
![Lab LCD Screenshot](photos/lab_lcd.jpg)

---

## ▶️ How to Run

1. Connect the **DHT11 sensor** to pin A0, and the **LDR** to pin A1.
2. Connect the **LCD** to the correct digital pins (RS, EN, D4–D7).
3. Upload the `LCD_Sensor_Display.ino` code using the Arduino IDE.
4. Make sure no external libraries are included.
5. Once running:
   - The screen will show temperature (°C) and humidity (%) with a thermometer icon
   - After 2 seconds, it will show the light level (%) with a light bulb icon
   - This alternation repeats continuously

---

## 🔗 Links

- 🎥 **Video Demo:** [YouTube Video](https://www.youtube.com/watch?v=1YcE6VmyJNA)
- 📄 **Project Report (PDF):** [Download Report](file:///C:/Users/Lenovo/Downloads/Arduino_Temperature_Light_Sensor_Documentation_(1).pdf)

---

## ✍️ Created by

**Lina Abufarha**  
Computer Engineering Student – Birzeit University  
May 2025

---
