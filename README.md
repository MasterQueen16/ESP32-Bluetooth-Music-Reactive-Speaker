# ESP32-Bluetooth-Music-Reactive-Speaker
A smart ESP32-based Bluetooth speaker with music-reactive RGB lighting and LCD display for song metadata. Streams audio via A2DP, outputs to MAX98357A amplifier, and shows track info on an I2C LCD.

# 🎶 ESP32 Bluetooth Music-Reactive Speaker

A smart ESP32-based Bluetooth speaker system that:
- Streams music via Bluetooth A2DP
- Outputs crystal-clear audio via MAX98357A I2S amplifier
- Controls RGB LEDs based on live audio volume
- Displays song title & artist on a 16x2 I2C LCD

## 💡 Features
- ✅ Bluetooth audio (A2DP sink)
- ✅ MAX98357A digital amplifier output
- ✅ RGB music-reactive lighting
- ✅ LCD screen for song metadata (title/artist)
- ✅ ESP32-based and Arduino-compatible

## 🧰 Hardware Used
- ESP32 Dev Module
- MAX98357A I2S DAC Amplifier
- RGB LED (or WS2812B optional)
- 16x2 I2C LCD (0x27)
- 5V Power Supply
- Speaker (4Ω / 8Ω)

## 📸 Demo
![demo](https://photos.app.goo.gl/xZxehVwrzYbN38467)

## 🔌 Wiring Diagram
*(Coming soon: upload schematic/connection image)*

## 📂 Folder Overview
- `firmware/` – Arduino code
- `hardware/` – Schematic and PCB layout
- `images/` – Demo visuals for README

## 📦 Libraries Required
Install via Arduino Library Manager:
- `ESP32-A2DP` by philbowles or h2zero
- `LiquidCrystal_I2C` (johnrickman version)
- `Wire` (built-in)

## 🚀 Getting Started
1. Upload code from `firmware/` to ESP32
2. Power with 5V
3. Connect Bluetooth from phone to "ESP32 BT Speaker"
4. Play music – enjoy sound + lights + metadata!

## 🛠️ Future Improvements
- Add WS2812B support
- Add rotary encoder for volume
- Add 3D printed speaker case
- Add battery support

## 📜 License
MIT License – do whatever you want, just credit.

---

Made with ❤️ by [Kesar and Pranav]
