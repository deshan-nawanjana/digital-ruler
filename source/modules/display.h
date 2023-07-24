// create display
LiquidCrystal_I2C display(0x27, 16, 2);

// method to setup display
void setupDisplay() {
    // begin display
    display.init();
    // turn on backlight
    display.backlight();
    // clear screen
    display.clear();
    // set cursor for first line
    display.setCursor(0, 0);
    // print first line
    updateDisplayLines(3, 0, "DIGITAL", 7);
    // set cursor for second line
    display.setCursor(0, 1);
    // print second line
    updateDisplayLines(3, 1, "RULER", 5);
    // delay for start screen
    delay(1000);
    // clear screen
    display.clear();
}

// method to update display text lines
void updateDisplayLines(int x, int y, String input, int size) {
    // Serial.print("Print: ");
    // Serial.println(input);
    // get string length
    int length = input.length();
    // for size of space
    for(int i = 0; i < size; i++) {
        // create current char
        char c = ' ';
        // check for char from input
        if(i < length) {
            // set char from input
            c = input[i];
        }
        // check line
        if(y == 0) {
            // Serial.print("L1: char = ");
            // Serial.println(c);
            // check first line for char change
            if(line_1[i + x] != c) {
                // set display cursor
                display.setCursor(i + x, y);
                // update char on lines
                line_1[i+ x] = c;
                // print char on display
                display.print(c);
            }
        } else if(y == 1) {
            // Serial.print("L2: char = ");
            // Serial.println(c);
            // check first line for char change
            if(line_2[i + x] != c) {
                // set display cursor
                display.setCursor(i + x, y);
                // update char on lines
                line_2[i+ x] = c;
                // print char on display
                display.print(c);
            }
        }
    }
}

// method to align integer
String alignInteger(int value, int size) {
    // convert value to string
    String input = String(value);
    // get input string length
    int length = input.length();
    // create output string
    String output = "                ";
    // set end character
    output[size] = '\0';
    // for each char in output
    for(int i = 0; i < size; i++) {
        // set char on output
        output[i] = ' ';
    }
    // for each char in input
    for(int i = 0; i < length; i++) {
        // set char on output
        output[size - length + i] = input[i];
    }
    // return output
    return output;
}

// method to update display
void updateDisplay() {
    // print x rotation label
    updateDisplayLines(0, 0, "RX: ", 4);
    // calculate x rotation
    String rot_x = alignInteger(adxl_x / 10, 2);
    // print x rotation value
    updateDisplayLines(4, 0, rot_x, 2);
    // print rotation unit
    updateDisplayLines(6, 0, String((char)223), 1);

    // calculate y rotation
    String rot_y = alignInteger(adxl_y / 10, 2);
    // print y rotation label
    updateDisplayLines(0, 1, "RY: ", 4);
    // print y rotation value
    updateDisplayLines(4, 1, rot_y, 2);
    // print rotation unit
    updateDisplayLines(6, 1, String((char)223), 1);

    // print length label
    updateDisplayLines(8, 0, "L: ", 3);
    // print length value
    updateDisplayLines(11, 0, alignInteger(length, 3), 3);
    // print length unit
    updateDisplayLines(14, 0, "cm", 2);

    // print length label
    updateDisplayLines(8, 1, "W: ", 3);
    // print length value
    updateDisplayLines(11, 1, alignInteger(width, 3), 3);
    // print length unit
    updateDisplayLines(14, 1, "cm", 2);
}