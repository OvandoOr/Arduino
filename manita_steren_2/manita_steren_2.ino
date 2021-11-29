#include <AFMotor.h>
AF_DCMotor motor1 (1);
AF_DCMotor motor2 (2);
AF_DCMotor motor3 (3);
AF_DCMotor motor4 (4);

int soltar = A0; 
int apretar = A5; 

int estado = 'c',estado_ant = 'c';         // inicia detenido
int contador,pasos=0;

int duracion, distancia;  // para Calcular distacia

void setup()  { 
  Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  pinMode(soltar, OUTPUT);
  pinMode(apretar, OUTPUT);
  
} 

void loop()  { 

  if(Serial.available()>0){        
    estado = Serial.read();
  
    if(estado=='a')motor1.run(FORWARD);
    else if(estado=='b')motor1.run(BACKWARD);
    else if(estado=='c')motor2.run(FORWARD);
    else if(estado=='d')motor2.run(BACKWARD);
    else if(estado=='e')motor3.run(FORWARD);
    else if(estado=='f')motor3.run(BACKWARD);
    else if(estado=='g')motor4.run(FORWARD);
    else if(estado=='h')motor4.run(BACKWARD);
    else if(estado=='i')
    {
      digitalWrite(soltar, LOW);
      digitalWrite(apretar, HIGH);
    }
    else if(estado=='j')
    {
      digitalWrite(soltar, HIGH);
      digitalWrite(apretar, LOW);
    }
    else{
      
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
     digitalWrite(soltar, LOW);
     digitalWrite(apretar, LOW);
    }
    //delay(1);
    contador++;
    estado_ant=estado;
  }

}
