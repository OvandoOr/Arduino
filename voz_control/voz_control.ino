int buzzer = 9; 
int led = 6; 
int venti = 3;

int estado = 'c',estado_ant = 'c';         // inicia detenido
int contador,pasos=0;

int duracion, distancia;  // para Calcular distacia

void setup()  { 
  Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(venti, OUTPUT);
} 

void loop()  { 

  if(Serial.available()>0){        
    estado = Serial.read();
  
    if(estado=='a')digitalWrite(led,1);
    else if(estado=='b')digitalWrite(led,0);
    else if(estado=='c')digitalWrite(buzzer,1);
    else if(estado=='d')digitalWrite(buzzer,0);
    else if(estado=='e')digitalWrite(venti,1);
    else if(estado=='f')digitalWrite(venti,0);

    //delay(1);
    contador++;
    estado_ant=estado;
  }

}
