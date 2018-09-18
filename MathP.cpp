#include "MathP.h"

float MathP::EEPROM_float_read(int addr)
{
    float f = 0.00f;
    EEPROM.get(addr, f);
    return f;
}
void MathP::EEPROM_float_write(int addr, float num)
{
    EEPROM.put(addr, num);
}

unsigned int MathP::EEPROM_uint_read(int addr)
{
    int i = 0;
    return EEPROM.get(addr, i);
}
void MathP::EEPROM_uint_write(int addr, unsigned int num)
{
    EEPROM.put(addr, num);
}
void MathP::EEPROM_clear()
{
    for (int i = 0; i < EEPROM.length(); i++)
        EEPROM.write(i, 0);
}