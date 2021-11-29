const int pin_boton=10;//variables tipo int son de 16 bits
short val_short=13;//el tamaño varia dependiendo del lenguaje
char caracter='A';//variables son de 8 bits
byte pin_led= 13;//variables 8 bits
bool encendido=1;//variables 1 bit
float decimales=.2345;//variables con decimales

char cadena[]="Hola mundo";
String cadena1="Hola mundo";

//#define pin_led 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin_led,OUTPUT);//definimos el pin 13 como salida
  pinMode(pin_boton,INPUT);//definimos el pin 10 como entrada
  Serial.println("Programa para encender un led con un boton");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  bool estado_boton = digitalRead(pin_boton);
  Serial.println(estado_boton);
  
  if(estado_boton==1){
    digitalWrite(pin_led,HIGH);
    Serial.println("El led se ha encendido");
  }
  else{
    digitalWrite(pin_led,LOW);
    Serial.println("El led se ha apagado");
  }

  //digitalWrite(pin_led,digitalRead(pin_boton));

  delay(1);
  
}
