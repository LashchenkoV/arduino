#include "MathP.h"

float MathP::EEPROM_float_read(int addr)
{
    byte raw[4];
    for (byte i = 0; i < 4; i++)
        raw[i] = EEPROM.read(addr + i);
    float &num = (float &)raw;
    return num;
}
void MathP::EEPROM_float_write(int addr, float num)
{
    byte raw[4];
    (float &)raw = num;
    for (byte i = 0; i < 4; i++)
        EEPROM.write(addr + i, raw[i]);
}
unsigned int MathP::EEPROM_uint_read(int addr)
{
    byte raw[2];
    for (byte i = 0; i < 2; i++)
        raw[i] = EEPROM.read(addr + i);
    unsigned int &num = (unsigned int &)raw;
    return num;
}
void MathP::EEPROM_uint_write(int addr, unsigned int num)
{
    byte raw[2];
    (unsigned int &)raw = num;
    for (byte i = 0; i < 2; i++)
        EEPROM.write(addr + i, raw[i]);
}
