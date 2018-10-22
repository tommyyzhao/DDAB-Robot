#pragma once

#include <Arduino.h>
#include <NewPing.h>

namespace DDAB {
  
  class DistanceSensor{
    private:
      int trigger_pin_front;
      int trigger_pin_left;
      int trigger_pin_right;
      
      int echo_pin_front;
      int echo_pin_left;
      int echo_pin_right;
      
      int max_distance;
      
      int distance_left=0;
      int distance_right=0;
      int distance_forward=0; 
      
      NewPing* sonar1;
      NewPing* sonar2;
      NewPing* sonar3;

    public:
      DistanceSensor();
      ~DistanceSensor();


      /**
       * Description:
       *    updates sensors when called
       */
      void updateSensors();
      
      /**
       * Description:
       *    gets distance from the front sensor
       */
      int getDistanceFront();

      /**
       * Description:
       *    gets distance from the left sensor
       */
      int getDistanceLeft();
      
      /**
       * Description:
       *    gets distance from the right sensor
       */
      int getDistanceRight();
      
  };

}
