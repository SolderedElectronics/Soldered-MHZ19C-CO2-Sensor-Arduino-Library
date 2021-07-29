/**
 **************************************************
 *
 * @file        PWM-Delayed-Mode.cpp
 * @brief       Example of PWM Delayed Mode on MHZ19C
 *
 * See the board at https://solde.red/108994
 *
 * @authors     Zvonimir Haramustek for soldered.com
 ***************************************************/

#include "MHZ19-SOLDERED.h"

#define MHZ_PIN 2

// Declare MHZ in the delayed mode
MHZ19PWM mhz(MHZ_PIN, MHZ_DELAYED_MODE);

void setup()
{
    // Set serial baud
    Serial.begin(115200);
    Serial.println(F("Starting..."));

    delay(2000);

    mhz.useLimit(5000);
}

// Print CO2 value every 5 seconds
void showValue()
{
    unsigned long start = millis();
    float co2 = mhz.getCO2();
    unsigned long duration = millis() - start;

    Serial.print(F("CO2: "));
    Serial.println(co2);
    Serial.print(F("Duration: "));
    Serial.println(duration);
    Serial.println();
}

void loop()
{
    showValue();
    delay(5000);
}
