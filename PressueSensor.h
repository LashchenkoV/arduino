#ifndef PressueSensor_h
#define PressueSensor_h

class PressueSensor
{
  private:
    uint8_t pin;
    bool stat;
    int value;

  public:
    PressueSensor(int pin);
    int getValue();
    void printValue();

  private:
    void setValue();
};

#endif