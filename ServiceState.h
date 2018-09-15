#ifndef ServiceState_h
#define ServiceState_h
#include "Arduino.h"
#include "IState.h"

class ServiceState : public IState
{
  public:
    void update();
    ServiceState();   
};

#endif