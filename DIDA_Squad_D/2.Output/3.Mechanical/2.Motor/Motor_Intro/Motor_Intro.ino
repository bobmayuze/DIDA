int switchPin = 2; // switch input
int motor1Pin1 = 3; // pin 2 on L293D
int motor1Pin2 = 4; // pin 7 on L293D
int enablePin = 9; // pin 1 on L293D

void setup() {
    // set the switch as an input:
    pinMode(switchPin, INPUT);

    // set all the other pins you're using as outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enablePin, OUTPUT);

    // set enablePin high so that motor can turn on:
    digitalWrite(enablePin, HIGH);
}

void loop() {
    // if the switch is high, motor will turn on one direction:
    if (digitalRead(switchPin) == HIGH) {
        digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D low
        digitalWrite(motor1Pin2, HIGH); // set pin 7 on L293D high
    }
    // if the switch is low, motor will turn in the opposite direction:
    else {
        digitalWrite(motor1Pin1, HIGH); // set pin 2 on L293D high
        digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D low
    }
}
