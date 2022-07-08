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
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.clearDisplay();

  pinMode(LED, OUTPUT);

  myServo.attach(10);
}

void loop() {
  display.clearDisplay();

  int analogValue = analogRead(A0);
  int percent = map(analogValue, 0, 1023, 0, 100);

  if (percent < 50) {
      myServo.write(0);
          for (int valueLED = 0; valueLED < 255; valueLED++){
          analogWrite(LED, valueLED);
          delay(10);
          }
  }else{
      analogWrite(LED, 0);
          for (int valueServo = 0; valueServo < 255; valueServo++){
          myServo.write(valueServo);
          delay(10);
          }
  }
  
  /*pantalla*/
  display.setCursor(0,0);
  display.print("Pot: ");
  display.print(percent);
  display.println("%");
  display.display();
  
  delay(1);
}
