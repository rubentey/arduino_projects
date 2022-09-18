// DS3231:  VCC -> 5V  GND -> GND  SDA -> A4  SCL -> A5
// DHT:  DATA -> A0
// OLED SSD1306:  SCK -> A5  SDA -> A4

#include <Wire.h>
#include <RTClib.h>
RTC_DS3231 rtc;

#include <DHT.h>
#define DHTTYPE DHT11
const int DHTpin = A0;
DHT dht(DHTpin, DHTTYPE);

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

char daysOfTheWeek[7][12] = {"Dom", "Lun", "Mar", "Mie", "Jue", "Vie", "Sab"};


void setup () {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  dht.begin();
  display.setTextColor(WHITE);
  display.setTextSize(2);
}

void loop () {
   display.clearDisplay();
   float h = dht.readHumidity();
   float t = dht.readTemperature();

   if (! rtc.begin()) {
   }

   if (rtc.lostPower()) {
       rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
   }
 
   DateTime now = rtc.now();
       //hora
   if (now.hour() < 10){
       display.setCursor(25,0);
   }else{
       display.setCursor(15,0);
   }
       display.print(now.hour(), DEC);
       display.print(':');
       display.print(now.minute(), DEC);
       display.print(':');
       display.print(now.second(), DEC);

       //dia y temperatura
       if (now.second() >= 0 && now.second() <= 4 || now.second() >= 10 && now.second() <= 14 || now.second() >= 20 && now.second() <= 24 || now.second() >= 30 && now.second() <= 34 || now.second() >= 40 && now.second() <= 44 || now.second() >= 50 && now.second() <= 54){
         //fecha
          display.setCursor(0,17);
          display.print(daysOfTheWeek[now.dayOfTheWeek()]);
          display.print(" ");
          display.print(now.day(), DEC);
          display.print('/');
          display.print(now.month(), DEC);
          display.print('/');
          display.print(now.year(), DEC);
       }else{
        //temperatura humedad
          display.setCursor(0,17);
          if (isnan(h) || isnan(t)) {
              display.println("Fallo DHT!");
          }else{
            display.print(h, 0);
            display.print("% ");
            display.print(t, 1);
            display.print("'C");
          }
   }
display.println();
display.display();

delay(100);
}
