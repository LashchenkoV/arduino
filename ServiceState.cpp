#include "ServiceState.h";

/**
 * Конструктор
 */
ServiceState::ServiceState()
{
    //В меню ещё не входили
    this->entry = false;
    //Считываем массы осей
    this->readMassAxis();
    //Считываем соответствия 1ед. к кг для кажой оси
    this->readProportionForAxis(this->arrProportion);
}

/**
 * Сработает при старте меню
 */
void ServiceState::start()
{
    //Если уже входили в меню
    if (this->entry == true)
    {
        //Выводим нагрузку на текущую ось
        this->outputMassAxis(this->iteratorAxis);
        return;
    }
    //Если в меню не входили
    this->entry = true;
    //По умолчанию будет выводится масса 1 оси
    this->iteratorAxis = 0;
    //Итератор для цифры
    this->iteratorNumber = 0;
    Helper::lcd.clear();
    Helper::lcd.setCursor(4, 0);
    Helper::lcd.print("Service");
    delay(1000);
    //Рисуем итератор нагрузки на ось
    this->drawIterator(this->iteratorNumber);
}

/**
 * Сработает при выходе из сервис меню
 */
void ServiceState::exit()
{
    Helper::lcd.clear();
    Helper::lcd.setCursor(4, 0);
    Helper::lcd.print("Saving...");
    delay(1000);
    Helper::lcd.clear();
    this->entry = false;
    //Переходим в состояние по умолчанию
    Helper::state = Helper::State::ST_DEFAULT;
    //Сохранили в энергонезависимую память нагрузки на ось
    this->saveMassAxis();
    //Расчитали соответствие
    this->calculateProportion();
    //Сохранили соответствие в энергонезависимую память
    this->saveProportionForAxis();
}
/**
 * Основная ф-ция всего сервис меню
 */
void ServiceState::update()
{
    this->start();
    switch (Helper::buttons[0].update())
    {
    //Если клик длинный, итератор назад
    case SB_LONG_CLICK:
        if (this->iteratorNumber - 1 >= 0)
        {
            this->iteratorNumber--;
            //Рисуемитератор
            this->drawIterator(this->iteratorNumber);
        }
        break;
    //Если обычный клик то итератор вреред
    case SB_CLICK:
        if (this->iteratorNumber + 1 == 5)
        {
            this->nextAxis();
        }
        else
        {
            this->iteratorNumber++;
            //Рисуемитератор
            this->drawIterator(this->iteratorNumber);
        }
        break;
    }

    //Увеличивает массу при обычном клике в точке итератора
    if (Helper::buttons[1].update() == SB_CLICK)
    {
        this->increaseNumberOnIterator(this->iteratorNumber);
    }
}

void ServiceState::calculateProportion()
{
    String str;
    for (int i = 0; i < Helper::getLenghtSensors(); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            str += String(this->massAxis[i][j]);
        }
        this->arrProportion[i] = (float)str.toInt() / (float)Helper::sensors[i].getValue();
#ifdef DEBUG_SERIAL
        Serial.print(str.toInt());
        Serial.print(" / ");
        Serial.print(Helper::sensors[i].getValue());
        Serial.print(" = ");
        Serial.println(this->arrProportion[i]);
#endif
        str = "";
    }
}

void ServiceState::nextAxis()
{
    if (Helper::getLenghtSensors() - 1 == this->iteratorAxis)
    {
        this->exit();
        return;
    }
    //Переключаем ось
    this->iteratorAxis++;
    //Обнуляем итератор
    this->iteratorNumber = 0;
    //Рисуем итератрор
    this->drawIterator(0);
}
/**
 * Рисует итератор под i-той цифрой
 */
void ServiceState::drawIterator(byte i)
{
    Helper::lcd.clear();
    Helper::lcd.setCursor(i+3, 1);
    Helper::lcd.print("-");
}

/**
 * Выводит массу axis оси на монитор
 */
void ServiceState::outputMassAxis(byte axis)
{
    Helper::lcd.setCursor(0, 0);
    Helper::lcd.print(axis+1);
    Helper::lcd.print(".");
    for (int i = 0; i < 5; i++)
    {
        Helper::lcd.setCursor(i+3, 0);
        Helper::lcd.print(this->massAxis[axis][i]);
    }
    Helper::lcd.setCursor(9, 0);
    Helper::lcd.print("KG");
}

/**
 * Увеличивает цифру(одну) массы оси this->iteratorAxis на единицу
 */
void ServiceState::increaseNumberOnIterator(byte i)
{
    if (this->massAxis[this->iteratorAxis][i] + 1 == 10)
        this->massAxis[this->iteratorAxis][i] = -1;
    this->massAxis[this->iteratorAxis][i] += 1;
}

/**
 * Сохраняет массу каждой оси в энергонезависимую память
 */
void ServiceState::saveMassAxis()
{
    int it = 0;
    for (int i = 0; i < Helper::getLenghtSensors(); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            EEPROM.write(it, massAxis[i][j]);
            it++;
        }
        it++;
    }
}

/**
 * Считывает массу из энергонезависимой памяти
 */
void ServiceState::readMassAxis()
{
    int it = 0;
    for (int i = 0; i < Helper::getLenghtSensors(); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            this->massAxis[i][j] = EEPROM.read(it);
            it++;
        }
        it++;
    }
}

/**
 * Сохраняет соответствие в энергонезависимую память
 * в 
 */
void ServiceState::saveProportionForAxis()
{
    int addr = 50;
    for (int i = 0; i < Helper::getLenghtSensors(); i++)
    {
        MathP::EEPROM_float_write(i * (sizeof(float)) + addr, this->arrProportion[i]);
    }
}

/**
 * Считывает соответствие из энергонезависимой памяти
 */
void ServiceState::readProportionForAxis(float a[])
{
    int addr = 50;
    for (int i = 0; i < Helper::getLenghtSensors(); i++)
    {
        a[i] = MathP::EEPROM_float_read(i * (sizeof(float)) + addr);
    }
}