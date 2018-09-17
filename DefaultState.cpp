#include "DefaultState.h";
#include "Helper.h";

DefaultState::DefaultState()
{
}
void DefaultState::update()
{
    Serial.println(Helper::sensors[20].getValue());
    if (Helper::buttons[0].update() == SB_AUTO_CLICK && Helper::buttons[1].update() == SB_AUTO_CLICK)
        Helper::state = Helper::State::ST_SERVICE;

    this->drawValueSensors();
}
void DefaultState::drawValueSensors()
{
    for (int i = 0; i < Helper::getLenghtSensors(); i++)
    {
        Helper::lcd.setCursor((i * 5), 0);
        Helper::lcd.print(Helper::sensors[i].getValue());
        Helper::lcd.print(" ");
    }
}
