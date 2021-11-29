#include <SoftwareSerial.h>

SoftwareSerial BTSerial(8, 9); // RX | TX
int cont=0;

void setup()
{
  Serial.begin(115200);
  //Serial.println("Enter AT commands:");
  BTSerial.begin(115200);  // HC-05 default speed in AT command more

  
}
//Charly_M1 address code= 98d3:32:2065b3 PSWD 123456789

//CHARLY_S1 address code= 98:D3:37:00:8C:3A PIN 0987   AT+PAIR=98D3,37,008C3A,10  

//CHARLY_S2 address code= 98:D3:32:70:95:A1 PIN 0987   AT+PAIR=98D3,32,7095A1,10




void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available()){
    Serial.write(BTSerial.read());
    //delay(1000);

  }

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available()){
    BTSerial.write(Serial.read());
    //delay(1000);
  }
    

 }
