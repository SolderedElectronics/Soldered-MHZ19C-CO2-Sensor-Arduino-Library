/**
 **************************************************
 *
 * @file        Get-Values.ino
 * @brief       Example of reading all info over uart
 *
 *  See the board at https://solde.red/[_sku]
 *
 * @authors     Zvonimir Haramustek for soldered.com
 ***************************************************/

#include "MHZ19-SOLDERED.h"

// Initiate SoftwareSerial object and pass it to the constructor of MHZ19 class
SoftwareSerial swSerial(8, 9); // RX, TX
MHZ19 mhz(&swSerial);

void setup()
{
    // Set the baud rate of the serial port and software serial object
    Serial.begin(115200);
    Serial.println(F("Starting..."));

    swSerial.begin(9600);
}

void loop()
{
    // Read all the values from the sensor
    MHZ19_RESULT response = mhz.retrieveData();
    if (response == MHZ19_RESULT_OK)
    {
        Serial.print(F("CO2: "));
        Serial.println(mhz.getCO2());
        Serial.print(F("Min CO2: "));
        Serial.println(mhz.getMinCO2());
        Serial.print(F("Temperature: "));
        Serial.println(mhz.getTemperature());
        Serial.print(F("Accuracy: "));
        Serial.println(mhz.getAccuracy());
    }
    else
    {
        Serial.print(F("Error, code: "));
        Serial.println(response);
    }

    delay(15000);
}