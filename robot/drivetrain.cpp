#include "drivetrain.h"

namespace DDAB {

  Drivetrain::Drivetrain(){
    pinMode(Motor1, OUTPUT);
    pinMode(Motor2, OUTPUT);
  }

  Drivetrain::~Drivetrain(){
  }

  void Drivetrain::turnLeft() {
    digitalWrite(Motor1,HIGH);
    digitalWrite(Motor2,LOW);
  }
  
  void Drivetrain::goStraight() {
    digitalWrite(Motor1,HIGH);
    digitalWrite(Motor2,HIGH);
  }
  
  void Drivetrain::turnRight() {
    digitalWrite(Motor1,LOW);
    digitalWrite(Motor2,HIGH);
  }

  void Drivetrain::tankDrive(int speed1, int speed2){
    analogWrite(Motor1, speed1);
    analogWrite(Motor2, speed2);
  }
  
  void Drivetrain::stop() {
     digitalWrite(Motor1,LOW);
     digitalWrite(Motor2,LOW);
  }
} 

