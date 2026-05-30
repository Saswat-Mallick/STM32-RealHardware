#include <Arduino.h>

// PWM pins — these map to hardware timer channels on STM32F103
#define RED_PIN   PA0   // TIM2_CH1
#define GREEN_PIN PA6   // TIM3_CH1
#define BLUE_PIN  PA7   // TIM3_CH2

void setColor(int r, int g, int b) {
  analogWrite(RED_PIN,   r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN,  b);
}

void setup() {
  // analogWrite handles pinMode internally on STM32 Arduino framework
  // PWM resolution is 8-bit by default: 0 = off, 255 = full brightness
}

void loop() {
  // --- Solid Colors ---
  setColor(255, 0,   0);    delay(1000);   // Red
  setColor(0,   255, 0);    delay(1000);   // Green
  setColor(0,   0,   255);  delay(1000);   // Blue
  setColor(255, 255, 0);    delay(1000);   // Yellow
  setColor(0,   255, 255);  delay(1000);   // Cyan
  setColor(255, 0,   255);  delay(1000);   // Magenta
  setColor(255, 255, 255);  delay(1000);   // White

  // --- Smooth Red Fade (shows PWM in action) ---
  for (int i = 0; i <= 255; i++) {
    setColor(i, 0, 0);
    delay(8);
  }
  for (int i = 255; i >= 0; i--) {
    setColor(i, 0, 0);
    delay(8);
  }

  // --- Rainbow Cycle ---
  for (int i = 0; i < 256; i++) {
    // HSV-style hue rotation mapped to RGB
    int r = (i < 85)  ? (255 - i * 3)     : (i < 170 ? 0          : (i - 170) * 3);
    int g = (i < 85)  ? 0                  : (i < 170 ? (i-85)*3   : 255 - (i-170)*3);
    int b = (i < 85)  ? i * 3              : (i < 170 ? 255-(i-85)*3 : 0);
    setColor(r, g, b);
    delay(20);
  }
}