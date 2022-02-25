/**
 **************************************************
 *
 * @file        PWM-Continous-Mode.cpp
 * @brief       Example of PWM Continuos Mode on MHZ19C
 *
 * See the board at https://solde.red/108994
 *
 * @authors     Zvonimir Haramustek for soldered.com
 ***************************************************/

#include "MHZ19-SOLDERED.h"

#define MHZ_PIN 2

// Declare the MHZ object
MHZ19PWM mhz(MHZ_PIN, MHZ_CONTINUOUS_MODE);

void setup()
{
    // Set serial baud
    Serial.begin(115200);
    Serial.println(F("Starting..."));

    delay(2000);

    // Set timeout off the mhz object
    mhz.useLimit(5000);
}

// Print the value of the current co2 supplied by the sensor
void showValue()
{
    unsigned long start = millis();
    float co2 = mhz.getCO2();
    unsigned long duration = millis() - start;

    Serial.print(F("CO2: "));
    Serial.println(co2);    //Get value of CO2 from sensor
    Serial.print(F("Duration: "));
    Serial.println(duration);   //Print duration of measurement
    Serial.println();
}

void loop()
{
    showValue();    //Call function to read and print CO2 value
    delay(5000);
}
