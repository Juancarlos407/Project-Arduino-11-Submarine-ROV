int pin2=9;   //Entrada 2 del L293D M1
int pin7=10;  //Entrada 7 del L293D M1
int pin10=6;   //Entrada 10 del L293D M2
int pin15=11;  //Entrada 15 del L293D M2
int Y=A0;   //Eje Y  (Joystick 1)
int valorY;     //Variable que recoge el valor del Eje Y
int Y2=A1;   //Eje X   (Joystick 2)
int valorX;     //Variable que recoge el valor del Eje Y2
int pwm1;          //Variable del PWM 1 M1
int pwm2;          //Variable del PWM 2 M1
int pwm3;          //Variable del PWM 3 M2
int pwm4;          //Variable del PWM 4 M2

 
void setup()
{
  Serial.begin(9600);
  pinMode(pin2,OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin10,OUTPUT);
  pinMode(pin15, OUTPUT);
}

 
void loop()
{
  valorY=analogRead(Y);
  Serial.println(valorY);
  pwm1 = map(valorY, 0, 1023, 0, 255); //mapeamos pasando de la entrada analogica a los valores de la salida
  pwm2 = map(valorY, 0, 1023, 255, 0); //Inversion respecto a pwm1

  analogWrite(pin2,pwm1);//Sacamos el PWM de las dos salidas usando analogWrite(pin,valor)
  analogWrite(pin7,pwm2);//Sacamos el PWM de las dos salidas usando analogWrite(pin,valor)

    valorX=analogRead(Y2);
  Serial.println(valorX);
  pwm3 = map(valorX, 0, 1023, 0, 255); //mapeamos pasando de la entrada analogica a los valores de la salida
  pwm4 = map(valorX, 0, 1023, 255, 0); //Inversion respecto a pwm1

  analogWrite(pin10,pwm3);//Sacamos el PWM de las dos salidas usando analogWrite(pin,valor)
  analogWrite(pin15,pwm4);//Sacamos el PWM de las dos salidas usando analogWrite(pin,valor)
}


