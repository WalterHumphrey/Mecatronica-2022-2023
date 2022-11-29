#include <AFMotor.h>
#define Speed 180
#include<Servo.h>

Servo Myservo;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

const int buttonPinUP = A0;
const int buttonPinDOWN = A1;
const int buttonPinLEFT = A2;
const int buttonPinRIGHT = A3;
const int buttonPinGRP = A4;
const int buzzer = A5; 

int buttonStateUP = 0;
int buttonStateDOWN = 0;
int buttonStateLEFT = 0;
int buttonStateRIGHT = 0;
int buttonStateGRP = 0;

bool encendido = false;

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  pinMode(buttonPinUP, INPUT_PULLUP);
  pinMode(buttonPinDOWN, INPUT_PULLUP);
  pinMode(buttonPinLEFT, INPUT_PULLUP);
  pinMode(buttonPinRIGHT, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(buttonPinGRP, INPUT_PULLUP);
  Myservo.attach(9);
}

void loop() {
  buttonStateUP = digitalRead(buttonPinUP);
  buttonStateDOWN = digitalRead(buttonPinDOWN);
  buttonStateLEFT = digitalRead(buttonPinLEFT);
  buttonStateRIGHT = digitalRead(buttonPinRIGHT);
  buttonStateGRP = digitalRead(buttonPinGRP);
  
  if (buttonStateUP == LOW){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    Serial.println("Adelante");
  } else if (buttonStateDOWN == LOW) {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    Serial.println("Atras");
    digitalWrite(buzzer, HIGH);
  } else if (buttonStateLEFT == LOW) {
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    Serial.println("Izquierda");
  } else if (buttonStateRIGHT == LOW) {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    Serial.println("Derecha");
  } else {
    Serial.println("Stop");
    digitalWrite(buzzer, LOW);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
  if (buttonStateGRP == LOW) {
    encendido = !encendido;
    if (encendido == true) {
      Myservo.write(180);
      Serial.println(encendido);
    } else if (encendido == false){
      Myservo.write(90);
      Serial.println(encendido);
    }
    delay(300);         //rebote al presionar
    while(buttonStateGRP == HIGH); //esperar a soltar boton 
    delay(100);
  }
}
