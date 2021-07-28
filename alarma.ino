#include "AlarmTempC.h"
#define UMBRAL 21.00

AlarmTempC alarma;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);    
  alarma.inicializar();
}

void loop() {
    alarma.mostrarTemperatura();
    if(alarma.getTemperatura() > UMBRAL){
      alarma.zumbar();
    }else{
      alarma.noZumbar();
    }
    alarma.getCantDispositivos();
}
