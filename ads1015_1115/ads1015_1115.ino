#include <Wire.h>
#include <Adafruit_ADS1015.h>
 
Adafruit_ADS1015 ads1015;

//Adafruit_ADS1015 ads1015;    // Construct an ads1015 at the default address: 0x48
//Adafruit_ADS1115 ads1115(0x49); // construct an ads1115 at address 0x49
// 
//void setup(void)
//{
//  ads1015.begin();  // Initialize ads1015
//  ads1115.begin();  // Initialize ads1115
//}
 
void setup(void)
{
  Serial.begin(115200);
  Serial.println("Hello!");
  
  Serial.println("Getting single-ended readings from AIN0..3");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 3mV)");
  ads1015.begin();
}
 int cont=0;
void loop(void)
{
  int16_t adc0, adc1, adc2, adc3;
 if(cont<5000){
  adc0 = ads1015.readADC_SingleEnded(0);
  Serial.println(adc0);
 // delay(1);
 }
 else
  cont++;
}
