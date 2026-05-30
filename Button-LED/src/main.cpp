#include <Arduino.h>

void setup() {
  Serial.begin(9600);   // UART1 on A9/A10, 9600 baud
  delay(2000);          // Give monitor time to connect
  Serial.println("STM32 Blue Pill UART is alive!");
}

void loop() {
  static int count = 0;
  Serial.print("Heartbeat #");
  Serial.println(count++);
  delay(1000);
}