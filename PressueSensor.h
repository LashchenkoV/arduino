#ifndef PressueSensor_h
#define PressueSensor_h
#include "Arduino.h"

class PressueSensor
{
  private:
    uint8_t pin;
    bool stat;
    int value;

  public:
    PressueSensor(uint8_t pin);
    int getValue();
    void printValue();

  private:
    void setValue();
};

#endif