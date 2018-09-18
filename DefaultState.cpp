#include "DefaultState.h";
DefaultState::DefaultState() {}
void DefaultState::drawMassAxis()
{
    float a[3];
    ServiceState::readProportionForAxis(a);
    Helper::lcd.setCursor(0, 0);
    
    Helper::lcd.print((int)(a[1]*Helper::sensors[1].getValue()));

}
void DefaultState::update()
{
    if (Helper::buttons[0].update() == SB_AUTO_CLICK && Helper::buttons[1].update() == SB_AUTO_CLICK)
        Helper::state = Helper::State::ST_SERVICE;

    this->drawMassAxis();
    this->drawValueSensors();
}
void DefaultState::drawValueSensors()
{
    for (int i = 0; i < Helper::getLenghtSensors(); i++)
    {
        Helper::lcd.setCursor((i * 5), 1);
        Helper::lcd.print(Helper::sensors[i].getValue());
        Helper::lcd.print(" ");
    }
}
