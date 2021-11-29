
#include <Wire.h>
#include <Adafruit_MLX90614.h>
 
#include <TFT_eSPI.h>
#include "bitmap.h" //(Bitmap generated with LCD Image Converter) https://sourceforge.net/projects/lcd-image-converter/
#include "Free_Fonts.h" // Include the header file attached to this sketch

TFT_eSPI tft = TFT_eSPI();   // Invoke library
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

const int buttonPin = D6;     // the number of the pushbutton pin
int xpos = 0; // Half the screen width
int ypos = 30;
int num_prom=20;
int tiempo_prom=25;
float offset= 2.5;
void setup(void) {
  Serial.begin(115200);
  Serial.print("ST7789 TFT Bitmap Test");
  mlx.begin();  
  tft.begin();     // initialize a ST7789 chip
  tft.setSwapBytes(true); // Swap the byte order for pushImage() - corrects endianness

  tft.fillScreen(TFT_BLACK);
  tft.pushImage(19,100,202,59,adagio);
  pinMode(buttonPin, INPUT);

  //delay(4000);
}

void loop() {
 Serial.println(digitalRead(buttonPin));
  if(!(digitalRead(buttonPin))){
    delay(50);
    if(!(digitalRead(buttonPin))){
       Serial.println(digitalRead(buttonPin));
      float temp_prom=0; 
      float temp_amb=mlx.readAmbientTempC();
      
      for(int i=0;i<num_prom;i++){
        float temp_obj=mlx.readObjectTempC()+offset;
        temp_prom+=temp_obj;
        delay(tiempo_prom);
      }
      temp_prom=temp_prom/num_prom;
      
      tft.fillScreen(TFT_BLACK);
      tft.setTextColor(TFT_YELLOW, TFT_BLACK);
      
    //  tft.setFreeFont(FSB18);
    //  tft.drawString("Temperatura", xpos, ypos, GFXFF);
    //  ypos += tft.fontHeight(GFXFF);
    //
    //  tft.setFreeFont(FSB24);
    //  tft.drawString(String(temp_obj, xpos, ypos, GFXFF);
    //  ypos += tft.fontHeight(GFXFF);
      
      tft.setCursor(xpos, ypos);    // Set cursor near top left corner of screen
      tft.setFreeFont(FSB18);       // Select Free Serif 12 point font
      tft.println();                // Move cursor down a line
      tft.println();                // Move cursor down a line
      tft.print("Temperatura"); // Print the font name onto the TFT screen
    
      tft.setFreeFont(FSB24);       // Select Free Serif 12 point font
      tft.println();   
      tft.print("    "); // Print the font name onto the TFT screen
      tft.print(temp_prom); // Print the font name onto the TFT screen
      tft.print("ºC"); // Print the font name onto the TFT screen
      
      Serial.print("Ambiente = ");
      Serial.print(temp_amb); 
      Serial.print("ºC\tObjeto = "); 
      Serial.print(temp_prom); 
      Serial.println("  C");
    }
  }
  //delay(100);
}
