#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

const int ledPin = 13;
const int transmitPin = 12; // D6
const int pulseLength = 430;

void setup() {
  pinMode(ledPin, OUTPUT);
  mySwitch.enableTransmit(transmitPin);
  mySwitch.setPulseLength(pulseLength);
}

void loop() {
  mySwitch.send("1111011110100011101100110"); // off signal
  delay(1000);
}
