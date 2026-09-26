#include "Arduino.h"


void setup()
{
    Serial.begin(115200);

    pinMode(12, OUTPUT);
    pinMode(25, INPUT);
}

void loop()
{  
    int button_status = digitalRead(25);

    if (button_status == HIGH){

        int light_sensor = analogRead(33);

        Serial.print("snapshot=");
        Serial.println(light_sensor);

        digitalWrite(12, HIGH);
        delay(500);
        digitalWrite(12, LOW);

    }

}