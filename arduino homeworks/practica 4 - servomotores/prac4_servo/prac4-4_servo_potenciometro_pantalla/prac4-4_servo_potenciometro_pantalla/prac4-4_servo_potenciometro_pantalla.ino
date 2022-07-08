// pin central potenciometro posicion servo -> A0
// pin central potenciometro iluminación conectado a pantalla -> V0
// pin servomotor -> D9 (progresivo ancho pulso)
// pantalla LCD 16x2 -> pin arduino:
//   VSS -> GND
//   VDD -> 5V
//   V0 -> potenciometro iluminación
//   RS -> D12
//   RW -> GND
//   E -> D11
//   D0
//   D1
//   D2
//   D3
//   D4/DB4 -> D5
//   D5/DB5 -> D4
//   D6/DB6 -> D3
//   D7/DB7 -> D2
//   A -> 5V van a resistencia 220 o 390, y salida resistencia se conecta aquí 
//   k -> GND

#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo miServo;
int pot_pin = 0;
int servo_pin = 9;
int val;
int val2;

void setup() {
  lcd.begin(16, 2);
  miServo.attach(servo_pin);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Posicion");

  val = analogRead(pot_pin);
  val2 = map (val, 0, 1023, 0, 179);
  miServo.write(val2);
  delay(15);

  if (val2 < 100){
    lcd.setCursor(0, 1);
    lcd.write("0");
    lcd.setCursor(1, 1);
    lcd.print(val2);
  }else{
    lcd.setCursor(0, 1);
    lcd.print(val2);
  }
  
}
