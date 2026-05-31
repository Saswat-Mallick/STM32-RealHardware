#include <Arduino.h>

volatile bool LedState = false;
volatile bool Interruptflag = false;
volatile unsigned long LastInterrupt = 0;

const int LEDPIN = PC13;
const int MANUAL_TRIGGER = PA2;

void manualISR(){
  unsigned long now = millis();
  if(now-LastInterrupt > 200){
    Interruptflag = true;
    LastInterrupt = now;
  }
}

void setup() {
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, HIGH); // LED OFF to start
  pinMode(MANUAL_TRIGGER, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(MANUAL_TRIGGER), manualISR, FALLING);
}

void loop() {
  if(Interruptflag){
    LedState = !LedState;
    digitalWrite(LEDPIN, !LedState); // active LOW
    Interruptflag = false;
  }
}