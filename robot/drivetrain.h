#pragma once

#include <Wire.h>
#include <Arduino.h>

namespace DDAB {
  
  class Drivetrain{
    private:
      const int Motor1 = 5;
      const int Motor2 = 6;

    public:
      Drivetrain();
      ~Drivetrain();

      /**
       * Description:
       *    Turns the robot to the left
       */
      void turnLeft();

      /**
       * Description:
       *    Turns the robot to the right
       */
      void turnRight();

      /**
       * Description:
       *    Robot goes straight forward
       */
      void goStraight();


      /**
       * Description:
       *    Stops the robot
       */
      void stop();

      /**
       * Description:
       *    Spins both motors with individual pwm speeds (from 0-255)
       */
      void tankDrive(int speed1, int speed2);
  };

}
