#ifndef ServiceState_h
#define ServiceState_h
#include "Arduino.h"
#include "MathP.h"
#include "Helper.h"

class ServiceState
{

private:
  //Масссив масс осей
  int massAxis[3][5];
  //Массив соответствий единицы датчика к оси в кг
  float arrProportion[3];
  //Итератор для осей
  byte iteratorAxis;
  //Итератор для цифры
  byte iteratorNumber;

  //Выполнен ли вход в меню
  bool entry;

  //Сработает при первом входе
  void start();
  //Сработает при выходе
  void exit();

  //Считывает Массу осей
  void readMassAxis();
  //Считывает пропорции
  void readProportionForAxis();
  //Сохраняет Массу осей
  void saveMassAxis();
  //Сохраняет пропорции
  void saveProportionForAxis();
  //Выводит массу нагрузки на ось
  void outputMassAxis(byte i);

  //Расчитывает пропорцию для каждой оси
  void calculateProportion();
  //Переключает ось на следующую
  void nextAxis();
  //Увеличивает цифру при итераторе
  void increaseNumberOnIterator(byte i);
  //Рисует под цифрой нагрузки на ось полосочку
  void drawIterator(byte i);

public:
  ServiceState();
  void update();
};

#endif