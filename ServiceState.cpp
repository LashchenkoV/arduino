#include "ServiceState.h";
#include "Helper.h";

void ServiceState::update()
{
    this->start();
    if (Helper::buttons[0].update() == SB_CLICK)
    {
        if (this->iteratorMass + 1 == 5)
        {
            this->exit();
        }
        else
        {
            this->iteratorMass += 1;
            Helper::lcd.clear();
            Helper::lcd.setCursor(this->iteratorMass, 1);
            Helper::lcd.print("-");
        }
    }
    if (Helper::buttons[1].update() == SB_CLICK)
    {
        this->increaseMassOnIterator(this->iteratorMass);
    }
}

ServiceState::ServiceState()
{
    this->iteratorMass = 0;
    this->entry = false;
    for (int i = 0; i < 5; i++)
    {
        this->massAuto[i] = 0;
    }
}

void ServiceState::paintMassAuto()
{
    for (int m = 0; m < 5; m++)
    {
        Helper::lcd.setCursor(m, 0);
        Helper::lcd.print(massAuto[m]);
    }
}
void ServiceState::increaseMassOnIterator(byte i)
{
    if (this->massAuto[i] + 1 == 10)
        this->massAuto[i] = -1;
    this->massAuto[i] += 1;
}
void ServiceState::exit()
{
    Helper::lcd.clear();
    Helper::lcd.setCursor(4, 0);
    Helper::lcd.print("Saving...");
    delay(1000);
    Helper::lcd.clear();
    this->entry = false;
    Helper::state = Helper::State::ST_DEFAULT;
    this->iteratorMass = 0;
}
void ServiceState::start()
{
    if (this->entry == true)
    {
        this->paintMassAuto();
        return;
    }
    Helper::lcd.clear();
    this->entry = true;
    Helper::lcd.setCursor(4, 0);
    Helper::lcd.print("Service");
    delay(1000);
    Helper::lcd.clear();
    Helper::lcd.setCursor(this->iteratorMass, 1);
    Helper::lcd.print("-");
}