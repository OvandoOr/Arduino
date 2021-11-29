
#include <NewPing.h>

/*Aqui se configuran los pines donde debemos conectar el sensor*/
#define TRIGGER_PIN  D7
#define ECHO_PIN     D6
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int relay_pin=D1;
int tiempo_millis=40;
int tiempo=0;

void setup() {
  Serial.begin(115200);
  pinMode(relay_pin,OUTPUT);
  digitalWrite(relay_pin,LOW);
  while (! Serial) {
    delay(1);
  }
}


void loop() {
  int tiempo1=millis();
  Serial.print(" Leyendo medida... ");
  int uS = sonar.ping_median()/US_ROUNDTRIP_CM;
  Serial.println(uS);
  int tiempo2=millis();
  int tiempo3=tiempo2-tiempo1;
  Serial.print("Tiempo: ");
  Serial.println(tiempo3);
  if(uS<40 && uS>0){
    digitalWrite(relay_pin,HIGH);
    Serial.print("Reinicio");
    tiempo=tiempo_millis;


  }
  
  if(tiempo>0){
    digitalWrite(relay_pin,HIGH);
    Serial.print(tiempo);
    tiempo--;
  }
  else{
    digitalWrite(relay_pin,LOW);
    Serial.println("Apagado");
  }
  //delay(10);
  
}
