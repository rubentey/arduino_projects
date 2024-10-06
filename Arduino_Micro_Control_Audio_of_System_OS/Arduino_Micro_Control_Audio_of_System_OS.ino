//Esta nueva version solo incluye encender el LED
#include <HID-Project.h> // Biblioteca para utilizar las funciones HID

const int potPin = A7;   // Pin del potenciómetro
int lastVolumeLevel = 0; // Almacena el último nivel de volumen leído
int led = 3; //led rojo en pcb, con pwm

void setup() {
  //Serial.begin(9600);                               // Inicializar el puerto serial y el teclado HID
  Consumer.begin();                                   // Empezar la comunicación HID
  pinMode(led, OUTPUT);                               // Así tener un LED indicando aprox el nivel de audio actual
}

void loop() {
  int potValue = analogRead(potPin);                  // Leer el valor del potenciómetro
  int volumeLevel = map(potValue, 0, 1023, 0, 150);   // Convertir el valor a un rango de 0 a 100. Sería poner 100, pero es muy justo de recorrido

  if (abs(volumeLevel - lastVolumeLevel) > 2) {       // Establecer un umbral para evitar cambios muy pequeños
    if (volumeLevel > lastVolumeLevel) {              // Subir el volumen si el nivel actual es mayor que el anterior
      Consumer.write(MEDIA_VOLUME_UP);
    }
    else if (volumeLevel < lastVolumeLevel) {         // Bajar el volumen si el nivel actual es menor que el anterior
      Consumer.write(MEDIA_VOLUME_DOWN);
    }
    lastVolumeLevel = volumeLevel;                    // Actualizar el nivel de volumen anterior
  }

  int ledLevel = map(potValue, 0, 1023, 0, 255);      // Se podría poner que ledLevel, sea = potValue, pero el LED se encendería y apagaría 4 veces en el recorrido
  analogWrite(led, ledLevel);
  //Serial.println(potValue);
  // Esperar un momento antes de volver a leer
  //delay(50);                                        // Aprox 50ms va bien, pero al mover rápido el pot, te falta. Máx pondría 10 a 20ms, arregla bastante
}
