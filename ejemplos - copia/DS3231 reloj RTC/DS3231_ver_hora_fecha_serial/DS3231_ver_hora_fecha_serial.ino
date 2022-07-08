// DS3231:
//   VCC -> 5V
//   GND -> GND
//   SDA -> A4
//   SCL -> A5

#include <Wire.h>
#include "RTClib.h"
RTC_DS3231 rtc;
 
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
 
void setup () {
  Serial.begin(9600);
  delay(3000); // wait for console opening
 
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  if (rtc.lostPower()) { // Si quitas la pila, y enciendes el arduino, este pondrá automaticamente la hora al modulo ** ojo, la fecha y hora de la ultima compilación del código **
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}
 
void loop () {
    DateTime now = rtc.now();

// fecha modificada
    // este apartado de datetime -> "añade cantidad dias  /  formato 12h o 24h  /  añade minutos  / añade segundos"
    DateTime date (now + TimeSpan(7,24,0,0));
    Serial.print("En 1 semana: ");
    Serial.print(date.year(), DEC);
    Serial.print('/');
    Serial.print(date.month(), DEC);
    Serial.print('/');
    Serial.print(date.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[date.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(date.hour(), DEC);
    Serial.print(':');
    Serial.print(date.minute(), DEC);
    Serial.print(':');
    Serial.print(date.second(), DEC);
    Serial.println();

// fecha actual
    Serial.print("Fecha actual: ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
 
    //Serial.print(" since midnight 1/1/1970 = ");
    //Serial.print(now.unixtime());
    //Serial.print("s = ");
    //Serial.print(now.unixtime() / 86400L);
    //Serial.println("d");
 
    Serial.println();
    delay(3000);
}
