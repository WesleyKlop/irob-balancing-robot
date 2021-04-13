#include <Arduino.h>
#include <MotorSet.h>

#define MOTOR1_STEP_PIN 3
#define MOTOR1_DIR_PIN 4
#define MOTOR2_STEP_PIN 5
#define MOTOR2_DIR_PIN 6
#define PWM_FREQUENCY 64000

MotorSet motorSet(
        MOTOR1_STEP_PIN, MOTOR1_DIR_PIN,
        MOTOR2_STEP_PIN, MOTOR2_DIR_PIN
);

void setupTimer1Interrupt() {
    noInterrupts();

    /* Reset timer1 register entirely */
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    OCR1A = 16000000 / PWM_FREQUENCY; // Configure compare match register
    TCCR1B |= (1 << WGM12); // Configure CTC Mode
    TCCR1B |= (1 << CS10); // Configure CS10 for 1 prescaler
    TIMSK1 |= (1 << OCIE1A); // Enable timer compare interrupt

    interrupts();
}

unsigned long pwmDutyCycleTicks;
unsigned long pwmPeriodTicks;

void configureTimer1Timings(const float periodMs, const float dutyCycleMs) {
    // Calculate how many ticks the pin should be high for the desired on period
    pwmDutyCycleTicks = (int) (dutyCycleMs / (1000.0f / PWM_FREQUENCY));
    // Calculate the total amount of ticks a period takes.
    pwmPeriodTicks = (int) (periodMs / (1000.0f / PWM_FREQUENCY));
}

void setup() {
    Serial.begin(115200);

    motorSet.init();
    setupTimer1Interrupt();
    configureTimer1Timings(1.0f, 0.2f);
}

void loop() {
    /*
     * How this would probably work:
     * 1. Get the current pitch of the gyroscope.
     * 2. Calculate required speed to compensate using some kind of easing function (PID)
     * 3. Update the speed
     */
}

volatile unsigned long ticksFired = 0;
ISR(TIMER1_COMPA_vect) { // .5ms passed when this is fired
    ticksFired++;

    if (ticksFired == pwmPeriodTicks) {
        // Reset the ticks and reset the pin to high for the restart of the duty cycles
        ticksFired = 0;
        motorSet.setStepState(HIGH);
        return;
    }

    if (ticksFired == pwmDutyCycleTicks) {
        // We have been HIGH for long enough now.
        motorSet.setStepState(LOW);
    }
}
