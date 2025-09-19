#include <Arduino.h>
#include <HardwareSerial.h>
#include <Adafruit_TinyUSB.h>
// put function declarations here:


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200); // sets serial comm, research the value
pinMode (13, OUTPUT); // powers on the battery charging pin
pinMode(0, INPUT_PULLUP);
pinMode(10, OUTPUT);
digitalWrite(10, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(0) == LOW){
  Serial.write("Xiao world!");
  digitalWrite(10, HIGH);
  delay(280);  //specifies delay between registered key presses, needs further work (bigger delay after first click then shorter delay)
  digitalWrite(10, LOW);
}
}