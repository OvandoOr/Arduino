
#include "Adafruit_VL53L0X.h"
#include <NewPing.h>

/*Aqui se configuran los pines donde debemos conectar el sensor*/
#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200

Adafruit_VL53L0X lox = Adafruit_VL53L0X();
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }
  
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
}


void loop() {
  VL53L0X_RangingMeasurementData_t measure;
    
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
  int uS = sonar.ping_median()/US_ROUNDTRIP_CM;
  Serial.println(uS);

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    int range=measure.RangeMilliMeter;
    Serial.print("Distance (mm): "); Serial.println(range);


    if(range<400 && range>100 || uS<30 && uS>10){
     beep(range/2+200);
     analogWrite(3,305-range);
    }
    else if(range<100 && range>0 || uS<10 && uS>0){
      analogWrite(9, 40);
      analogWrite(3,255-range);
    }
    else{
      analogWrite(9, 0);
      analogWrite(3, 0);
      delay(100);
    }
     
  }
  else if(uS<70 && uS>20)
  {
    beep(400);
    //analogWrite(3,305-range);
    Serial.println("b");
  }
  else {
    Serial.println(" out of range ");
    analogWrite(9, 0);
    analogWrite(3, 0);
    delay(100);
  }
}

void beep(unsigned char pausa)
{
    analogWrite(9, 20);
    delay(pausa);                 // Espera
    analogWrite(9, 0);            // Apaga
    delay(pausa);                 // Espera
}
