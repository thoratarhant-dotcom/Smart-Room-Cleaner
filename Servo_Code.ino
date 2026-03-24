#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(10);  // connect to pin 10
}

void loop() {

  myServo.write(90);   // center
  delay(1000);

  myServo.write(150);  // left
  delay(1000);

  myServo.write(30);   // right
  delay(1000);
}