// (Original) BlinkLed.ino


void setup() {
    pinMode(5, OUTPUT);
    pinMode(6, INPUT_PULLUP);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
//    Serial.begin(250000);
//    Serial.setTimeout(10);
}

void loop() {
    int pin6 = digitalRead(6);
    int current_pin = 9;
//    if(Serial.available()){
//      Serial.parseInt(); 
//    }
//    analOn(5);
    turnOn(pin6, current_pin);
    turnOff(pin6, current_pin);
}

void analOn(int pin){
    for(int i = 0; i <= 255; i+=5){
      analogWrite(pin, i);
      delay(50);
    }
    for(int i = 255; i >= 0; i-=5){
      analogWrite(pin, i);
      delay(50);
    }
}

void turnOn(int pin6, int current_pin){
    while(current_pin < 13){
      digitalWrite(current_pin, !pin6);
      delay(500);
      current_pin++;
    }
}

void turnOff(int pin6, int current_pin){
    while(current_pin < 13){
      digitalWrite(current_pin, pin6);
      delay(500);
      current_pin++;
    }
}
