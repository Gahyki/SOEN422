// (Original) Task2.ino


void setup() {
    pinMode(6, INPUT_PULLUP); // Input pin
    pinMode(9, OUTPUT); // Output pin
}

void loop() {
    int pin6 = digitalRead(6); // reading the pin data
    digitalWrite(9, !pin6); // inverting then writing to the pin
}
