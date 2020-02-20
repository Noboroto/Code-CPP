char Command;
#include <Servo.h>

Servo MyServo; 
int pos = 0; 


void setup()
{
    pinMode(10,OUTPUT);   //left motors forward
    pinMode(9,OUTPUT);   //left motors reverse
    pinMode(8,OUTPUT);   //right motors forward
    pinMode(7,OUTPUT);   //right motors reverse
    MyServo.attach(9);
    Serial.begin(9600); 
}

void StopCar ()
{
    digitalWtite (8, LOW);
    digitalWrite (7, LOW);
    digitalWtite (10, LOW);
    digitalWrite (9, LOW);
}

void LeftWheel (bool Forward)
{
    digitalWtite (10, (int)Forward);
    digitalWrite (9, (int)Forward);
    delay (500);
    StopCar();
}

void RightWheel (bool Forward)
{
    digitalWtite (8, (int)Forward);
    digitalWrite (7, (int)Forward);
    delay (500);
    StopCar();
}
 
void loop() {
    if(Serial.available()){
        Command = Serial.read();
        Serial.println(t);
    }
    switch (Commad) {
        case 'B':
            LeftWheel (true);
            RightWheel (true);
            break;
        case 'F':
            LeftWheel (false);
            RightWheel (false);
            break;
        case 'R':
            LeftWheel (true);
            break;
        case 'L':
            RightWheel (true);
            break;
    }

else if(t == 'W'){
  for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    myservo.write(30);              
    delay(10); 
}
}
else if(t == 'w'){
  for (pos = 180; pos >= 0; pos -= 1) { 
    // in steps of 1 degree
    myservo.write(-30);              
    delay(10); 
}
} 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
}
delay(1);
}