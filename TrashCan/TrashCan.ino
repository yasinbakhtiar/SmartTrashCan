// Smart Trash Can with Arduino
// By Yasin Bakhtiar

#include <Servo.h>

Servo servo;

const int ledGreen = 12;
const int ledRed = 13;
const int TCRT5000D = 4; 

const int pingPin = 3; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 2; // Echo Pin of Ultrasonic Sensor
long duration;

const int servoPin = 9;
int servoAngle = 85; 

void setup() {
  
  servo.attach(servoPin);
  servo.write(85);
  
  // change pinMode of Leds to output
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  pinMode(TCRT5000D, INPUT);

  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  digitalWrite(pingPin, LOW);
  

}

void loop() {
    int readingTCRT5000 = digitalRead(TCRT5000D);
    if (readingTCRT5000 == HIGH)
    {
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
    }
    else if (readingTCRT5000 == LOW)
    {
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, LOW);
    }
    
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pingPin, LOW);
    duration = pulseIn(echoPin, HIGH) / 29 / 2;

    
    if (duration <= 5 && duration != 0)
    {
       OpenDoor();
    }
}



void OpenDoor()
{
  
    for(servoAngle = 85; servoAngle > 0; servoAngle--) {
        servo.write(servoAngle);
        delay(15);
    }
    
    delay(2000);

        for(servoAngle = 0; servoAngle < 85; servoAngle++) {
        servo.write(servoAngle);
        delay(15);
    }

}
