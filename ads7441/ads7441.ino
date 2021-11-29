// Some snippets of codes that allows the use of the ADS7841 12-bit ADC
#include <SPI.h>

// Channel Selection Bytes
////////////////////////////////////////////////////////////////////////////////////
const byte ch0_code =  0b10010100;         // ADC channel 0 - Used by Li200
const byte ch1_code = 0b11010100;         // ADC channel 1 - Used by HIH4030
const byte ch2_code = 0b10100100;         // ADC channel 2 - Currently unused
const byte ch3_code = 0b11100100;         // ADC channel 3 - Currently unused
///////////////////////////////////////////////////////////////////////////////////

// ADS7841 function
////////////////////////////////////////////////////////////////////////////////////
unsigned int ads7841(const byte control){           // Function to read ADS7841
  int bitnum;                                       // Return value
  digitalWrite(SS,LOW);                             // Activate ADS7841
  SPI.transfer(control);                            // Transfer control byte
  byte msb = SPI.transfer(0);                       // Read MSB & LSB
  byte lsb = SPI.transfer(0);
  digitalWrite(SS,HIGH);                            // Deactivate ADS7841
  msb = msb & 0x7F;                                 // Isolate readings and form final reading
  lsb = lsb >> 3;
  bitnum = (char(msb) << 5) | lsb;
  return bitnum;                                    // Return
}
////////////////////////////////////////////////////////////////////////////////////


// Usage
// Call the function with the code for the channel you want.  For example, ads7841(ch0_code) will return the 
// analog voltage level of channel 0 in bits.


int cont=0;
void setup() {
  SPI.begin();                
  //  SPI.setBitOrder(MSBFIRST);
  //  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  digitalWrite(SS,HIGH);
  Serial.begin(115200);
  int tiempo=millis();
  while(cont<1000000)
  {
  int an0= ads7841(ch0_code);
  
//  Serial.print(0);
//  Serial.print(",");
//  Serial.print(2000);
//  Serial.print(",");
  Serial.println(an0);
  delay(1);
  cont++;
  }
  int tiempo2=millis()-tiempo;
  Serial.println(tiempo2);
}


void loop() {
  // put your main code here, to run repeatedly:
  
}

