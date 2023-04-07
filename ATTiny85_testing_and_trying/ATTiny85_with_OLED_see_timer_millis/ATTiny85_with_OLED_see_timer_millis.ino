#include <U8x8lib.h>  //For use OLED display
#include <TinyWireM.h>  //For use I2C in ATTiny

U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 2, /* data=*/ 0, /* reset=*/ U8X8_PIN_NONE);

uint8_t Second=0;
unsigned long timer=0;

void setup(){

  TinyWireM.begin();

  u8x8.begin();
  u8x8.setPowerSave(0);
}

void loop(){

  if(millis()-timer>1000){
    Second++;
    showOled();

    timer=millis();
    }
}

void showOled(){

  u8x8.setFont(u8x8_font_victoriamedium8_r);

  u8x8.setCursor(0,0);
  u8x8.print("Timer:");

  u8x8.setCursor(1,2);
  u8x8.print(Second);
  u8x8.print(" s    ");
  
}
