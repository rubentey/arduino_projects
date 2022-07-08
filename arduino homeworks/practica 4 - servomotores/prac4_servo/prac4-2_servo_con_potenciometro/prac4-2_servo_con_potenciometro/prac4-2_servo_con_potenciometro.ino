// servomotor -> D9 (progresivo ancho pulso)

#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  int adc = analogRead(A0);
  int angulo = map(adc, 0, 1023, 0, 180);
  myservo.write(angulo);
  Serial.print("Angulo: ");
  Serial.println(angulo);
  delay(10);
}
