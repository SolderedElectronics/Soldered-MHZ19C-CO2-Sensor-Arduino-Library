/**
 **************************************************
 *
 * @file        PWM-Async-Mode.ino
 * @brief       Example of PWM Async Mode on MHZ19C
 *
 * See the board at https://solde.red/108994
 *
 * @authors     Zvonimir Haramustek for soldered.com
 ***************************************************/

#include "MHZ19-SOLDERED.h"

#define MHZ_PIN 2

// Declare MHZ object in anync mode
MHZ19PWM mhz(MHZ_PIN, MHZ_ASYNC_MODE);
unsigned long _time = 0;
bool waitMode = false;

void setup()
{
    // Set baud rate of the serial port
    Serial.begin(115200);
    Serial.println(F("Starting..."));

    delay(2000);

    mhz.useLimit(5000); //Set max measurable ppm
}

// This function is called periodically and shows the current value of the PWM CO2 readout
void showValue()
{
    unsigned long start = millis(); //Get timestamp of start
    float co2 = mhz.getCO2();   //Get CO2 from sensor
    unsigned long duration = millis() - start;  //Get duration of measure

    Serial.print(F("CO2: "));
    Serial.println(co2);
    Serial.print(F("Duration: "));
    Serial.println(duration);
    Serial.println();
}

void loop()
{
    unsigned long ms = millis();

    // Tests if there is data and if the time since the last data is greater than the timeout
    if (waitMode)
    {
        if (ms - _time >= 500 || ms < _time)
        {
            _time = ms;
            bool state = mhz.isDataReady(); //Check is sensor has ready data
            Serial.print(F("isDataReady: "));
            Serial.println(state);

            if (state)
            {
                waitMode = false; //If tehere is data to read, exit wait mode 
                showValue();
            }
        }
    }
    else
    {
        if (ms - _time >= 10000 || ms < _time)
        {
            _time = ms;
            waitMode = true;    //When data is read, enter wait mode
            mhz.requestData();  //Request data from sensor
            Serial.println(F("Request data"));
        }
    }
}