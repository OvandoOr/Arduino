
#include <SPI.h>
#include "SdFat.h"
SdFat SD;

//#define SPI_SPEED SD_SCK_MHZ(39)
File dataFile, webFile, myFile;
const int ledPin =  2;

void setup() {
    if (!SD.begin(chipSelect, SD_SCK_MHZ(30))) {
    Serial.println("SD failded...");
    for(int r=0;r<4;r++){
      digitalWrite(ledPin, LOW);
      delay(500);
      digitalWrite(ledPin, HIGH);
      delay(500);
    }
    ESP.reset();
  }
}
int cont=0;
void loop() {
  if(Serial.available()>0)
  {
    char inByte = Serial.read();
    myFile = SD.open("prueba.txt", O_READ | O_WRITE | O_CREAT | O_TRUNC);

    // if the file opened okay, write to it:
    if (myFile) {
      Serial.print("Writing to setup_iecg.txt...");
      myFile.print(inByte);
      // close the file:
      myFile.close();
      Serial.println("done.");
    } else {  
      // if the file didn't open, print an error:
      Serial.println("error opening setup_iecg.txt");
    }
  }
}
