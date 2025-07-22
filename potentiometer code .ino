const int signalPin = 15;
void setup() {
  Serial.begin(115200);
  pinMode(signalPin, INPUT);
}

void loop() {
  int signalState = digitalRead(signalPin);

  if (signalState == HIGH) {
    Serial.println("Signal Detected: HIGH");
} else {
  Serial.println("Signal Detected: LOW");
}
 delay(500);
}
