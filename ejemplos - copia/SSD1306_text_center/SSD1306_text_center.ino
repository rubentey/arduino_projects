// pin central potenciometro -> A0

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4 //pin reset
#define SCREEN_WIDTH 128 //anchura
#define SCREEN_HEIGHT 64 //altura
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Text lines
char text[] = ""; // Scroll

// Text specs
int speedText = 2;
int textSize = 2;
int scrollCursorMin = 0;
int scrollCursor = 0;


void setup() {
  //Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextWrap(false);
  scrollCursor = display.width();
  display.clearDisplay();
}

void loop() {
  scrollText(text);
  delay(100);
}

void scrollText(char message[]) {
  
  int analogPot = analogRead(A0);
  int valuePot = map(analogPot, 0, 1023, 0, 1000);


  
  scrollCursorMin = -12 * strlen(message); //12 = 6 pixels/character * text size 2
  display.clearDisplay();
  display.setTextColor(WHITE);
  
  //First line - Static
  display.setTextSize(1);
  display.setCursor(0,0);
  //display.print("RECORRIDO: ");
  oledDisplayCenter("RECORRIDO: ");
  
  //Second line - Scroll
  display.setTextSize(textSize);
  display.setCursor(scrollCursor,15);
  display.println(valuePot);
  
  display.display();
  scrollCursor = scrollCursor - speedText; // scroll speed
  if (scrollCursor < scrollCursorMin) scrollCursor = display.width();
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
  //display.setCursor(0, (SCREEN_HEIGHT - height) / 2);
  display.println(text);
  display.display();
}
