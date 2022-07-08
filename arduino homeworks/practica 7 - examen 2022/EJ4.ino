#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

int potenciometro;
int almacen;
int almacen1;
int almacen2;
int almacen3;
int almacen4;

const int led = 3;

void setup() {
  Serial.begin(9600);

  lcd.begin();
  lcd.backlight();
  lcd.print("Hello world!");

  delay(2000);
  lcd.clear();

  pinMode(led, OUTPUT);

  servo.attach(9);
}

void loop()
{
  //***********************LECTURA DEL POTENCIÓMETRO********************************//

  potenciometro = analogRead(A0);

  //**************MAPEO Y SALIDA POR SERIAL*****************************************//

  almacen = map(potenciometro, 0, 1023, 0, 100);
  Serial.println(almacen);

  //*******LINEA 1 POTENCIOMETRO Y CORRECION DE CEROS********************************//

  if (almacen == 100)
  {
    lcd.setCursor(0, 0);
    lcd.print("POT");
    lcd.setCursor(4, 0);
    lcd.print(almacen);
    lcd.setCursor(7, 0);
    lcd.print("%");
  }

  if (almacen < 100 && almacen > 9)
  {
    lcd.setCursor(0, 0);
    lcd.print("POT");
    lcd.setCursor(4, 0);
    lcd.print("0");
    lcd.setCursor(5, 0);
    lcd.print(almacen);
    lcd.setCursor(7, 0);
    lcd.print("%");
  }

  if (almacen < 9)
  {
    lcd.setCursor(0, 0);
    lcd.print("POT");
    lcd.setCursor(4, 0);
    lcd.print("00");
    lcd.setCursor(6, 0);
    lcd.print(almacen);
    lcd.setCursor(7, 0);
    lcd.print("%");
  }

  //********PRIMERA MITAD DE VUELTA Y MAPEO PARA ESCRITURA DE HASTA 255 EN EL LED*****//

  if (almacen >= 0 && almacen < 51)
  {
    almacen1 = map(potenciometro, 0, 512, 0, 255);
    analogWrite(led, almacen1);
  }

  //******SEGUNDA MITAD DE VUELTA Y MAPEO PARA ESCRITURA DE HASTA 180 EN EL SERVO*****//

  if (almacen > 50 && almacen < 101)
  {
    almacen2 = map(potenciometro, 513, 1023, 0, 180);
    analogWrite(led, 0);
    servo.write(almacen2);

    lcd.setCursor(0, 1);
    lcd.print("L");
    lcd.setCursor(2, 1);
    lcd.print("000");
    lcd.setCursor(6, 1);
    lcd.print("%");
  }

  //*****SEGUNDA LINEA - PORCENTAJE VALORES DEL LED - SEGUNDA MITAD DE LA VUELTA*******//

  almacen3 = map(potenciometro, 0, 512, 0, 100);

  if (almacen3 == 100)
  {
    lcd.setCursor(0, 1);
    lcd.print("L");
    lcd.setCursor(2, 1);
    lcd.print(almacen3);
    lcd.setCursor(6, 1);
    lcd.print("%");
  }

  if (almacen3 < 100 && almacen3 > 9)
  {
    lcd.setCursor(0, 1);
    lcd.print("L");
    lcd.setCursor(2, 1);
    lcd.print("0");
    lcd.setCursor(3, 1);
    lcd.print(almacen3);
    lcd.setCursor(6, 1);
    lcd.print("%");
  }

  if (almacen3 < 10 && almacen3 >= 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("L");
    lcd.setCursor(2, 1);
    lcd.print("00");
    lcd.setCursor(4, 1);
    lcd.print(almacen3);
    lcd.setCursor(6, 1);
    lcd.print("%");
  }

  //*******SEGUNDA LINEA - VALORES DEL SERVOMOTOR - SEGUNDA MITAD DE LA VUELTA*******//

  almacen4 = map(potenciometro, 513, 1023, 0, 180);

  if (almacen4 > 99 && almacen4 < 181)
  {
    lcd.setCursor(10, 1);
    lcd.print("S");
    lcd.setCursor(12, 1);
    lcd.print(almacen4);
  }
  if (almacen4 > 9 && almacen4 < 100)
  {
    lcd.setCursor(10, 1);
    lcd.print("S");
    lcd.setCursor(12, 1);
    lcd.print("0");
    lcd.setCursor(13, 1);
    lcd.print(almacen4);
  }

  if (almacen4 < 10 && almacen4 >= 0)
  {
    lcd.setCursor(10, 1);
    lcd.print("S");
    lcd.setCursor(12, 1);
    lcd.print("00");
    lcd.setCursor(14, 1);
    lcd.print(almacen4);
  }
  delay(20);
}
