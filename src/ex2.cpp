#include "Arduino.h"

#define GREEN_LED_PIN 27
#define BUTTON_PIN    25

bool greenOn = false;
int prevButton = LOW;

void setup(){
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    Serial.begin(115200);
};

void loop(){
    int nowButton = digitalRead(BUTTON_PIN);

    if (nowButton == HIGH && prevButton == LOW)
    {
        greenOn = !greenOn;
        digitalWrite(GREEN_LED_PIN, greenOn);
        Serial.print("GREEN=");
        Serial.println(greenOn);
        delay(50);
    }

    prevButton = nowButton;

}