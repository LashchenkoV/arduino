#ifndef Helper_h
#define Helper_h
#include "Arduino.h"
#include "sav_button.h";
#include "PressueSensor.h";
#include <LiquidCrystal_I2C.h>;

class Helper
{
public:
  enum State
  {
    ST_DEFAULT,
    ST_SERVICE
  };
  static State state;
  static LiquidCrystal_I2C lcd;
  static SButton buttons[2];
  static PressueSensor sensors[3];
  static int getLenghtSensors();
};

#endif