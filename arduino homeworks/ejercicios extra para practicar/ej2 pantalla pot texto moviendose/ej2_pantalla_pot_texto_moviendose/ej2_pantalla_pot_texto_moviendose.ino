// pin central potenciometro -> A0
// pantalla SSD1306: SCK -> A5   SDA -> A4

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4 //pin reset
#define SCREEN_WIDTH 128 //anchura
#define SCREEN_HEIGHT 64 //altura
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int pos = 0;
int cant = 1;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);
  display.setTextSize(2);

  
  display.clearDisplay();
}

void loop() {
  int analogPot = analogRead(A0);
  int valuePot = map(analogPot, 0, 1023, 0, 1000);

  display.clearDisplay();

  if (valuePot < 990){
    //First line - Static
    display.setCursor(0,0);
    oledDisplayCenter("RECORRIDO");
    display.println();
    display.println();

    //Second line - value
    //display.setCursor(0,15);
    display.println(valuePot);
    
  }else{
    //First line - Static
    display.setCursor(0,0);
    oledDisplayCenter("Genial!");
    display.println();
    
    pos = pos + cant;
    if (pos <= 0 || pos >= 45) {
        cant = -cant;
    }
   
    display.setCursor(pos,30);
    display.println("Eso es!");
  }

  display.display();
  delay(100);
}

void oledDisplayCenter(String text) {
  int16_t x1;
  int16_t y1;
  uint16_t width;
  uint16_t height;

  display.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);
  
  display.clearDisplay(); // clear display
  //display.setCursor((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2); // centrado en horizontal y vertical
  display.setCursor((SCREEN_WIDTH - width) / 2, 0); // horizontal
  //display.setCursor(0, (SCREEN_HEIGHT - height) / 2); // vertical
  display.print(text);
  //display.display();
}
