#include <AFMotor.h>
#include <Servo.h>


AF_DCMotor m1(1); 
AF_DCMotor m2(2);
AF_DCMotor m3(3); 
AF_DCMotor m4(4); 

Servo myServo;

#define trigPin A5
#define echoPin A0

long duration;
int distance;


void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(10);
  myServo.write(90); 

 
  m1.setSpeed(200);
  m2.setSpeed(200);
  m3.setSpeed(200);
  m4.setSpeed(200);
}


int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}



void moveForward() {
  m1.run(BACKWARD);
  m2.run(FORWARD);
  m3.run(BACKWARD);
  m4.run(FORWARD);
}

void moveBackward() {
  m1.run(FORWARD);
  m2.run(BACKWARD);
  m3.run(FORWARD);
  m4.run(BACKWARD);
}

void turnLeft() {
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void turnRight() {
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}


void stopMotors() {
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
}

void loop() {

  int center = getDistance();
  Serial.print("Center: ");
  Serial.println(center);

  if (center > 20) {
    moveForward();
  } 
  else {

    stopMotors();
    delay(300);

    moveBackward();
    delay(400);

    stopMotors();
    delay(200);
    myServo.write(150);
    delay(500);
    int left = getDistance();
    Serial.print("Left: ");
    Serial.println(left);

    myServo.write(30);
    delay(500);
    int right = getDistance();
    Serial.print("Right: ");
    Serial.println(right);

    myServo.write(90);
    delay(300);

    if (left > right) {
      turnLeft();
      delay(600);
    } else {
      turnRight();
      delay(600);
    }

    stopMotors();
  }
}
