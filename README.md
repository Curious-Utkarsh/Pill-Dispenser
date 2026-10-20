# Spencer Pro 370 — Automatic Pill Dispenser (ESP32)

[![ESP32](https://img.shields.io/badge/MCU-ESP32-E7352C)](https://www.espressif.com/)
[![Stepper](https://img.shields.io/badge/actuation-NEMA%2017%20%2B%20servo-555)](#key-features)

A Wi-Fi-connected pill dispenser that releases medication either for a symptom the user selects or on a schedule. Six cylinders are indexed by a NEMA 17 stepper and a servo releases the dose; a TFT screen drives the interface. Built solo, 2023–2024.

## Demo

[![Automatic pill dispenser — Spencer Pro 370](https://img.youtube.com/vi/GGR1IZcwPq0/hqdefault.jpg)](https://youtu.be/GGR1IZcwPq0)

## Key features

- **Selection mode** (by symptom) and **timer mode** (scheduled doses using NTP time)
- **Refill mode** with homing of the cylinder carousel
- SD-card storage and TFT graphics; Wi-Fi setup through WiFiManager
- 3D-printed mechanism

## Stack

ESP32 · NEMA 17 + AccelStepper · servo · TFT_eSPI · SD · NTPClient · WiFiManager

## Files

`Pill_Dispenser_FullCode.ino` (latest) with one tab per mode: `selectionMode_`, `timerMode`, `refillMode`, `stepDispense`, `homePosn`, `sdCard`, …

## Related

[RFID canteen payment system](https://github.com/Curious-Utkarsh/rfid-canteen-payment-system) · [Q'Less Pro kiosk](https://github.com/Curious-Utkarsh/qless-pro-ordering-kiosk)

---
[Kumar Utkarsh](https://github.com/Curious-Utkarsh) · [LinkedIn](https://www.linkedin.com/in/kumar-utkarsh-124aab227/) · [Portfolio of builds](https://www.mechamindlabs.com/projects)
