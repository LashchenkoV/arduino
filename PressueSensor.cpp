#include "PressueSensor.h";
/**
 * pin - номер аналового пина датчика
 */ 
PressueSensor::PressueSensor(uint8_t pin)
{
  this->pin = pin;
  pinMode(pin, INPUT);
}

void PressueSensor::setValue()
{
  this->value = analogRead(pin);
}

void PressueSensor::printValue()
{
  Serial.println(this->getValue());
}

int PressueSensor::getValue()
{
  this->setValue();
  return this->value;
}