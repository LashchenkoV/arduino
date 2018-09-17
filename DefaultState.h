#ifndef DefaultState_h
#define DefaultState_h
#include "Arduino.h"
#include "PressueSensor.h";
#include "Helper.h";

class DefaultState
{
public:
  DefaultState();
  void update();
  static void drawValueSensors();

};

#endif