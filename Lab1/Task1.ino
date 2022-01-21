// (Original) Task1.ino


void setup() {
    pinMode(6, INPUT_PULLUP); // Input pin
    pinMode(LED_BUILTIN, OUTPUT); // Output pin
}

void loop() {
    int pin6 = digitalRead(6); // reading the pin data
    digitalWrite(LED_BUILTIN, !pin6); // inverting then writing to the pin
}
