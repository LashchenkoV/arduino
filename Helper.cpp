#include "Helper.h";
int Helper::getLenghtSensors(){
    return sizeof(Helper::sensors)/ sizeof(PressueSensor);
}