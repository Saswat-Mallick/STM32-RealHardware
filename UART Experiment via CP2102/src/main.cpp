#include <Arduino.h>

HardwareSerial mySerial(PA10, PA9); // RX, TX — USART1 explicit

void setup() {
  mySerial.begin(9600);
  delay(500);
  mySerial.println("Hello from Blue Pill!");
}

void loop() {
  mySerial.println("Hello from Blue Pill!");
  delay(1000);
}