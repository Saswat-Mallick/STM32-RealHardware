#include <Arduino.h>

#define BUZZER_PIN PA0

void beep(int duration) {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(duration);
  digitalWrite(BUZZER_PIN, LOW);
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Startup jingle
  beep(100); delay(50);
  beep(100); delay(50);
  beep(100); delay(50);
  beep(500); delay(1000);

  // Alarm pattern
  for(int i = 0; i < 5; i++) {
    beep(50); delay(50);
  }
  delay(1000);

  // Heartbeat
  for(int i = 0; i < 3; i++) {
    beep(100); delay(100);
    beep(200); delay(500);
  }
  delay(2000);
}