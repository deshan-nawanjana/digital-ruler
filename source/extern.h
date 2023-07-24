// externs for accelerometer
extern void setupAccelerometer();

// externs for lcd module
extern void setupDisplay();
extern void updateDisplayLines(int x, int y, String input, int size);
extern String alignInteger(int value, int size);
extern void updateDisplay();

// externs for servo motor
extern void setupServo();
extern void updateServo(int change);

// externs for ultrasonic
extern void setupUltrasonic();
extern void updateUltrasonic();