#include <Servo.h>

Servo MyServo; 
int pos = 0; 
char Command;

enum Pin 
{
    ServoPin = 6,
    RMotorBack = 7,
    RMotorForward = 8,
    LMotorBack = 9,
    LMotorForward = 10,
};

enum CommandCharacter
{
    Forward = 'F',
    Back = 'B',
    Left = 'L',
    Rigt = 'R',
    StopCmd = 'S',
};

void setup()
{
    pinMode(LMotorForward,OUTPUT);   
    pinMode(LMotorBack,OUTPUT);   
    pinMode(RMotorForward,OUTPUT);  
    pinMode(RMotorBack,OUTPUT);   
    MyServo.attach(ServoPin);
    Serial.begin(9600); 
}

void StopCar ()
{
    digitalWrite (RMotorForward, LOW);
    digitalWrite (RMotorBack, LOW);
    digitalWrite (LMotorForward, LOW);
    digitalWrite (LMotorBack, LOW);
}

void LeftWheel (bool Forward)
{
    if (Forward) 
    {    
        digitalWrite (LMotorForward, HIGH);
        digitalWrite (LMotorBack, LOW);
    }
    else
    {
        digitalWrite (LMotorForward, LOW);
        digitalWrite (LMotorBack, HIGH);  
    }
}

void RightWheel (bool Forward)
{
    if (Forward) 
    {    
        digitalWrite (RMotorForward, HIGH);
        digitalWrite (RMotorBack, LOW);
    }
    else
    {
        digitalWrite (RMotorForward, LOW);
        digitalWrite (RMotorBack, HIGH);  
    }
}
 
void loop() {
    if(Serial.available()){
        Command = Serial.read();
        Serial.println(Command);
    }
    switch (Command) {
        case Forward:
            LeftWheel (true);
            RightWheel (true);
            delay(500);
            StopCar();
            break;
        case Back:
            LeftWheel (false);
            RightWheel (false);
            break;
        case Rigt:
            LeftWheel (true);
            delay (500);
            StopCar();
            break;
        case Left:
            RightWheel (true);
            delay (500);
            StopCar();
            break;
        case StopCmd:
            StopCar();
            break;
        defaut:
        if (Command >= '0' && Command <= '9')
        {
            int Angle = ((int)Command - (int)'0' + 1) * 18;
            MyServo.write(Angle);
        }
        break;
    }
}
