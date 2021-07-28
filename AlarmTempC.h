#include "Arduino.h"
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 8
#define BUZZER_PIN 7

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);

class AlarmTempC {

    private:

    public:

        void inicializar(){
            sensor.begin();
            sensor.setResolution(0, 12);
        }

        void mostrarTemperatura() {
            
            sensor.requestTemperatures();
            float tempDS18B20 = sensor.getTempCByIndex(0);

            Serial.print("TEMPERATURA: ");
            Serial.print(tempDS18B20);
            Serial.println(" °C---");
            delay(600);
        }

        float getTemperatura() {
            return(sensor.getTempCByIndex(0));
        }

        void zumbar(){
          digitalWrite(BUZZER_PIN, HIGH);
        }

        void noZumbar(){
          digitalWrite(BUZZER_PIN, LOW);
        }

        void getCantDispositivos() {
            Serial.print("Dispositivos: ");
            Serial.println(sensor.getDeviceCount());
        }
};
