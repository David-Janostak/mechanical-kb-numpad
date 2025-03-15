#include <Arduino.h> // imports Arduino framework
#define D6 12  // GPIO12 (D6 on board)

void setup() {
    Serial.begin(115200, SERIAL_8N1); // setting up serial communication 
    pinMode(D6, INPUT_PULLUP); // setting up D6 as pullup, using internal pull up resistor
}

void loop() {
    if (digitalRead(D6) == LOW) { // pressed button detection
        Serial.println("XDD");  // writes "XDD" in terminal
        delay(200);  // debounce against multiple quick presses (antighosting)
    }
}
