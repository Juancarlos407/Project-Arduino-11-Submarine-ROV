#include <Stepper.h>
#include <Wire.h>                 
#include <LiquidCrystal_I2C.h>    
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int motorPin1 = 8;    // Azul   - 28BYJ48 pin 1 motor
int motorPin2 = 9;    // Rosa   - 28BYJ48 pin 2 motor
int motorPin3 = 10;    // Amarillo - 28BYJ48 pin 3 motor
int motorPin4 = 11;    // Naranja - 28BYJ48 pin 4 motor
                        // Rojo   - 28BYJ48 pin 5 (VCC) motor
int motorSpeed = 1000;  //variable para fijar la velocidad del motor (el retraso entre cada secuencia)
int count = 0;          // cuenta de los pasos dados
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

void setup() 
{
{ 
lcd.begin(16,2);// Indicamos medidas de LCD   
lcd.setCursor(0,0); 
lcd.print("Velocidad Motor");
lcd.setCursor(0,1);    
lcd.print(">>>>>>>>> 45rpm");
}
{
  //declare the motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);
}
}

void loop()
{
  for(int i = 7; i >= 0; i--)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void setOutput(int out) //función secuencia giro
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
}
