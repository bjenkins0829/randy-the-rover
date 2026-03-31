#include "Arduino.h"

long microsecondsToInches(long microseconds);
long getDistance();
void tooClose();
void setupEyes();
void setupWheel();

int trigPin = 7;
int echoPin = 8;
int motor1pin1 = 2;
int motor1pin2 = 3;
int speedMotor1 = 11;
int motor2pin1 = 4;
int motor2pin2 = 5;
int speedMotor2 = 10;

void setup() {
  Serial.begin(9600);
  setupEyes();
  setupWheel();
}

void loop() {
  // NOAH G-MONEY WAS HERE
  // long inches = getDistance();

  // Serial.print(inches);
  // Serial.print("in");
  // Serial.println();

  // if (inches <= 7) {
  //   tooClose();
  // }

  analogWrite(speedMotor1, 50);
  analogWrite(speedMotor2, 50);

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  delay(1000);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(1000);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  delay(1000);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(1000);

  delay(100);

}

void tooClose() {
  Serial.println("TOO CLOSE RETARD BACK UP!!!!");
}

void setupWheel() {
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(speedMotor1, OUTPUT);
  pinMode(speedMotor2, OUTPUT);
}

void setupEyes() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration / 74 / 2;
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}
