#include "Arduino.h"

long getDistance();
void setupEyes();
void setupWheels();
void goForward();
void goBackward();
void stop();

// eyes
int trigPin = 12;
int echoPin = 13;

// left wheel
int motor1pin1 = 9;
int motor1pin2 = 8;
int speedMotor1 = 10;

// right wheel
int motor2pin1 = 4;
int motor2pin2 = 5;
int speedMotor2 = 3;

// motor direction
bool goingForward = false;
bool goingBackward = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  setupEyes();
  setupWheels();
}

void loop() {
  Serial.println("beginning loop");

  if (getDistance() <= 7) {
    goBackward();
  } else {
    goForward();
  }

  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);

  delay(100);
}

/**
 * Make both wheels go forward
 */
void goForward() {
  if (goingBackward) {
    stop();
    delay(1000);
  }

  goingForward = true;
  goingBackward = false;

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

/**
 * Make both wheels go backward
 */
void goBackward() {
  if (goingForward) {
    stop();
    delay(1000);
  }

  goingForward = false;
  goingBackward = true;

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

/**
 * Stop both wheels
 */
void stop() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}

/**
 * Setup the wheel pin modes
 */
void setupWheels() {
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(speedMotor1, OUTPUT);
  pinMode(speedMotor2, OUTPUT);

  analogWrite(speedMotor1, 120);
  analogWrite(speedMotor2, 120);
}

/**
 * Setup the eyes pin modes
 */
void setupEyes() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

/**
 * Get the distance of an object in front of the eyes (in inches)
 * return distance in inches
 */
long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration / 74 / 2;
}