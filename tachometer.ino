#include <LiquidCrystal.h>

// Initialize the LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// IR sensor and buzzer pins
const int sensorPin = 7;
const int buzzerPin = 8;  // Connect buzzer to pin 8

// Variables for timing and RPM calculation
unsigned long lastPulseTime = 0;
unsigned long currentTime;
float rpm = 0;
bool objectDetected = false;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW); // Ensure buzzer is off initially

  lcd.begin(16, 2); // 16x2 LCD
  lcd.print("Tachometer");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = digitalRead(sensorPin);

  if (sensorValue == LOW && !objectDetected) {
    objectDetected = true;

    currentTime = millis();
    unsigned long timeDiff = currentTime - lastPulseTime;

    if (timeDiff > 0) {
      rpm = (1000.0 / timeDiff) * 60.0;
      lastPulseTime = currentTime;
    }

    displayRPM(rpm);
    checkBuzzer(rpm);
  }

  if (sensorValue == HIGH) {
    objectDetected = false;
  }
}

void displayRPM(float value) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RPM:");
  lcd.setCursor(0, 1);
  lcd.print(value, 2); // show 2 decimal places
}

void checkBuzzer(float rpmVal) {
  if (rpmVal > 3000) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}
