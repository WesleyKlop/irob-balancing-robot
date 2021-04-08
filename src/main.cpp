/***************************************************************************
* Example sketch for the MPU9250_WE library
*
* This sketch shows how to measure pitch and roll angles from the MPU9250.
* I have also included the corrected angle method for comparison.
*
* For further information visit my blog:
*
* https://wolles-elektronikkiste.de/mpu9250-9-achsen-sensormodul-teil-1  (German)
* https://wolles-elektronikkiste.de/en/mpu9250-9-axis-sensor-module-part-1  (English)
*
***************************************************************************/

#include <Arduino.h>
#include <Motion.h>

Motion motionSensor(0x68);

void setup() {
    Serial.begin(115200);

    motionSensor.init();


}

void loop() {
    xyzFloat angles = motionSensor.getAngles();

/* This method provides quite precise values for x/y
   angles up 60°. */
    Serial.print("Angle x = ");
    Serial.print(angles.x);
    Serial.print("  |  Angle y = ");
    Serial.print(angles.y);
    Serial.print("  |  Angle z = ");
    Serial.println(angles.z);

/* Pitch and roll consider all axes for calculation. According to my experience
   it provides more reliable results at higher angles (>60°) */
    float pitch = motionSensor.getPitch();
    float roll = motionSensor.getRoll();

    Serial.print("Pitch   = ");
    Serial.print(pitch);
    Serial.print("  |  Roll    = ");
    Serial.print(roll);
    Serial.print("  |  Temp    = ");
    Serial.println(motionSensor.getTemperature());

    Serial.println();

    delay(1000);

}