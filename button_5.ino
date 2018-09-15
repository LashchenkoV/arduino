#include "sav_button.h";
#include "PressueSensor.h";
#include "IState.h";
#include "DefaultState.h";
#include "ServiceState.h";
#include "Program.h";
#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;

LiquidCrystal_I2C lcd(0x27, 16, 2);

PressueSensor sensors[] = {
    PressueSensor(A0),
    PressueSensor(A1),
    PressueSensor(A2)};

SButton button1(2, 50, 500, 2000, 500);
SButton button2(3, 50, 500, 2000, 500);

bool serviceMenu = false;
bool entryServicemenu = false;
byte activeNumberEntryMass = 0;

int massAuto[5] = {0, 0, 0, 0, 0};

void setup()
{
    Serial.begin(9600);
    button1.begin();
    button2.begin();
    lcd.init();
    lcd.backlight();
    lcd.setCursor(6, 0);
    lcd.print("Hello");
    delay(1000);
    lcd.clear();
}
void loop()
{
    if (serviceMenu == true)
    {
        if (entryServicemenu == false)
        {
            lcd.clear();
            entryServicemenu = true;
            lcd.setCursor(4, 0);
            lcd.print("Service");
            delay(1000);
            lcd.clear();
            lcd.setCursor(activeNumberEntryMass, 1);
            lcd.print("-");
        }

        if (button1.Loop() == SB_CLICK)
        {
            if (activeNumberEntryMass + 1 == 5)
            {
                lcd.clear();
                lcd.setCursor(4, 0);
                lcd.print("Saving...");
                delay(1000);
                lcd.clear();
                entryServicemenu = false;
                serviceMenu = false;
                activeNumberEntryMass = 0;
            }
            else
            {
                lcd.clear();
                activeNumberEntryMass += 1;
                lcd.setCursor(activeNumberEntryMass, 1);
                lcd.print("-");
            }
        }
        if (button2.Loop() == SB_CLICK)
        {
            if (massAuto[activeNumberEntryMass] + 1 == 10)
                massAuto[activeNumberEntryMass] = -1;

            massAuto[activeNumberEntryMass] += 1;
        }
        if (serviceMenu == true){
            for (int m = 0; m < 5; m++)
            {
                lcd.setCursor(m, 0);
                lcd.print(massAuto[m]);
            }
        }
    }
    else
    {
        if (button1.Loop() == SB_AUTO_CLICK && button2.Loop() == SB_AUTO_CLICK)
            serviceMenu = true;

        for (int i = 0; i < sizeof(sensors) / sizeof(PressueSensor); i++)
        {
            lcd.setCursor((i * 5), 0);
            lcd.print(sensors[i].getValue());
            lcd.print(" ");
        }
    }
}