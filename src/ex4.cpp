#include "Arduino.h"

#define LIGHT_PIN 33
#define BLUE_LED_PIN 14
#define GREEN_LED_PIN 27
#define YELLOW_LED_PIN 12
#define RED_LED_PIN 26

void setup()
{
    Serial.begin(115200);
    
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);

}


void loop()
{

    // hamma ledlarni off qilamiz
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);

    int light_pin_val = analogRead(LIGHT_PIN);
    String band;

    if (light_pin_val >= 3072 && light_pin_val <= 4095){
    
        digitalWrite(RED_LED_PIN, HIGH);
        
        band = "RED";
    
    } else if (light_pin_val >= 2048 && light_pin_val <= 3071) {
        
        digitalWrite(YELLOW_LED_PIN, HIGH);

        band = "YELLOW";

    } else if (light_pin_val >= 1024 && light_pin_val <= 2047) {

        digitalWrite(GREEN_LED_PIN, HIGH);
    
        band = "GREEN";

    } else if (light_pin_val >= 0 && light_pin_val <= 1023) {

        digitalWrite(BLUE_LED_PIN, HIGH);
    
        band = "BLUE";

    }

    Serial.print("band=");
    Serial.println(band);

}