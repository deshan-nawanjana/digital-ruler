#include <ADXL345.h>

// create adxl module
ADXL345 adxl;

// method to setup adxl module
void setupAccelerometer() {
    // power up adxl
    adxl.powerOn();
}

// method to update adxl module
void updateAccelerometer() {
    // update accelerometer values
    adxl.readAccel(&adxl_x, &adxl_y, &adxl_z);
}