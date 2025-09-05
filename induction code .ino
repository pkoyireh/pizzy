const int pwmPin = 23;      // PWM output to LED + inductor
const int pwmChannel = 0;   // LEDC channel
const int pwmResolution = 8; // 8-bit (0-255)
const int duty = 128;       // 50% duty cycle
const int buttonPin = 21;   // Button input (to GND)
int freqs[] = {5, 50, 200, 1000, 5000}; // Hz list to test
void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  ledcAttachPin(pwmPin, pwmChannel);
}
void loop() {
  bool pressed = (digitalRead(buttonPin) == LOW);

  if (pressed) {
    // Cycle through different frequencies
    for (int i = 0; i < sizeof(freqs) / sizeof(freqs[0]); i++) {
      int f = freqs[i];
      ledcSetup(pwmChannel, f, pwmResolution);
      ledcWrite(pwmChannel, duty);
      Serial.printf("PWM ON @ %d Hz (button pressed)\n", f);
      delay(3000); // 3s per frequency
    }
  } else {
    ledcWrite(pwmChannel, 0);
    Serial.println("PWM OFF (button released)");
    delay(200);
  }
}
