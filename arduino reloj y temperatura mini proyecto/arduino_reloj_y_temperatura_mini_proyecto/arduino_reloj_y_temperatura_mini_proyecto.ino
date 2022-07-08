// DS3231:    VCC -> 5V    GND -> GND    SDA -> A4    SCL -> A5
// sensor temperatura / humedad:   DATA -> A0
// pantalla OLED SSD1306:  SCK -> A5   SDA -> A4

#include <Wire.h>
#include "RTClib.h"
RTC_DS3231 rtc;

#include "DHT.h"
#define DHTTYPE DHT11
const int DHTpin = A0;
DHT dht(DHTpin, DHTTYPE);

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
 
char daysOfTheWeek[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};




void setup () {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  dht.begin();
  display.setTextColor(WHITE);
}




void loop () {
  display.clearDisplay();
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  //int h = dht.readHumidity();
  //int t = dht.readTemperature();

  if (! rtc.begin()) {
      //Serial.println("Fallo en RTC");
  }
  
  if (rtc.lostPower()) {
      //Serial.println("RTC sin energía, ajustamos el tiempo!");
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }




  DateTime now = rtc.now();
      //hora
  display.setTextSize(2);
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




      //dia y temperatura
   display.setTextSize(1);
   if (now.second() >= 0 && now.second() <= 4 || now.second() >= 10 && now.second() <= 14 || now.second() >= 20 && now.second() <= 24 || now.second() >= 30 && now.second() <= 34 || now.second() >= 40 && now.second() <= 44 || now.second() >= 50 && now.second() <= 54){      
      //fecha
      display.setCursor(20,25);
      display.print(daysOfTheWeek[now.dayOfTheWeek()]);
      display.print(" ");
      display.print(now.day(), DEC);
      display.print('/');
      display.print(now.month(), DEC);
      display.print('/');
      display.print(now.year(), DEC);
   }else{
      //temperatura humedad
      display.setCursor(0,25);
          if (isnan(h) || isnan(t)) {
              display.println("Fallo en lectura DHT!");
          }else{
            display.print("H: ");
            display.print(h);
            display.print("% ");
            display.print(" T: ");
            display.print(t);
            display.print("'C");
          }

   }



    display.println();
    display.display();

delay(100);
}
