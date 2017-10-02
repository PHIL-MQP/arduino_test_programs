#include <TimerOne.h>

const unsigned int led = 13;
const unsigned int us = 3;

void setup() {
  Serial.begin(9600);
  pinMode(us, OUTPUT);
  pinMode(led, OUTPUT);
}

uint8_t c = 0;
void loop() {
  analogWrite(us, ++c);
  delay(20);
}
