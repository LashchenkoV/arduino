#ifndef MathP_h
#define MathP_h
#include "Arduino.h"
#include <EEPROM.h>
class MathP
{
  private:
    MathP();

  public:
    static float EEPROM_float_read(int addr);
    static void EEPROM_float_write(int addr, float num);
    static unsigned int EEPROM_uint_read(int addr);
    static void EEPROM_uint_write(int addr, unsigned int num);
    static void EEPROM_clear();
};

#endif