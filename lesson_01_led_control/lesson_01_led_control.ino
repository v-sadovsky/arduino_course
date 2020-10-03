#define LED_PIN     6
#define LED_TIMEOUT 500

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(LED_TIMEOUT);
  digitalWrite(LED_PIN, LOW);
  delay(LED_TIMEOUT);
}
