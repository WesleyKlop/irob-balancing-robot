#include <Arduino.h>
#include <TimerOne.h>

#include <MotorSet.h>
#include <Motion.h>
#include <Controller.h>

#include <constants.h>

MotorSet motorSet(
        MOTOR1_STEP_PIN, MOTOR1_DIR_PIN,
        MOTOR1_MS1_PIN, MOTOR1_MS2_PIN, MOTOR1_MS3_PIN,
        MOTOR2_STEP_PIN, MOTOR2_DIR_PIN,
        MOTOR2_MS1_PIN, MOTOR2_MS2_PIN, MOTOR2_MS3_PIN
);
Motion motionSensor;
Controller controller(2, 0, 0);

unsigned long rpmToPeriod(unsigned long rpm, StepResolution resolution);

void setup() {
    Serial.begin(APP_BAUD_RATE);

    motionSensor.init();
    controller.init();
    motorSet.init(SIXTEENTH);

    Timer1.initialize(MOTOR_SPEED_LOWER);
    Timer1.attachInterrupt([]() {
        motorSet.toggleStepState();
    });
}

void loop() {
    // Combine pitch + acceleration into our PID input
    controller.setInput(motionSensor.getAcceleration() - motionSensor.getPitch());

    // Uses our global input & output
    if (!controller.compute()) {
        // If we have no new data we don't have to do anything.
        return;
    }

    double output = controller.read();
    Serial.print(controller.getInput());
    Serial.print(' ');
    Serial.println(output);
    // When output is 0 the Arduino freezes. (Timer would tick too fast)
    if (output == 0) {
        return;
    }

    motorSet.setDirection(output > 0);

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
    return MICROSECONDS_PER_MINUTE / (resolution * MOTOR_STEPS_PER_ROTATION * rpm) / 2;
}