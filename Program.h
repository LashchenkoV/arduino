#ifndef Program_h
#define Program_h
#include "Arduino.h"
#include "IState.h"
#include "DefaultState.h"

class Program : public IState
{
  private:
    IState state;
  public:
    void update();
    void setState(IState *state);
    IState getState();
    Program();   
};

#endif