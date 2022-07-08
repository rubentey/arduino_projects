// luz LED alarma enciende en X minuto -> D4
// luz LED temporizador enciende en X segundo tras alarma -> D9
// DS3231:
//   VCC -> 5V
//   GND -> GND
//   SDA -> A4
//   SCL -> A5

#include <Wire.h>
#include "RTClib.h"
RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sábado"};

int LEDalarm = 4;
int LEDtimer = 9;

 
void setup () {
  Serial.begin(9600);
  delay(3000); // wait for console opening

int LEDalarm = 0;
int LEDtimer = 0;
 
  if (! rtc.begin()) {
    Serial.println("No se encuentra el RTC");
    while (1);
  }
  
  if (rtc.lostPower()) { // Si quitas la pila, enciendes el arduino, y pones de nuevo la pila, este asignará la fecha y hora de la ultima compilación del código, al módulo
    //Serial.println("RTC lost power, lets set the time!");
    Serial.println("RTC sin energía, Reemplaza la pila, y vuelve a conectar el Arduino!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}
 
void loop () {
    DateTime now = rtc.now();

// fecha actual
    Serial.print("Fecha: ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print("Hora: ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    //Serial.println("El LED enciende a las XX:08:XX");
      //Setting alarm/timer at every 2:32:53pm
      //if (now.hour() == 14 && now.minute() == 32 && now.second() == 53){
      if (now.minute() == 8){
          //digitalWrite(LEDalarm, HIGH); Con este se enciende muy poco el LED
          Serial.println("LED alarma pin 4: 08m");
          analogWrite(LEDalarm, 255);
            if (now.second() > 29){
              Serial.println("LED temporizador pin 9: 30s despues");
            analogWrite(LEDtimer, 255);
            }
      }else{
          analogWrite(LEDalarm, 0);
          analogWrite(LEDtimer, 0);
        }

    Serial.println();
    delay(1000);
}
