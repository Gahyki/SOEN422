// (Original) BlinkLed.ino

int brightness;

void setup() {
  pinMode(6, INPUT_PULLUP); // setting up the input pin
  pinMode(9, OUTPUT); // setting up the pin to output the information
  Serial.begin(9600); // setting up the serial monitor
}

void loop() {
  if (Serial.available() > 0) { // Checks for input value in the serial monitor
    brightness = Serial.parseInt(); // Saves the value of the input brightness
    Serial.print("New value: "); // Print message to track the input value
    Serial.println(brightness); // Print message to track the input value
    analogWrite(9, brightness); // Changes the pin's brightness value to the new brightness value
  }
}
