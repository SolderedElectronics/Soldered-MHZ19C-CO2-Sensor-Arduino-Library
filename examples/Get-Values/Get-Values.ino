/**
 **************************************************
 *
 * @file        Get-Values.ino
 * @brief       Example of reading all info over uart
 *
 *  See the board at https://solde.red/108994
 *
 * @authors     Zvonimir Haramustek for soldered.com
 ***************************************************/

#include "MHZ19-SOLDERED.h"

// Initiate SoftwareSerial object and pass it to the constructor of MHZ19 class
SoftwareSerial swSerial(8, 9); // RX, TX
MHZ19 mhz(&swSerial);

void setup()
{
    Serial.begin(115200);   // Start serial communication with PC using native Serial port
                            // with baudrate of 115200
    Serial.println(F("Starting..."));

    swSerial.begin(9600);   // Start serial communication with sensor using software serial
                            // with baudrate of 9600
}

void loop()
{
    // Read all the values from the sensor
    MHZ19_RESULT response = mhz.retrieveData();
    if (response == MHZ19_RESULT_OK)
    {
        Serial.print(F("CO2: "));
        Serial.println(mhz.getCO2());   // Print CO2 value in air
        Serial.print(F("Min CO2: "));
        Serial.println(mhz.getMinCO2()); // Print min measured CO2 value in air
        Serial.print(F("Temperature: "));
        Serial.println(mhz.getTemperature()); // Print air temperature
        Serial.print(F("Accuracy: "));
        Serial.println(mhz.getAccuracy()); //Print accuracy
    }
    else
    {
        Serial.print(F("Error, code: ")); //If error occured, print error code
        Serial.println(response);
    }

    delay(15000);
}