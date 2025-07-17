const int potPin = 15; // Potentiometer connected to GPIO27
const int ledPin = 2;  // LED connected to GPIO2 (D2)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int potValue = analogRead(potPin); // Range: 0–4095
  int brightness = map(potValue, 0, 4095, 0, 1023); // Manual PWM range

  // Simple PWM using delayMicroseconds
  for (int i = 0; i < 50; i++) {
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(brightness);  // On-time
    digitalWrite(ledPin, LOW);
    delayMicroseconds(1023 - brightness);  // Off-time
  }

  Serial.println(brightness);
}
