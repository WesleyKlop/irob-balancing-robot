#include <Arduino.h>
#include <TimerOne.h>
#include <MotorSet.h>
#include <Motion.h>
#include <PID_v1.h>

#include <constants.h>

MotorSet motorSet(
        MOTOR1_STEP_PIN, MOTOR1_DIR_PIN,
        MOTOR1_MS1_PIN, MOTOR1_MS2_PIN, MOTOR1_MS3_PIN,
        MOTOR2_STEP_PIN, MOTOR2_DIR_PIN,
        MOTOR2_MS1_PIN, MOTOR2_MS2_PIN, MOTOR2_MS3_PIN
);
Motion motionSensor;

double setPoint = 0, input, output;
double Kp = .5, Ki = .25, Kd = 0;
PID controller(&input, &output, &setPoint, Kp, Ki, Kd, P_ON_E, DIRECT);

unsigned long rpmToPeriod(unsigned long rpm, StepResolution resolution);

void setup() {
    Serial.begin(APP_BAUD_RATE);

    motorSet.init(SIXTEENTH);
    motionSensor.init();

    controller.SetOutputLimits(0, 200);
    controller.SetSampleTime(20);
    controller.SetMode(AUTOMATIC);

    Timer1.initialize(MOTOR_SPEED_LOWER);
    Timer1.attachInterrupt([]() {
        motorSet.toggleStepState();
    });
}

void loop() {
    float pitch = motionSensor.getPitch();
    // Change direction based on pitch
    motorSet.setDirection(pitch > 0);
    // Combine pitch + acceleration into our PID input
    input = abs(pitch + motionSensor.getAcceleration());

    // Uses our global input & output
    if (!controller.Compute()) {
        // If we have no new data we don't have to do anything.
        return;
    }

    Serial.print("input: ");
    Serial.print(input);
    Serial.print(" \t| output: ");
    Serial.println(output);

    // When output is 0 the Arduino freezes. (Timer would tick too fast)
    if (output == 0) {
        return;
    }

    Timer1.setPeriod(rpmToPeriod(abs(output), SIXTEENTH));
}


/**
 * Calculate the period of time we need to configure for a given rpm.
 *
 * Example:
 *  say we want to rotate 45rpm. In half-step this is 200 * 2 = 400 steps for a rotation
 *  this means that to go 45rm we do 400 * 45 = 18 000 steps per minute. A minute is 60 000 000 microseconds.
 *  60 000 000 / 18 000 = 3333.333333333 microseconds per step. Because we toggle each time we need to half that.
 * @param rpm
 * @param resolution
 * @return
 */
inline unsigned long rpmToPeriod(const unsigned long rpm, const StepResolution resolution) {
    int stepsPerRotation = resolution * MOTOR_STEPS_PER_ROTATION;
    unsigned long stepsPerMinute = stepsPerRotation * rpm;

    return MICROSECONDS_PER_MINUTE / stepsPerMinute / 2;
}