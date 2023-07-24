// import libraries
#include <Servo.h>

// create servo motor
Servo motor;

// method to setup servo motor
void setupServo() {
    // attach motor to start
    motor.attach(PIN_SVR_SG);
    // update current angle
    angle = 0;
    // set zero angle
    motor.write(0);
    // delay to complete rotation
    delay(1000);
}

// method to update servo angle
void updateServo(int change) {
    // value to update
    int value = angle + change;
    // check high out of range
    if(value > 90) { value = 90; }
    // check low out of range
    if(value < 0) { value = 0; }
    // return if same angle
    if(value == angle) { return; }
    // update current angle
    angle = value;
    // set motor angle
    motor.write(value);
    // delay to complete rotation
    delay(15);
}