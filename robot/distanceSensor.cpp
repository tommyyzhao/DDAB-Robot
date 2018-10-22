#include "distanceSensor.h"

namespace DDAB {
  DistanceSensor::DistanceSensor() {
    max_distance = 200;
    distance_left = 0;
    distance_right = 0;
    distance_forward = 0;

    trigger_pin_front = 2;
    trigger_pin_left = 10;
    trigger_pin_right = 13;

    echo_pin_front = 1;
    echo_pin_left = 11;
    echo_pin_right = 12;
    
    sonar1 = new NewPing(trigger_pin_front,echo_pin_front,max_distance);
    sonar2 = new NewPing(trigger_pin_left,echo_pin_left,max_distance);
    sonar3 = new NewPing(trigger_pin_right,echo_pin_right,max_distance);
  }

  DistanceSensor::~DistanceSensor(){
    delete sonar1;
    delete sonar2;
    delete sonar3;
  }

  void DistanceSensor::updateSensors(){
    distance_forward=sonar1->ping_cm();
    distance_left=sonar2->ping_cm();
    distance_right=sonar3->ping_cm();
  }

  int DistanceSensor::getDistanceFront()
  {
    return distance_forward;
  }
  int DistanceSensor::getDistanceLeft()
  {
    return distance_left;
  }
  int DistanceSensor::getDistanceRight()
  {
    return distance_right;
  }
}

