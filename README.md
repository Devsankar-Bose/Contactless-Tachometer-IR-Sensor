# 🚀 Contactless Tachometer using IR Sensor

A contactless tachometer project built using an **IR sensor** and **Arduino**, with real-time RPM displayed on a **16x2 LCD** via the LiquidCrystal library and a buzzer alarm for high RPM.

## ⚙️ Components Used

- Arduino Uno
- IR Sensor Module
- 16x2 LCD Display
- Potentiometer (for LCD contrast)
- Buzzer
- Breadboard and Jumper Wires
- Small DC Motor or Fan (for testing)
- Reflective Tape (or white paper patch)

## 🔌 Working Principle

The IR sensor detects a reflective surface once per rotation. Arduino measures the time between detections, calculates RPM, and displays it on the LCD. If RPM exceeds 3000, the buzzer sounds an alert.

## 🧾 Files Included

- `tachometer.ino` – Arduino code with LCD and buzzer
- `circuit.png` – Circuit diagram
- `README.md` – Project documentation

## 👨‍💻 Team

- [Devsankar Bose]
- [Nistil Rooy]
- [Navaneeth Krishna]
- [Krishnalal]
- [Athul krishna]

> 🏆 Won **3rd Prize** in the Project Expo organized by the EEE Department of Christ College of Engineering, Irinjalakuda 🎉
