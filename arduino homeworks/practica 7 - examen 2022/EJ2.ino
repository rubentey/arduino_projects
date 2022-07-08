#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int potenciometro;
int almacen;
int almacen1;
const int led = 3;

void setup() {
  Serial.begin(9600);

  lcd.begin();
  lcd.backlight();
  lcd.print("Hello world!");

  delay(2000);

  pinMode(led, OUTPUT);

  lcd.clear();
}

void loop()
{
  //***********************LECTURA DEL POTENCIÓMETRO********************************//

  potenciometro = analogRead(A0);

  //************MAPEO PARA ESCRITURA DE HASTA 255 EN EL LED*************************//

  almacen = map(potenciometro, 0, 1023, 0, 255);
  analogWrite(led, almacen);

  //**************MAPEO Y SALIDA POR SERIAL******************************************//

  almacen1 = map(potenciometro, 0, 1023, 0, 100);
  Serial.println(almacen1);

  //************SALIDA POR LCD Y CORRECION CON CEROS*********************************//

  if (almacen1 == 100)
  {
    lcd.setCursor(0, 0);
    lcd.print(almacen1);
  }

  if (almacen1 < 100 && almacen1 > 9)
  {
    lcd.setCursor(0, 0);
    lcd.print("0");
    lcd.setCursor(1, 0);
    lcd.print(almacen1);
  }

  if (almacen1 < 9)
  {
    lcd.setCursor(0, 0);
    lcd.print("00");
    lcd.setCursor(2, 0);
    lcd.print(almacen1);
  }
}
