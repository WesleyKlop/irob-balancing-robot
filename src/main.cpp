#include <Arduino.h>
#include <TimerOne.h>
#include <MotorSet.h>
#include <Motion.h>

#define MOTOR1_STEP_PIN 3
#define MOTOR1_DIR_PIN 4
#define MOTOR2_STEP_PIN 5
#define MOTOR2_DIR_PIN 6

MotorSet motorSet(
        MOTOR1_STEP_PIN, MOTOR1_DIR_PIN,
        MOTOR2_STEP_PIN, MOTOR2_DIR_PIN
);
Motion motionSensor;

void setup() {
    Serial.begin(115200);

    motorSet.init();
    motionSensor.init();

    Timer1.initialize(1500);
    Timer1.attachInterrupt([]() {
        motorSet.toggleStepState();
    });
}

void loop() {
    /*
     * How this would probably work:
     * 1. Get the current pitch of the gyroscope.
     * 2. Calculate required speed to compensate using some kind of easing function (PID)
     * 3. Update the speed
     */
    float pitch = motionSensor.getPitch();
    motorSet.setDirection(pitch < 0);
}