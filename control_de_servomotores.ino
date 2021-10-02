#include <Servo.h>

#define pinServo_1 11
#define pinServo_2 12
#define pinPot_1 A0
#define pinPot_2 A1

Servo servo_1;
Servo servo_2;

int deg_1 = 0;
int deg_2 = 0;

void readServoState(){
    deg_1 = analogRead(pinPot_1);
    deg_2 = analogRead(pinPot_2);
}

void setServoState(){

    readServoState();

    deg_1 = map(deg_1, 0, 1023, 180, 0);
    servo_1.write(deg_1);
    Serial.println(deg_1);
    
    deg_2 = map(deg_2, 0, 1023, 180, 0);
    servo_2.write(deg_2);
    Serial.println(deg_2);
    
    delay(10);
}

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

void loop()
{
    setServoState();
}
