// (Original) BlinkLed.ino


void setup() {
    pinMode(9, OUTPUT); // setting up the pin to output the information
}

void loop() {
    analOn(9);
}

void analOn(int pin){
    // Gradually turns on the LED (uses more than 4 different brightness levels)
    for(int i = 0; i <= 255; i+=5){
      analogWrite(pin, i); // Changes the pin brightness
      delay(50);
    }
    // Gradually turns off the LED (uses more than 4 different brightness levels)
    for(int i = 255; i >= 0; i-=5){
      analogWrite(pin, i); // Changes the pin brightness
      delay(50);
    }
}
