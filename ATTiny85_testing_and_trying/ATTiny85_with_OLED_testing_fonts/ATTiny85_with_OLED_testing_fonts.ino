#include <U8x8lib.h>  //For use OLED display
#include <TinyWireM.h>  //For use I2C in ATTiny

U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 2, /* data=*/ 0, /* reset=*/ U8X8_PIN_NONE);

void setup(){
  TinyWireM.begin();
  
  u8x8.begin();
  u8x8.setPowerSave(0);
  //u8x8.setFont(u8x8_font_amstrad_cpc_extended_r); //looks good, small
  //u8x8.setFont(u8x8_font_5x7_r); //looks good, but really small
  //u8x8.setFont(u8x8_font_5x8_r); //looks good
  //u8x8.setFont(u8x8_font_8x13_1x2_r); //Lot of memory, but looks good
  //u8x8.setFont(u8x8_font_8x13B_1x2_r); //Lot of memory, but looks good
  //u8x8.setFont(u8x8_font_7x14_1x2_r); //Lot of memory, but looks good
  //u8x8.setFont(u8x8_font_7x14B_1x2_r); //Lot of memory, but looks good
  //u8x8.setFont(u8x8_font_open_iconic_play_2x2); //icons
  //u8x8.setFont(u8x8_font_open_iconic_weather_2x2); //icons
  //u8x8.setFont(u8x8_font_pxplusibmcgathin_f); //Lot of memory
  //u8x8.setFont(u8x8_font_pxplusibmcgathin_r); //looks good, small
  //u8x8.setFont(u8x8_font_pxplusibmcga_f); //Lot of memory, but looks good
  //u8x8.setFont(u8x8_font_pxplusibmcga_r); //looks good
  //u8x8.setFont(u8x8_font_victoriamedium8_r); //looks good, small
  //u8x8.setFont(u8x8_font_victoriabold8_r); //looks good, small
  //u8x8.setFont(u8x8_font_inb33_3x6_n); //Really lot of memory, very big
  //u8x8.setFont(u8x8_font_pxplustandynewtv_r); //looks good, but small
  //u8x8.setFont(u8x8_font_px437wyse700a_2x2_n); //just numbers and some symbols, good size and looks good
  u8x8.setFont(u8x8_font_px437wyse700b_2x2_n); //just numbers and some symbols, good size and looks good
}

void loop(){
  u8x8.setCursor(0,0);
  u8x8.print("ABCDEFG");
  u8x8.setCursor(0,2);
  u8x8.print("1234567");
  u8x8.setCursor(0,4);
  u8x8.print("+-^´?!;");
}
