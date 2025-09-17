#include <HardwareSerial.h>  // imports libraries
#include <BleKeyboard.h>

#define R1 16   // defines pins as rows and colums
#define R2 17
#define C1 21
#define C2 22
#define C3 23

// Inicializace BLE klávesnice
BleKeyboard bleKeyboard("ESP32 Keyboard", "ESP32", 100);

void setup() {
  Serial.begin(115200, SERIAL_8N1);   // setting up serial communication & defines specific parameters
  delay(300);                         // waits for the communication to stabilize
  while(Serial.available()) {         // cleans buffer
    Serial.read();
  }
  
  esp_sleep_disable_wakeup_source(ESP_SLEEP_WAKEUP_ALL); // prevents ESP from sleeping
  
  // sets rows as output
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  
  // sets columns as inputs with pull-up resistors
  pinMode(C1, INPUT_PULLUP);
  pinMode(C2, INPUT_PULLUP);
  pinMode(C3, INPUT_PULLUP);

  // BLE keyboard initialisation
  bleKeyboard.begin();
  Serial.println("BLE Keyboard ready!");
}

void loop() {
  if(bleKeyboard.isConnected()) {
    // Kontrola všech tlačítek a odeslání kláves při detekci
    
    // sets all rows to HIGH (inactive)
    digitalWrite(R1, HIGH);
    digitalWrite(R2, HIGH);
    
    // checks R1 (columns C1, C2, C3)
    digitalWrite(R1, LOW);
    if (digitalRead(C1) == LOW) {
      Serial.println("1");
      bleKeyboard.write('1');
      delay(200); // Debounce
      while(digitalRead(C1) == LOW) {} // waits for button release
    }
    if (digitalRead(C2) == LOW) {
      Serial.println("2");
      bleKeyboard.write('2');
      delay(200); // Debounce
      while(digitalRead(C2) == LOW) {} // Čekej na uvolnění tlačítka
    }
    if (digitalRead(C3) == LOW) {
      Serial.println("3");
      bleKeyboard.write('3');
      delay(200); // Debounce
      while(digitalRead(C3) == LOW) {} // Čekej na uvolnění tlačítka
    }
    digitalWrite(R1, HIGH); // sets R1 back to HIGH
    
    // checks R2 (columns C1, C2, C3)
    digitalWrite(R2, LOW);
    if (digitalRead(C1) == LOW) {
      Serial.println("4");
      bleKeyboard.write('4');
      delay(200); // Debounce
      while(digitalRead(C1) == LOW) {} // Čekej na uvolnění tlačítka
    }
    if (digitalRead(C2) == LOW) {
      Serial.println("5");
      bleKeyboard.write('5');
      delay(200); // Debounce
      while(digitalRead(C2) == LOW) {} // Čekej na uvolnění tlačítka
    }
    if (digitalRead(C3) == LOW) {
      Serial.println("6");
      bleKeyboard.write('6');
      delay(200); // Debounce
      while(digitalRead(C3) == LOW) {} // Čekej na uvolnění tlačítka
    }
    digitalWrite(R2, HIGH); // sets R2 back to HIGH
  }
  else {
    // Když není BLE připojeno
    Serial.println("Waiting for BLE connection...");
    delay(1000);
  }
  
  delay(10); // krátká pauza pro stabilitu
}