
// CONTROL DE SERVOMOTORES - Aldo Danilo Vargas Esquivel - 01/10/2021

// INCLUIMOS LA LIBRERIA Servo.h

#include <Servo.h>

// DECLARAMOS LOS PINES

#define pinServo_1 11
#define pinServo_2 12
#define pinPot_1 A0
#define pinPot_2 A1

// CREAMOS LOS OBJETOS Servo

    // UNO PARA CADA SERVOMOTOR

Servo servo_1;
Servo servo_2;

// INICIAMOS LAS VARIABLES, ESTAS REPRESENTAN EL ANGULO DE CADA MOTOR

int deg_1 = 0;
int deg_2 = 0;

// INICIAMOS LAS FUNCIONES

void readServoState(){ // LEE EL VALOR DE LOS SENSORES(POTENCIOMETROS) Y GUARDA EL VALOR EN LAS VARIABLES CORRESPONDIENTES
    deg_1 = analogRead(pinPot_1);
    deg_2 = analogRead(pinPot_2);
}

void setServoState(){ // ESTABLECE LA POSICION DE CADA SERVOMOTOR E IMPRIME EN PANTALLA LOS VALORES DE CADA UNO

    readServoState();

    deg_1 = map(deg_1, 0, 1023, 180, 0);
    servo_1.write(deg_1);
    Serial.print(deg_1);

    Serial.print(" - ");
    
    deg_2 = map(deg_2, 0, 1023, 180, 0);
    servo_2.write(deg_2);
    Serial.println(deg_2);
    
    delay(10);
}

// SETUP

void setup()
{

    Serial.begin(9600);
  
    pinMode(pinPot_1, INPUT);
    pinMode(pinPot_2, INPUT);

    servo_1.attach(pinServo_1);
    servo_2.attach(pinServo_2);

    servo_1.write(0);
    servo_2.write(0);
    delay(1500);
}

// LOOP

void loop() // EN EL LOOP SOLO SE EJECUTA LA FUNCION setServoState() Y QUEDA MUY LIMPIO EL CODIGO
{
    setServoState();
}
