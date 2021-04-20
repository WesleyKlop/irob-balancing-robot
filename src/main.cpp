#include <Arduino.h>
#include <TimerOne.h>
#include <MotorSet.h>
#include <Motion.h>
//#include <StepResolution.h>

#define MOTOR1_STEP_PIN 2
#define MOTOR1_DIR_PIN 3
#define MOTOR2_STEP_PIN 4
#define MOTOR2_DIR_PIN 5
#define MOTOR1_MS1_PIN 6
#define MOTOR1_MS2_PIN 7
#define MOTOR1_MS3_PIN 8
#define MOTOR2_MS1_PIN 9
#define MOTOR2_MS2_PIN 10
#define MOTOR2_MS3_PIN 11

#define MOTOR_SPEED_LOWER 1500
#define MOTOR_SPEED_UPPER 50

MotorSet motorSet(
        MOTOR1_STEP_PIN, MOTOR1_DIR_PIN,
        MOTOR1_MS1_PIN, MOTOR1_MS2_PIN, MOTOR1_MS3_PIN,
        MOTOR2_STEP_PIN, MOTOR2_DIR_PIN,
        MOTOR2_MS1_PIN, MOTOR2_MS2_PIN, MOTOR2_MS3_PIN
);
Motion motionSensor;

void setup() {
    Serial.begin(115200);

    motorSet.init(EIGHTH);
    motionSensor.init();

    Timer1.initialize(MOTOR_SPEED_LOWER);
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
    float absPitch = abs(pitch);

    motorSet.setDirection(pitch > 0);

    // In these cases we don't have to do anything
    if (absPitch < 0.25 || absPitch > 45) {
        // Stop motor when angle is below 1
        return;
    }

    // If the angle is too high, switch to EIGHTH step size.
    motorSet.setResolution(absPitch >= 16 ? EIGHTH : SIXTEENTH);

    unsigned long period = map((long) absPitch, 0, 45, MOTOR_SPEED_LOWER, MOTOR_SPEED_UPPER);
    Timer1.setPeriod(period);
}