// pin central potenciometro -> A0
// pin LED -> D3
// pantalla OLED SSD1306: SCK -> A5  SDA -> A4
// servomotor -> D10

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#include <Servo.h>
Servo myServo;

int LED = 3;
int valueLED = 0;
int valuePercent = 0;
int valueServo = 0;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  //display.clearDisplay();
  pinMode(LED, OUTPUT);
  myServo.attach(10);
}

void loop() {
  display.clearDisplay();

  // read the input on analog pin A0:
  int analogValue = analogRead(A0);
  
  int percentLED = map(analogValue, 0, 1023, 0, 100);
  int valueServo = map(analogValue, 0, 1023, 0, 180);
  int valueLED = map(analogValue, 0, 1023, 0, 255);

  analogWrite(LED, valueLED);
  myServo.write(valueServo); 
  
  /*pantalla*/
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
      display.setCursor(0,0);
      display.println("L1:");
      display.setCursor(20,0);
      display.println(percentLED);
  
    if (percentLED < 10) {
      /*LED*/
      display.setCursor(30,0);
      display.println("%");
      /*Servomotor*/
      display.setCursor(40,0);
      display.println("S1:");
      display.setCursor(60,0);
      display.println(valueServo);
    }else if (percentLED < 100){
      /*LED*/
      display.setCursor(35,0);
      display.println("%");
      /*Servomotor*/
      display.setCursor(45,0);
      display.println("S1:");
      display.setCursor(65,0);
      display.println(valueServo);
    }else{
      /*LED*/
      display.setCursor(40,0);
      display.println("%");
      /*Servomotor*/
      display.setCursor(50,0);
      display.println("S1:");
      display.setCursor(70,0);
      display.println(valueServo);
    }

  display.display();
  delay(15);
}
