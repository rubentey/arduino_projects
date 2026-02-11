// -- Nota de pines utilizados. Por favor, no tocar. ---
// OLED I2C     ->  A4 SDA  -> No tocar
//                  A5 SCL  -> No tocar
// IR Emisor    ->  D3      -> No tocar
// IR Receptor  ->  D10
// RF Emisor    ->  D11     -> No tocar
// RF Receptor  ->  D2
// Botón táctil ->  D4
// Deslizante   ->  A0
//                  A1
//                  A2
//                  A3
//-- Nota adicional.  --
// Ha habido problemas con tema RAM, por ello hay textos con la F: display.println(F("ejemplo")); ahorra recursos

#include <Wire.h>               //v7.5.0
#include <Adafruit_SSD1306.h>   //v2.5.16
#include <IRremote.hpp>         //v4.5.0
#include <RCSwitch.h>           //v2.6.4

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

RCSwitch mySwitch = RCSwitch();

// Define el pin para IR
#define irReceivePin 10 // Pin para el receptor IR

// Define el pin para RF 433
#define pinRFenvia 11
#define pinRFrecive 2

// Pines de los botones
const int buttonPins[] = {A0, A1, A2, A3}; // Posiciones del interruptor deslizante
#define boton 4     // Botón pulsador

// Variables globales para el envío IR
int irAddress = 0x02;
int irCommand = 0x34;

void setup() {
    Serial.begin(9600);
    Wire.begin(); // Forzamos el inicio del bus I2C antes que la pantalla
    delay(500);   // Espera generosa para que el voltaje sea estable

    // Intento de inicio
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
        Serial.println(F("Fallo SSD1306"));
    } else {
        Serial.println(F("Pantalla detectada OK"));
    }

// --- MENSAJE DE INICIO ---
    display.clearDisplay();
    display.setTextSize(1);           // Tamaño de fuente normal
    display.setTextColor(SSD1306_WHITE);
    
    display.setCursor(20, 0);          // Esquina superior izquierda
    display.println(F("MULTITOOL RF/IR")); // Nombre del aparato
    
    display.setCursor(30, 15);         // Bajamos a la mitad de la pantalla (32px de alto total)
    display.println(F("Version: v19")); 
    
    display.display();                // Mostrar en pantalla
    delay(2500);                      // Pausa de 2.5 segundos para que de tiempo a leerlo
    // -------------------------

// -- IMPORTANTE: Inicializa los botones uno a uno --
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(boton, INPUT);

    mySwitch.enableTransmit(pinRFenvia);
    mySwitch.enableReceive(0);
    IrReceiver.begin(irReceivePin, ENABLE_LED_FEEDBACK);
    IrSender.begin(3);
    
    Serial.println(F("Todo iniciado"));
}

void loop() {
    display.clearDisplay();
    display.setCursor(0, 0);

    bool menuActive = false; // Controlar si un menú ha sido activado

    for (int i = 0; i < 4; i++) {
        if (digitalRead(buttonPins[i]) == LOW) {
            menuActive = true;

            if (i == 0) {       // Si A0 está activo
                //Serial.println("Menú 1 - Emisor RF");
                display.println(F("Emisor RF"));
                display.setCursor(115, 0);
                display.println("M1");

                if (digitalRead(boton) == LOW) {
                    const char *msg = "Hola RF433"; // Mensaje a enviar
                    display.println("Enviado: \n" + String(msg));
                    mySwitch.send(msg, strlen(msg)); // Enviar el mensaje
                    delay(100);
                } else {
                    display.println(F("Pulsa para test.")); // Mensaje si no se presiona el botón
                }
                
                break; // Salir del bucle si un menú se ha activado
            }

            else if (i == 1) {      // Si A1 está activo
                //Serial.println("Menú 2 - Receptor RF");
                display.println(F("Recive RF - Auto"));
                display.setCursor(115, 0);
                display.println("M2");

                // Guardar el mensaje recibido
                unsigned long receivedValue = mySwitch.getReceivedValue();
                display.println("Recibido: " + String(receivedValue));
                mySwitch.resetAvailable(); // Restablecer el estado de disponibilidad

                break;
            }

            else if (i == 2) {         // Si A2 está activo
                //Serial.println("Menú 3 - Emisor IR");
                display.println(F("Emisor IR"));
                display.setCursor(115, 0);
                display.println("M3");

                if (digitalRead(boton) == LOW) {
                    IrSender.sendNEC(irAddress, irCommand, 0); 
                    irAddress += 0x0101; // Actualizar dirección
                    irCommand += 0x11; // Actualizar comando
                    display.println(F("IR Enviado!"));
                    delay(100); // Evita rebotes
                 
                } else {
                    display.println(F("Pulsa para test.")); // Mensaje si no se presiona el botón
                }
                //digitalWrite(0, HIGH); // Solucionar bug de LED RX

                break;
            }

            else if (i == 3) {      // Si A3 está activo
                //Serial.println("Menú 4 - Receptor IR");
                display.println(F("Recive IR - Auto"));
                display.setCursor(115, 0);
                display.println("M4");

                if (IrReceiver.decode()) { 
                    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
       
                    // Mostramos el valor en HEX directamente desde la estructura nueva
                    unsigned long valorRecibido = IrReceiver.decodedIRData.decodedRawData;
    
                    display.print(F("Protocolo: "));
                    display.println(IrReceiver.decodedIRData.protocol); 
                    display.print(F("HEX: "));
                    display.println(valorRecibido, HEX);
                    Serial.println(valorRecibido, HEX);

                    IrReceiver.resume(); // Muy importante para recibir el siguiente
                    delay(100);
                } else {
                    display.println(F("Esperando IR..."));
                }

                break;
            }
        }
    }

    if (!menuActive) {
        display.setCursor(0, 0);
        display.println(F("Listo..."));
        display.println(F("Pulsa A0-A3"));
    }

    display.display(); // Actualiza la pantalla
    delay(50); // Control de velocidad de actualización
}
