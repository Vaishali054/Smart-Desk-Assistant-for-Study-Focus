#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD pins

const int buttonPin = 7;
const int greenLED = 8;
const int redLED = 9;
const int buzzer = 10;

bool sessionRunning = false;
int buttonState;
int lastButtonState = HIGH;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Press to Start");
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && !sessionRunning) {
      sessionRunning = true;
      startFocusSession();
      startBreakSession();
      lcd.clear();
      lcd.print("Session Done!");
      sessionRunning = false;
    }
  }

  lastButtonState = reading;
}

void startFocusSession() {
  lcd.clear();
  lcd.print("Focus Time: 45min");
  digitalWrite(greenLED, HIGH);
  countdown(45); // Real: 45, Demo: 0.3
  digitalWrite(greenLED, LOW);
  buzz();
}

void startBreakSession() {
  lcd.clear();
  lcd.print("Break Time: 15min");
  digitalWrite(redLED, HIGH);
  countdown(15); // Real: 15, Demo: 0.1
  digitalWrite(redLED, LOW);
  buzz();
}

void countdown(int minutes) {
  for (int i = minutes * 60; i > 0; i--) {
    lcd.setCursor(0, 1);
    lcd.print("Time Left: ");
    int min = i / 60;
    int sec = i % 60;
    lcd.print(min);
    lcd.print(":");
    if (sec < 10) lcd.print("0");
    lcd.print(sec);
    delay(1000);  // 1 sec per second
  }
}

void buzz() {
  tone(buzzer, 1000, 500); // Beep sound
  delay(500);
  noTone(buzzer);
}

