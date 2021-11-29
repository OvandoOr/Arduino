int izqA = 5; 
int izqB = 6; 
int derA = 9; 
int derB = 10; 
int vel = 230;            // Velocidad de los motores (0-255)
int vel2= 255;
int estado = 'c',estado_ant = 'c';         // inicia detenido
int contador,pasos=0;

int paso1=1000;
int paso2=1200+paso1;
int paso3=300+paso2;
int paso4=1200+paso3;
int paso5=1000+paso4;
int paso6=1000+paso5;
int paso7=300+paso6;
int paso8=1000+paso7;
int paso9=1000+paso8;
int paso10=1+paso9;

int duracion, distancia;  // para Calcular distacia

void setup()  { 
  Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  
  pinMode(13,OUTPUT);


} 

void loop()  { 

  if(Serial.available()>0){        
    estado = Serial.read();
  }
  if(estado=='j'){           //  Frente
    frente();
  }
  if(estado=='b'){          // IZQ 
    izq();
  }
  if(estado=='c'){         //  Parar
    parar();
    pasos=contador;
    if(estado_ant!=estado)
      Serial.println(pasos);
    contador=0;
  }
  if(estado=='d'){          //  DER
    derecha();
  } 

  if(estado=='e'){          //  Reversa
    analogWrite(derA, 0);    
    analogWrite(izqA, 0);
    analogWrite(derB, vel);  
    analogWrite(izqB, vel2); 
  }
  
  if(estado=='a'){          //  Reversa
    if(contador<paso1)
      frente();
    if(contador>paso1 && contador<paso2)
      izq();
    if(contador>paso2 && contador<paso3)
      frente();
    if(contador>paso3 && contador<paso4)
      derecha();
    if(contador>paso4 && contador<paso5)
      frente();
    if(contador>paso5 && contador<paso6)
      derecha();
    if(contador>paso6 && contador<paso7)
      frente();
    if(contador>paso7 && contador<paso8)
      izq();
    if(contador>paso8 && contador<paso9)
      frente();
    if(contador>paso9)
      {
        parar();
        estado='c';
      }
    //estado='c';
  }
  delay(1);
  contador++;
  estado_ant=estado;
}



void frente()
{
  analogWrite(derB, 0);     
  analogWrite(izqB, 0); 
  analogWrite(derA, vel);  
  analogWrite(izqA, vel2); 
}

void izq()
{
  analogWrite(derB, 0);     
  analogWrite(izqB, 0); 
  analogWrite(derA, 0);  
  analogWrite(izqA, vel2); 
}

void derecha()
{
  analogWrite(derB, 0);     
  analogWrite(izqB, 0); 
  analogWrite(derA, vel);  
  analogWrite(izqA, 0); 
}

void parar()
{
  analogWrite(derB, 0);     
  analogWrite(izqB, 0); 
  analogWrite(derA, 0);    
  analogWrite(izqA, 0); 
}
