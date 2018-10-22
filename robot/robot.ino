#include "distanceSensor.h"
#include "drivetrain.h"
#include <stdlib.h>

using namespace DDAB;

Drivetrain *drivetrain;
DistanceSensor *distanceSensor;

int speed = 75;
const byte numChars = 32;
char receivedChars[numChars]; // an array to store the received data

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Initializing");
  drivetrain = new Drivetrain();
  Serial.println("Drivetrain initialized");
  distanceSensor = new DistanceSensor();
  Serial.println("Sensor initialized");
}

void loop() {
  // put your main code here, to run repeatedly:
  inputSpeed();
  drivetrain->tankDrive(speed, speed);
}

void inputSpeed() {
   static byte ndx = 0;
   char endMarker = '\n';
   char rc;
   
 
   while (Serial.available() > 0) {
     rc = Serial.read();
    
     if (rc != endMarker) {
         receivedChars[ndx] = rc;
         ndx++;
         if (ndx >= numChars) {
            ndx = numChars - 1;
         }
     } else {
         char* pEnd;
         speed = (int)strtol(receivedChars,&pEnd, 10);
         Serial.println(speed);
         receivedChars[ndx] = '\0'; // terminate the string
         ndx = 0;
         strcpy(receivedChars, "" );
     }
  }
}



