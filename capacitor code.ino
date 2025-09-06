// Pin setup
const int ledPin = 2;       // Built-in LED (GPIO2 on ESP32, D4 on ESP8266)
const int buttonPin = 23;   // Push button connected to GPIO23 (change if needed)

int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Button with internal pull-up
  Serial.begin(115200);
}

void loop() {
  // Read button (LOW when pressed because of pull-up)
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    // Button pressed → LED ON (charging)
    digitalWrite(ledPin, HIGH);
    Serial.println("Button Pressed → Capacitor Charging");
  } else {
    // Button released → LED fades (discharging)
    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(ledPin, brightness); // PWM fade
      delay(15); // controls discharge speed
    }
    Serial.println("Button Released → Capacitor Discharging");
  }
}
