#include <Servo.h>

Servo Servo1; //Declaramos que queremos controlar un Servo, al cual le vamos a poner un nombre cualquiera
int potenciometro = A4; //El pin análogo donde va conectado el Potenciómetro
int value; //El valor a leer por el puerto análogo

void setup()
{
Servo1.attach(3); //El pin al cual conectamos el servo 
}

void loop()
{
value = analogRead(potenciometro); //lee el valor entre 0 y 1023
value = map(value, 0 ,1023, 0, 180); //Traduce la lectura análga (0, 1023) a grados (0°, 180°)
Servo1.write(value); //Mueve el Servo según la lectura análoga
}
