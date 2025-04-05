# 🧠 Arduino-Based Simulated Smart Desk Assistant to Improve Study Focus

This project simulates a smart desk assistant using Arduino, built with online simulation tools like **Wokwi** or **Tinkercad**. It uses the **Pomodoro technique** to help students improve focus during study sessions by managing work/break timers using LEDs, a push button, and an optional LCD and buzzer.

---

## 🎯 Features

- ⏱️ **45-minute focus timer** with a green LED indicator
- ☕ **15-minute break timer** with a red LED indicator
- 🔘 Start timer using a push button
- 📢 Optional buzzer tone when session switches
- 📟 Optional LCD display showing countdown timer (for better UX!)
- 🔄 Fully simulated — no physical hardware required

---

## 🛠️ Tools Used

- [Wokwi Arduino Simulator](https://wokwi.com/)
- Arduino Uno
- LEDs (Green, Red)
- Push Button
- Buzzer *(optional)*
- 16x2 LCD with I2C *(optional)*

---

## ⚙️ Circuit Diagram

Here’s the connection overview (simulated in Wokwi):

| Component     | Arduino Pin |
|--------------|-------------|
| Green LED     | D3          |
| Red LED       | D4          |
| Push Button   | D7 (with `INPUT_PULLUP`) |
| Buzzer (opt.) | D8          |
| LCD SDA       | A4          |
| LCD SCL       | A5          |

> Push button one side to **D7**, other side to **GND**.

---

## 💡 How It Works

1. User presses the button to start the 45-minute session.
2. Green LED turns ON during the focus period.
3. After 45 minutes, red LED turns ON for a 15-minute break.
4. Buzzer optionally beeps at each switch.
5. LCD (if added) shows a countdown timer for both sessions.
6. After break, the assistant resets and waits for next cycle.
