// (Original) BlinkLed.ino

int LED = 9;

void setup() {
  pinMode(LED, OUTPUT); // setting up the pin to output the information
  Serial.begin(9600); // setting up the serial monitor
}

void loop() {
  analOn(LED);
}

void analOn(int pin) {
  // Gradually turns on the LED (uses more than 4 different brightness levels)
  for (int i = 0; i <= 255; i += 5) {
    analogWrite(pin, i); // Changes the pin brightness
    Serial.println(analogRead(pin)); // Reads and prints the new brightness level of the pin
    delay(50);
  }
  // Gradually turns off the LED (uses more than 4 different brightness levels)
  for (int i = 255; i >= 0; i -= 5) {
    analogWrite(pin, i); // Changes the pin brightness
    Serial.println(analogRead(pin)); // Reads and prints the new brightness level of the pin
    delay(50);
  }
}
