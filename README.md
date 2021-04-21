# Balancing Robot

For my robotics minor at Hogeschool Leiden I'm creating an inverted cartpole
robot that balances by itself.

## Hardware

Hardware and wiring here

### Components

* 1 Arduino Nano
* 1 MPU9250 Accelerometer / Gyroscope / Magnetometer
* 2 A4988 stepper motor drivers
* 2 bipolar stepper motors
* 1 47 Uf-something capacitor to prevent voltage spikes to the driver.
* 1 big breadboard
* Some big boy batteries to power everything. (I had 2x 3.7v batteries)

If you want to build the robot exactly like mine you also need some m3 
threaded steel and some washers plus nuts to mount the breadboard to the 
board you 3D printed with your 3D printer. :)

### Wiring

See [src/constants.h](./src/constants.h) for which pin goes where. MPU9250 needs
SCA / SCL cables connected to the Arduino nano.

## Software

You need to use platformio to compile and upload this to your Arduino.

## Good luck