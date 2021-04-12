
#include <Arduino.h>
#include <Motors.h>

#define STEP_PIN 3
#define DIR_PIN 4

Motors motorSet(STEP_PIN, DIR_PIN);


void setup() {
    Serial.begin(115200);

    motorSet.init();
    motorSet.setSpeed(500);
}

void loop() {
    motorSet.step();
}