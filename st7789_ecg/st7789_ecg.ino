const char x[]={97,97,98,98,98,98,100,100,100,100,100,100,100,100,100,100,101,101,101,101,100,100,100,100,100,100,100,100,100,100,100,100,99,99,99,99,98,98,97,97,99,99,99,99,100,100,100,100,101,101,101,101,100,100,100,100,100,100,100,100,100,100,101,101,101,101,102,102,103,103,103,103,105,105,106,106,107,107,107,107,107,107,108,108,108,108,108,108,108,108,109,109,109,109,111,111,112,112,113,113,116,116,117,117,118,118,119,119,120,120,122,122,123,123,125,125,126,126,126,126,126,126,126,126,125,125,126,126,126,126,125,125,126,126,125,125,123,123,122,122,121,121,120,120,120,120,120,120,118,118,117,117,116,116,113,113,113,113,113,113,115,115,119,119,122,122,122,122,123,123,125,125,124,124,124,124,124,124,124,124,122,122,120,120,117,117,114,114,111,111,108,108,105,105,102,102,100,100,98,98,97,97,97,97,98,98,99,99,101,101,103,103,103,103,103,103,103,103,102,102,103,103,103,103,102,102,103,103,103,103,104,104,105,105,106,106,107,107,109,109,108,108,105,105,97,97,90,90,100,100,117,117,143,143,178,178,207,207,229,229,235,235,218,218,190,190,148,148,101,101,61,61,27,27,19,19,29,29,47,47,71,71,85,85,89,89,88,88,85,85,84,84,86,86,91,91,96,96,97,97,95,95,94,94,97,97,100,100,101,101,101,101,102,102,104,104,105,105,106,106,107,107,107,107,108,108,110,110,111,111,112,112,112,112,111,111,111,111,111,111,112,112,113,113,115,115,116,116,117,117,117,117,117,117,118,118,119,119,119,119,119,119,119,119,119,119,118,118,118,118,118,118,120,120,122,122,123,123,125,125,124,124,124,124,124,124,122,122,119,119,117,117,113,113,110,110,108,108,106,106,103,103,99,99,94,94,88,88,82,82,79,79,77,77,76,76,76,76,79,79,81,81,83,83,86,86,88,88,90,90,93,93,94,94,95,95,95,95,96,96,96,96,96,96,97,97,97,97,97,97,98,98,99,99,99,99,99,99,99,99,98,98,97,97,96,96,96,96,96,97,97,98,99,100,100,100,101,101,101,101,101,101,102,103,103,102,101,101,101,100,100,100,99,99,99,100,100,101,101,101,101,101,101,102,101,101,101,101,102,102,103,103};



#include <Adafruit_GFX.h>    // Core graphics library by Adafruit
#include <Arduino_ST7789.h> // Hardware-specific library for ST7789 (with or without CS pin)
#include <SPI.h>

#define TFT_DC    D1
#define TFT_RST   D0
//#define TFT_CS    10 // only for displays with CS pin
#define TFT_MOSI  11   // for hardware SPI data pin (all of available pins)
#define TFT_SCLK  13   // for hardware SPI sclk pin (all of available pins)

Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST); //for display without CS pin
long randnum;

void setup() {
  Serial.begin(9600);
  Serial.println("Initialized");
  tft.init(240, 240);   // initialize a ST7789 chip, 240x240 pixels
  tft.fillScreen(BLACK);
  //tft.setTextWrap(false);
  tft.setCursor(50, 50);
  tft.setTextColor(BLUE);
  tft.setTextSize(4);
  tft.println("iECG");
  tft.setTextColor(YELLOW);
  tft.setCursor(50, 100);
  tft.setTextSize(2);
  tft.print("BIOMEDIXT");
  uint16_t time = millis();
  delay(2000);
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
}

int pix_x=0,pix_y=0, error=5, cont=0;


void loop() {
  // put your main code here, to run repeatedly:
  randnum=random(error);
  pix_y=(x[pix_x*2]-19+randnum)/2+100;

  pix_x++;
  if(pix_x>239){
    tft.fillScreen(BLACK);
    pix_x=0;
    //cont=0;
    tft.setCursor(0, 0);
    tft.setTextColor(WHITE);
    tft.print("BPM:  ");
    tft.print(60+random(-5,5));
    //tft.print("               Señal cardiaca normal");
    //tft.print(60+random(-5,5));
    cont++;

  }
  if(cont>14)
  {
    cont=0;
  }
  else if(cont>9)
  {
    error=50;
    tft.drawPixel(pix_x, pix_y, RED);
  }
  else if(cont>4)
  {
    error=20;
    tft.drawPixel(pix_x, pix_y, YELLOW);
  }
  else
  {
    error=5;
    tft.drawPixel(pix_x, pix_y, GREEN);
  }
  delay(4);
}
