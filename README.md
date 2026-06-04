# RFID-Based Smart Attendance System

## Overview

The RFID-Based Smart Attendance System is an IoT project that automates attendance tracking using RFID technology. The system reads RFID card data through an RC522 RFID reader connected to an ESP32 microcontroller and automatically updates attendance records in Google Sheets using Google Apps Script.

This eliminates manual attendance marking, reduces human errors, and prevents proxy attendance.

---

## Features

* RFID card-based attendance marking
* Real-time attendance updates
* Automatic Google Sheets integration
* Wi-Fi-enabled attendance logging
* Fast and contactless operation
* Low-cost and easy-to-deploy solution

---

## Components Used

| Component                | Quantity    |
| ------------------------ | ----------- |
| ESP32 Development Board  | 1           |
| RC522 RFID Reader Module | 1           |
| RFID Card/Tag            | 1 or more   |
| Breadboard               | 1           |
| Jumper Wires             | As required |
| LED (Optional)           | 1           |
| Buzzer (Optional)        | 1           |

---

## System Architecture

RFID Card → RC522 Reader → ESP32 → Wi-Fi → Google Apps Script → Google Sheets

---

## Pin Connections

| RC522 | ESP32   |
| ----- | ------- |
| 3.3V  | 3.3V    |
| GND   | GND     |
| SDA   | GPIO 5  |
| SCK   | GPIO 18 |
| MOSI  | GPIO 23 |
| MISO  | GPIO 19 |
| RST   | GPIO 4  |

---

## Working Principle

1. The user scans an RFID card.
2. ESP32 reads the RFID UID.
3. The UID is verified against registered users.
4. Attendance data is sent to Google Apps Script through Wi-Fi.
5. Google Apps Script stores the attendance record in Google Sheets.
6. Attendance can be monitored in real time.

---

## Software Used

* Arduino IDE
* ESP32 Board Package
* MFRC522 Library
* Google Apps Script
* Google Sheets

---

## Folder Structure

```text
RFID-Attendance-System/
│
├── Arduino_Code/
│   └── RFID_Attendance.ino
│
├── Google_Script/
│   └── Code.gs
│
├── Circuit_Diagram/
│   └── circuit.jpg
│
├── Images/
│   └── setup.jpg
│
├── Documentation/
│   └── Project_Report.pdf
│
└── README.md
```

## Applications

* Educational Institutions
* Corporate Offices
* Hospitals
* Conferences and Events
* Employee Attendance Management

---

## Future Enhancements

* Multiple User Registration
* Mobile App Integration
* Cloud Database Storage
* Face Recognition Integration
* Attendance Analytics Dashboard

---

## Author

**Jawahar Bharathi C**

Electronics and Communication Engineering

VIT AP

---

## License

This project is intended for educational and learning purposes.
