#include "Wire.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
 
// Pantalla OLED con dirección TWI
#define OLED_ADDR 0x3C
 
Adafruit_SSD1306 display(-1); // -1 = no reset pin
 
void setup () {
// inicializa y borra la pantalla
display.begin (SSD1306_SWITCHCAPVCC, OLED_ADDR);
display.clearDisplay ();
display.display ();
 
// muestra un pixel en cada esquina de la pantalla
display.drawPixel (0, 0, WHITE);
display.drawPixel (127, 0, WHITE);
display.drawPixel (0, 63, WHITE);
display.drawPixel (127, 63, WHITE);
 
// muestra una línea de texto
display.setTextSize (2);
display.setTextColor (WHITE);
display.setCursor (1,30);
display.print ("Hola mundo");
 
// actualiza la pantalla con todos los gráficos anteriores
display.display ();
delay(1000);
display.clearDisplay ();
display.display ();
}
 int oled=0;
void loop () {
  
//  Serial.println(value_f);
  display.drawPixel(oled, 10, WHITE);
  if(oled%42==0 || oled==127)display.display();
  oled++;
  if(oled>127){ 
    oled=0;
    display.clearDisplay();
  }
}
