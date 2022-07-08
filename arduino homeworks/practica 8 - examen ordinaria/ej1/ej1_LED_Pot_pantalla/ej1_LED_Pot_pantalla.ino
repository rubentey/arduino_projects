// pin central potenciometro -> A0
// pin LED -> D3
// pantalla OLED SSD1306 - SCK -> A5  SDA -> A4

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int LED = 3;
int valueLED;
int valuePercent;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  pinMode(LED, OUTPUT);
}

void loop() {
  display.clearDisplay();

  // read the input on analog pin A0:
  int analogValue = analogRead(A0);
  int percent = map(analogValue, 0, 1023, 0, 100);
  int valueLED = map(analogValue, 0, 1023, 0, 255);

  analogWrite(LED, valueLED);
  
  /*pantalla*/
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("LED 1:");
  display.setCursor(40,0);
  display.println(percent);
  
    if (percent < 10){
      display.setCursor(50,0);
    }else if (percent < 100){
      display.setCursor(55,0);
    }else{
      display.setCursor(60,0);
    }
    
  display.println("%");
  display.display();
  delay(1);
}
