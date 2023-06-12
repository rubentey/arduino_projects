#include "max6675.h"
int tcpDO = 1;  //SPI for thermocouple MAX6675 settings
int tcpCS = 3;
int tcpCLK = 4;
MAX6675 tcp(tcpCLK, tcpCS, tcpDO);

#include <U8x8lib.h>  //For use OLED display
#include <TinyWireM.h>  //For use I2C in ATTiny
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 2, /* data=*/ 0,
/* reset=*/ U8X8_PIN_NONE);

void setup() {
  TinyWireM.begin();
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFont(u8x8_font_7x14B_1x2_r);
  delay(500);
  u8x8.setCursor(0,2);
  u8x8.print("   Tech & COT");
  u8x8.setCursor(0,4);
  u8x8.print("  Electronics");
  delay(1500);
  
  u8x8.setCursor(0,2);
  u8x8.print("                      ");
  u8x8.setCursor(0,4);
  u8x8.print("                      ");
  delay(50);
  u8x8.setCursor(0,2);
  u8x8.print("                      ");
  u8x8.setCursor(0,4);
  u8x8.print("                      ");
  delay(50);
  
  u8x8.setCursor(0,2);
  u8x8.print("   Temp with");
  u8x8.setCursor(0,4);
  u8x8.print("    K-Type");
  delay(1500);
  
  u8x8.setCursor(0,2);
  u8x8.print("                      ");
  u8x8.setCursor(0,4);
  u8x8.print("                      ");
  delay(50);
  u8x8.setCursor(0,2);
  u8x8.print("                      ");
  u8x8.setCursor(0,4);
  u8x8.print("                      ");
  delay(50);
}

void loop() {
  u8x8.setCursor(0,0);
  u8x8.print("Cels = ");             // Celsius
  u8x8.print(tcp.readCelsius());
  u8x8.setCursor(0,3);
  u8x8.print("Fahr = ");             // Fahrenheit
  u8x8.print(tcp.readFahrenheit());
  u8x8.setCursor(0,6);
  u8x8.print(" - Tech & COT -");   // Trademark
  delay(500);
}
