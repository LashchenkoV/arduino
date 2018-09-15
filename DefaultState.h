#ifndef DefaultState_h
#define DefaultState_h
#include "Arduino.h"
#include "IState.h"

class DefaultState : public IState
{
  public:
    void update();
    DefaultState();   
};

#endif