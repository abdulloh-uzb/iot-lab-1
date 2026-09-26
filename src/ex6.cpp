#include "Arduino.h"



void setup()
{
    Serial.begin(115200);

    pinMode(14, OUTPUT);
}

void loop()
{
    if (Serial.available() > 0) {

        char c = Serial.read();

        if (c == 'B') {
            digitalWrite(14, HIGH);
            Serial.println("BLUE=1");
        } else if (c == 'b') {
            digitalWrite(14, LOW);
            Serial.println("BLUE=0");
        }
    }
}
