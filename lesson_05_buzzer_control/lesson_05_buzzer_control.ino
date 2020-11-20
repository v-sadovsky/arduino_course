#define BUZ_PIN 5

void setup() {
  pinMode(BUZ_PIN, OUTPUT);
}

void loop() {
  digitalWrite(BUZ_PIN, HIGH);
  delay(500);
  digitalWrite(BUZ_PIN, LOW);
  delay(500);
}
