/* © Sebastian camacho A.*/
/*código para practica #2 - mantenimiento mecatronico
   hacer "Estaciones con Servo y boton 
  ---- 4 Estaciones--- */

#include <Servo.h> //Incluimos la libreria de Servo para poder controlar nuestro Servomotor
Servo servoMotor; //Declaramos nuestro Servomotor
//Declaraciones
int boton = 9; //Declaramos el pin del boton que usaremos (En mi caso fue el pin 9)
int estacion = 0; //Declaramos la variable estacion para usarla mas tarde
int conta = 0; //Declaramos la variable "conta" para usarla como sumatoria
long time = 0; //Declaramos "time" para usarlo en el anti-rebote
int rebote = 200; //Declaramos los ms que va a tener nuestro rebote

void setup()
{
  servoMotor.attach(A0); //Declaramos donde esta conectado nuestro Servomotor (E mi caso A0)
  pinMode(boton, INPUT); //Declaramos el boton de manera INPUT
  servoMotor.write(0); //Colocamos el Servo en 0°, al iniciar el programa
  Serial.begin(9600); //Usaremos serial begin para leer la variable "conta", puedes quitarla o modicar el serial.print
}

void loop()
{
  
  if( (digitalRead(boton) == 1) && (millis() - time > rebote) ){ //Declaramos si el boton fue seleccionado haz esto↓↓
    time = millis();
    conta++; //conta++ nos ayuda a hacer la sumatoria cda que pulsemos el boton
    Serial.println(conta); //Aqui le decimos a Serial lo que queremos que muestre en el monitor serial, en este caso "conta"
  }
  
  switch(conta){ //usamos la variable switch para mandar las funciones correspondientes segun el pulso que va
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
    case 5: //como solo tendremos 4 estaciones o grados, al quinto pulso mandamos la variable "conta" de nuevo al inicio "0"
    conta = 0;
    break;
    
    }
  
  switch(estacion){ //con switch posicionaremos nuestro servo segun el numero de estacion que lleve el contador
    case 0:
    servoMotor.write(0); //.write nos sirve para indicarle al servomotor que grado° debe posicionarse (cambia los valores por los tuyos)
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
/*© Sebastián camacho - 2022 - 2023 - borrar de ser necesario*/

