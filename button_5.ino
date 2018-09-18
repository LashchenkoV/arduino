#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;
#include "sav_button.h";
#include "PressueSensor.h";
#include "Helper.h";
#include "DefaultState.h";
#include "ServiceState.h";

//Обьявляем сенсоры
PressueSensor Helper::sensors[] = {
    PressueSensor(A0),
    PressueSensor(A1),
    PressueSensor(A2)};

//Обьявляем кнопки
SButton Helper::buttons[] = {
    SButton(2, 50, 500, 2000, 500),
    SButton(3, 50, 500, 2000, 500)};

//Определяем монитор
LiquidCrystal_I2C Helper::lcd = *new LiquidCrystal_I2C(0x27, 16, 2);

//Определяем состояния программы
DefaultState defaultSt = *new DefaultState();
ServiceState serviceSt = *new ServiceState();

//состояние по умолчанию
Helper::State Helper::state = Helper::State::ST_DEFAULT;

//Для очистики памяти
SButton clear(4, 50, 500, 2000, 500);
void setup()
{
    Serial.begin(9600);
    //Инициализируем монитор
    Helper::lcd.init();
    Helper::lcd.backlight();
}
void loop()
{
    if (clear.update() == SB_CLICK)
    {
        MathP::EEPROM_clear();
        Serial.println("OK");
    }
    switch (Helper::state)
    {
    case Helper::State::ST_DEFAULT:
        defaultSt.update();
        break;
    case Helper::State::ST_SERVICE:
        serviceSt.update();
        break;
    }
}