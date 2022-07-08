#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)

// Display OLED specs
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
int hexAddress = 0x3C; //Hex address OLED

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Text lines
String line1 = "OLED SSD1306:"; // Static
char text[] = "Test 2nd line scroll!"; // Scroll
String line3 = "The 3rd line too!"; // Scroll

// Text specs
int speedText = 2;
int textSize = 2;
int scrollCursorMin = 0;
int scrollCursor = 0;


void setup() 
{
  //Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, hexAddress);
  display.setTextWrap(false);
  scrollCursor = display.width();
  //display.clearDisplay();
}


void loop() 
{
  //char text[] = "The quick brown fox jumped over the lazy dogs back";
  scrollText(text);
  //First line - Static (if here, it blinks)
  //display.setCursor(0,0);
  //display.println(line1);
}


void scrollText(char message[]) {
  scrollCursorMin = -12 * strlen(message); //12 = 6 pixels/character * text size 2
  display.clearDisplay();
  display.setTextColor(WHITE);
  
  //First line - Static
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println(line1);
  //display.print(scrollCursor);
  
  //Second line - Scroll
  display.setTextSize(textSize);
  display.setCursor(scrollCursor,15);
  display.print(message);
  
  //Third line - Scroll too
  display.setCursor(scrollCursor,35);
  display.println(line3);
  
  display.display();
  scrollCursor = scrollCursor - speedText; // scroll speed
  if (scrollCursor < scrollCursorMin) scrollCursor = display.width();
}
