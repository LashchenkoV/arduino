#ifndef DefaultState_h
#define DefaultState_h
#include "Arduino.h"
#include "PressueSensor.h";
#include "Helper.h";
#include "ServiceState.h"
class DefaultState
{
public:
  DefaultState();
  void update();
  static void drawValueSensors();
  static void drawMassAxis();
};

#endif