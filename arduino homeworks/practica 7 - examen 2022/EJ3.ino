#include <Servo.h>

Servo servo;

int potenciometro;
int almacen;
int almacen1;
int almacen2;
const int led = 3;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);

  servo.attach(9);
}

void loop()
{
  potenciometro = analogRead(A0);
  almacen = map(potenciometro, 0, 1023, 0, 100);
  Serial.println(almacen);

  if (almacen >= 0 && almacen < 51)
  {
    almacen1 = map(potenciometro, 0, 512, 0, 255);
    analogWrite(led, almacen1);
  }

  if (almacen > 50 && almacen < 101)
  {
    almacen2 = map(potenciometro, 513, 1023, 0, 180);
    analogWrite(led, 0);
    servo.write(almacen2);
  }
}
