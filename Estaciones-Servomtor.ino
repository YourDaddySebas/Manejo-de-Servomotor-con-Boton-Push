/* Sebastian camacho A.*/
/*código para practica #2 - mantenimiento
   hacer "Estaciones con Servo y boton 
  ---- 4 Estaciones--- */

#include <Servo.h>
Servo servoMotor;
//Declaraciones
int boton = 9;
int estacion = 0;
int conta = 0;
long time = 0;
int rebote = 200;
void setup()
{
  servoMotor.attach(A0);
  pinMode(boton, INPUT);
  servoMotor.write(0);
  Serial.begin(9600);
}

void loop()
{
  
  if( (digitalRead(boton) == 1) && (millis() - time > rebote) ){
    time = millis();
    conta++;
    Serial.println(conta);
  }
  /*
  if(conta == 1){
    estacion = 1;
  }*/
  switch(conta){
    case 0:
    estacion = 0;
    break;
    case 1:
    estacion = 1;
    break;
    case 2:
    estacion = 2;
    break;
    case 3:
    estacion = 3;
    break;
    case 4:
    estacion = 4;
    break;
    case 5:
    conta = 0;
    break;
    
    }
  
  switch(estacion){
    case 0:
    servoMotor.write(0);
    break;
    case 1:
    servoMotor.write(40);
    break;
    case 2:
    servoMotor.write(90);
    break;
    case 3:
    servoMotor.write(130);
    break;
    case 4:
    servoMotor.write(180);
    break;
  }
}
