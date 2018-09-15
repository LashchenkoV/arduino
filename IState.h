#ifndef IState_h
#define IState_h
#include "Arduino.h"

class IState
{
  public:
    virtual void update();
};

#endif