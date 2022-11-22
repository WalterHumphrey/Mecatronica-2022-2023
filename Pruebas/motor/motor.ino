#include <AFMotor.h>
//#define x A0
//#define y A1
#define Speed 180

AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

const int buttonPin = 2;
const int buttonPin2 = 3;
const int buzzer = 4;

int buttonState = 0;
int buttonState2 = 0;

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  //int X = analogRead(x);
  //int Y = analogRead(y);

  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  //Serial.print(X);
  //Serial.print("\t");
  //Serial.println(Y);

  //if (X >= 800) {
  if (buttonState == LOW){
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    Serial.println("Atras");
    digitalWrite(buzzer, HIGH);
    Serial.print(digitalRead(buzzer));
  //} else if (X <= 200) {
  } else if (buttonState2 == LOW) {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    Serial.println("Adelante");
  /*} else if (Y >= 800) {
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
  } else if (Y <= 200) {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);*/
  } else {
    Serial.println("Stop");
    digitalWrite(buzzer, LOW);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
}