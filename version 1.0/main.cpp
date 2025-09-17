#include <Arduino.h> // imports Arduino framework
#define D6 12  // (GPIO12 = D6 on board)
#define D5 14   // (GPIO 14 = D5 on board)

void setup() {
    Serial.begin(115200, SERIAL_8N1); // setting up serial communication 
    pinMode(D6, INPUT_PULLUP); // setting up D6 as pullup, using internal pull up resistor
    pinMode(D5, OUTPUT); // sets D5 as output for indicator LED diode
}

void loop() {
    if (digitalRead(D6) == LOW) { // pressed button detection
        Serial.println("XDD");  // writes "XDD" in terminal
        delay(50);  // debounce against multiple quick presses (antighosting) - delay split into 2 parts bcs of the LED
        digitalWrite(D5, HIGH); // lights up the LED with each press
        delay(150);  // debounce - part 2
    } else {
        digitalWrite(D5, LOW); // ensures the LED turns off
    }
}
