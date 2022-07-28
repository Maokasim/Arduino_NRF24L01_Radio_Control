/**
 * THIS IS CODE FOR DISPLAYING INFORMATION
 *
 * Code include void for setting display up (DisplaySetup) and void for displaying information (DisplayInformation)
 * Settings and detailed documentation you can find in "SensorRead.h" file
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (TRANSMITTER)
 */
#include "DisplayInfo.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // Creating Display object

void DisplaySetup()
{
    // custom degree character
    byte Degree[]{
        B01100,
        B10010,
        B10010,
        B01100,
        B00000,
        B00000,
        B00000,
        B00000};

    lcd.init();
    lcd.backlight();
    lcd.createChar(0, Degree);

    //--------------- displaying static components ---------------

    lcd.setCursor(0, 0);
    lcd.print("THR");
    lcd.setCursor(THRpos + 1, 0);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("BAT");
    lcd.setCursor(BATpos + 4, 1);
    lcd.print("V");

    lcd.setCursor(9, 0);
    lcd.print("X");
    lcd.setCursor(Xpos + 1, 0);
    lcd.write(0);

    lcd.setCursor(11, 1);
    lcd.print("Y");
    lcd.setCursor(Ypos + 1, 1);
    lcd.write(0);

    //--------------- displaying static components ---------------
}

void DisplayInformation(int Throttle, float Voltage, int Xangle, int Yangle)
{
    // start of displaying throttle information
    if (Throttle > 0 && Throttle <= 9)
    {
        lcd.setCursor(THRpos + 1, 0);
        lcd.print("%");
        lcd.setCursor(THRpos + 2, 0);
        lcd.print(" ");
    }

    if (Throttle > 9 && Throttle <= 99)
    {
        lcd.setCursor(THRpos + 2, 0);
        lcd.print("%");
        lcd.setCursor(THRpos + 3, 0);
        lcd.print(" ");
    }

    if (Throttle > 99)
    {
        lcd.setCursor(THRpos + 3, 0);
        lcd.print("%");
    }

    lcd.setCursor(THRpos, 0);
    lcd.print(Throttle);
    // end of displaying throttle information

    // start of displaying battery information
    Voltage = Voltage / 10;
    if (Voltage > 0 && Voltage <= 9.9)
    {
        lcd.setCursor(BATpos + 4, 1);
        lcd.print("V");
        lcd.setCursor(BATpos + 5, 1);
        lcd.print(" ");
    }

    if (Voltage > 9.9 && Voltage < 13)
    {
        lcd.setCursor(BATpos + 5, 1);
        lcd.print("V");
    }

    lcd.setCursor(BATpos, 1);
    lcd.print(Voltage);
    // end of displaying battery information

    // start of displaying angles
    // X angle

    if (Xangle > -99)
    {
        lcd.setCursor(Xpos + 3, 0);
        lcd.write(0);
    }

    if (Xangle >= -99 && Xangle < -9)
    {
        lcd.setCursor(Xpos + 3, 0);
        lcd.write(0);
        lcd.setCursor(Xpos + 4, 0);
        lcd.print(" ");
    }

    if (Xangle >= -9 && Xangle < 0)
    {
        lcd.setCursor(Xpos + 2, 0);
        lcd.write(0);
        lcd.setCursor(Xpos + 3, 0);
        lcd.print(" ");
    }

    if (Xangle > 0 && Xangle <= 9)
    {
        lcd.setCursor(Xpos + 1, 0);
        lcd.write(0);
        lcd.setCursor(Xpos + 2, 0);
        lcd.print(" ");
    }

    if (Xangle > 9 && Xangle <= 99)
    {
        lcd.setCursor(Xpos + 2, 0);
        lcd.write(0);
        lcd.setCursor(Xpos + 3, 0);
        lcd.print(" ");
    }

    if (Xangle > 99)
    {
        lcd.setCursor(Xpos + 3, 0);
        lcd.write(0);
    }

    lcd.setCursor(Xpos, 0);
    lcd.print(Xangle);

    // Y angle
    if (Yangle > 0 && Yangle < 10)
    {
        lcd.setCursor(Ypos + 1, 1);
        lcd.write(0);
        lcd.setCursor(Ypos + 2, 1);
        lcd.print(" ");
    }

    if (Yangle > 10 && Yangle < 99)
    {
        lcd.setCursor(Ypos + 2, 1);
        lcd.write(0);
        lcd.setCursor(Ypos + 3, 1);
        lcd.print(" ");
    }

    if (Yangle > 99)
    {
        lcd.setCursor(Ypos + 3, 1);
        lcd.write(0);
    }

    lcd.setCursor(Ypos, 1);
    lcd.print(Yangle);
    // end of displaying angles

    // end of displaying information
}