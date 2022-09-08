int pin2=9;   //Entrada 2 del L293D
int pin7=10;  //Entrada 7 del L293D
int Y=A0;   //Eje Y  
int valorY;     //Variable que recoge el valor del Eje Y
int X=A1;   //Eje X
int valorX;     //Variable que recoge el valor del Eje X
int pwm1;          //Variable del PWM 1
int pwm2;          //Variable del PWM 2


void setup()
{
  Serial.begin(9600);
  pinMode(pin2,OUTPUT);
  pinMode(pin7, OUTPUT);
}

void loop()
{
  valorY=analogRead(Y);
  valorX=analogRead(X);
  Serial.println("valorY");
  Serial.println(valorY);
  Serial.println("valorX");
  Serial.println(valorX);
  
     if (valorY == valorX)
 { digitalWrite(pin2,LOW);
  digitalWrite(pin7,LOW);}
  
    if ((valorY < 500)&&(valorX > 500))
{ digitalWrite(pin2,HIGH);
 digitalWrite(pin7,LOW);}
 
    if ((valorY > 510)&&(valorX < 510)) //Reverse
  {digitalWrite(pin2,LOW);
  digitalWrite(pin7,HIGH);}
   
    if ((valorY < 500)&&(valorX < 500))
 { digitalWrite(pin2,HIGH);
  digitalWrite(pin7,LOW);}
  
    if ((valorY < 510)&&(valorX > 510)) 
  {digitalWrite(pin2,HIGH);
  digitalWrite(pin7, LOW);} //must be 128

        Serial.println("pin2");
        Serial.println(pin2);
        Serial.println("pin7");
        Serial.println(pin7);
}

