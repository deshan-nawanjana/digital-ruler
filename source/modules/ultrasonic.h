// method to setup ultrasonic sensor
void setupUltrasonic() {
    // set trigger pin as output
    pinMode(PIN_USS_TRG, OUTPUT);
    // set echo pin as input
    pinMode(PIN_USS_ECH, INPUT);
}

// method to update ultrasonic sensor
void updateUltrasonic() {
    // low the trigger pin
    digitalWrite(PIN_USS_TRG, LOW);
    // delay to trigger
    delayMicroseconds(2);
    // high the trigger pin
    digitalWrite(PIN_USS_TRG, HIGH);
    // delay to create pulse
    delayMicroseconds(10);
    // low the trigger pin
    digitalWrite(PIN_USS_TRG, LOW);
    // calculate the pulse time for one side
    long duration = pulseIn(PIN_USS_ECH, HIGH) / 2;
    // calculate distance between wall and servo motor
    int distance = (duration * 340 * 100 / 1000000) + GAP_USS_SVR;
    // calculate length of the wall
    length = distance + GAP_SVR_END;
    // calculate width of the wall
    width = (tan(angle * M_PI / 180) * distance) + RUL_HLF_WDH;
}