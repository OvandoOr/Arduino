int motorA = 12 ;
int motorB = 11 ;
int Shock = 2; 
boolean AlarmaChoque,arriba=false; 

void setup ()
{
  Serial.begin(9600);
  pinMode (motorA, OUTPUT) ; 
  pinMode (motorB
  , OUTPUT) ;
  pinMode (Shock, INPUT) ; 
}
void loop ()
{
  AlarmaChoque= digitalRead (Shock) ;
  Serial.println(AlarmaChoque);
  if (AlarmaChoque == 0) 
  {
    if(arriba){
      digitalWrite (motorB, 1);
      delay(1600);
      digitalWrite (motorB, 0);
      arriba=false;
    }
    else
    {
      digitalWrite (motorA, 1);
      delay(2500);
      digitalWrite (motorA, 0);
      arriba=true;
    }
  }

  delay(10);
}
