// pin central potenciometro -> A0
// pin LED -> D3
// pantalla OLED SSD1306 - SCK -> A5  SDA -> A4
// servomotor -> D10

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#include <Servo.h>
Servo myServo;

int LED = 3;
int valueLED;
int valueServo;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();

  pinMode(LED, OUTPUT);

  myServo.attach(10);
}

void loop() {
  display.clearDisplay();

  int analogValue = analogRead(A0);
  int percent = map(analogValue, 0, 1023, 0, 100);
  int valueServo = map(analogValue, 0, 1023, 0, 180);
  int valueLED = map(analogValue, 0, 1023, 0, 255);

  myServo.write(valueServo);
  analogWrite(LED, valueLED);
  
  /*pantalla*/
  display.setCursor(0,0);
  display.print("Potenciometro: ");
  display.println(analogValue);
  
  display.print("LED: ");
  display.print(percent);
  display.print("%");
  
  display.print(" Servo: ");
  display.print(valueServo);
  display.print("'");
  display.display();
  
  delay(1);
}
