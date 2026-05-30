#include <Arduino.h>

#define LED_PIN PC13  // Built-in LED on Blue Pill is PC13

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED OFF (PC13 is active low!)
  delay(500);
  digitalWrite(LED_PIN, LOW);   // LED ON
  delay(500);
}