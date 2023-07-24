#include <LiquidCrystal_I2C.h>

#include "setup.h"
#include "global.h"
#include "extern.h"
#include "modules/accelerometer.h"
#include "modules/display.h"
#include "modules/servo.h"
#include "modules/ultrasonic.h"

// method to setup
void setup() {
    // begin serial communication
    Serial.begin(9600);
    // set pin mode for buttons
    pinMode(BTN_SVR_CLW, INPUT_PULLUP);
    pinMode(BTN_SVR_CCW, INPUT_PULLUP);
    // setup servo motor
    setupServo();
    // setup ultrasonic sensor
    setupUltrasonic();
    // setup adxl module
    setupAccelerometer();
    // setup display
    setupDisplay();
}

// method to loop
void loop() {
    // check for servo clock wise button
    if(digitalRead(BTN_SVR_CLW) == LOW) {
        // increase servo angle
        updateServo(+1);
    }
    // check for servo counter clock wise button
    if(digitalRead(BTN_SVR_CCW) == LOW) {
        // decrease servo angle
        updateServo(-1);
    }
    // update ultrasonic sensor
    updateUltrasonic();
    // update accelerometer module
    updateAccelerometer();
    // update display
    updateDisplay();
    // delay for next round
    delay(100);
}