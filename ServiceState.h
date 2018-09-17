#ifndef ServiceState_h
#define ServiceState_h
#include "Arduino.h"

class ServiceState
{
private:
  //Выполнен ли вход в меню
  bool entry;
  //Сработает при первом входе
  void start();
  //Выводит массу сухого авто
  void paintMassAuto();
  //Сработает при выходе
  void exit();
  //Увеличивает значение сухой массы 
  void increaseMassOnIterator(byte i);
  
  //Итератор для сухой массы
  byte iteratorMass;
  //Сухая масса
  int massAuto[5];

public:
  ServiceState();
  void update();
};

#endif