#include <Arduino.h>
#include <TimerOne.h>
#include <MotorSet.h>
#include <Motion.h>

#include <constants.h>

MotorSet motorSet(
        MOTOR1_STEP_PIN, MOTOR1_DIR_PIN,
        MOTOR1_MS1_PIN, MOTOR1_MS2_PIN, MOTOR1_MS3_PIN,
        MOTOR2_STEP_PIN, MOTOR2_DIR_PIN,
        MOTOR2_MS1_PIN, MOTOR2_MS2_PIN, MOTOR2_MS3_PIN
);
Motion motionSensor;

unsigned long pitchToSpeed(long pitch);

void setup() {
    Serial.begin(APP_BAUD_RATE);

    motorSet.init(EIGHTH);
    motionSensor.init();

    Timer1.initialize(MOTOR_SPEED_LOWER);
    Timer1.attachInterrupt([]() {
        motorSet.toggleStepState();
    });
}

float previousPitch;

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
    if (absPitch < 0.25 || absPitch > 45 || pitch == previousPitch) {
        // No changes required.
        return;
    }

    // If the angle is too high, switch to EIGHTH step size.
    motorSet.setResolution(absPitch >= 16 ? EIGHTH : SIXTEENTH);

    Timer1.setPeriod(pitchToSpeed((long) absPitch));
    previousPitch = pitch;
}

inline unsigned long pitchToSpeed(const long pitch){
    unsigned long period = map((long) pitch, 0, 45, MOTOR_SPEED_LOWER, MOTOR_SPEED_UPPER);
    return period;
}
