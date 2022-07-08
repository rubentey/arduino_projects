// pin central potenciometro servo -> A0
// pin central potenciometro LED -> A1
// pin del servo -> D9
// pin del LED -> D3

#include <Servo.h>
Servo myServo;

const int LED = 3;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
  int LED = 0;
}

void loop() {
  int analogServo = analogRead(A0);
  int valueServo = map(analogServo, 0, 1023, 0, 180);
  
  int analogLED = analogRead(A1);
  int percentLED = map(analogLED, 0, 1023, 100, 0);
  int valueLED = map(analogLED, 0, 1023, 255, 0);

  myServo.write(valueServo);
  analogWrite(LED, valueLED);

  Serial.print("Servo: ");
  Serial.print(valueServo);

  Serial.print(", LED: ");
  Serial.print(percentLED);
  Serial.print(" % ");
  Serial.println();
  
  delay(100);
}
