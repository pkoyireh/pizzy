// ESP32 PWM Demo – adjusted version
// This program generates a PWM signal on GPIO21 using channel 1.
// The duty cycle is gradually increased and decreased to create a fading effect.

int pwm_output = 21;        // GPIO pin where PWM signal is sent
int channel = 1;            // PWM channel (ESP32 supports multiple channels)
int freq = 15000;           // PWM frequency set to 15 kHz
int resolution = 8;         // 8-bit resolution: duty cycle range 0–255

void setup() {
  Serial.begin(9600);                         // Start serial monitor
  ledcSetup(channel, freq, resolution);       // Configure PWM channel
  ledcAttachPin(pwm_output, channel);         // Link channel to chosen pin
}

void loop() {
  // Gradually increase duty cycle from 0 to max
  for (int level = 0; level < 256; level += 10) {
    ledcWrite(channel, level);  // Update PWM duty cycle
    delay(40);                  // Small delay for visible transition
  }

  // Gradually decrease duty cycle back to 0
  for (int level = 255; level >= 0; level -= 10) {
    ledcWrite(channel, level);  // Update PWM duty cycle
    delay(40);
  }
}
