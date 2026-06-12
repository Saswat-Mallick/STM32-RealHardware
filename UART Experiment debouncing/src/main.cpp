#include <Arduino.h>

HardwareSerial mySerial(PA10, PA9);

const int BUTTON_PIN = PA3;
const int LED_PIN = PA2;

bool ledState = false;
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long DEBOUNCE_DELAY = 50; // ms

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  mySerial.begin(9600);
  mySerial.println("Debounce test ready!");
}

void loop() {
  bool reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (reading == LOW) { // button pressed (active low)
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
      mySerial.println(ledState ? "LED ON" : "LED OFF");
      while(digitalRead(BUTTON_PIN) == LOW); // wait for release
    }
  }

  lastButtonState = reading;
}