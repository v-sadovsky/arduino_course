#define FIRST_LED 6
#define LAST_LED  13
#define LED_LIGHT_TIMEOUT 500
#define NEXT_LED_TIMEOUT  200

void setup() {
  for (int i = FIRST_LED; i <= LAST_LED; i++) {
      pinMode(i, OUTPUT);
  }
}

void loop() {
  // move forward
  for (int i = FIRST_LED; i <= LAST_LED; i++) {
    digitalWrite(i, HIGH);
    delay(LED_LIGHT_TIMEOUT);
    digitalWrite(i, LOW);
    delay(NEXT_LED_TIMEOUT);
  }  

  // move backward
  for (int i = LAST_LED-1; i > FIRST_LED; i--) {
    digitalWrite(i, HIGH);
    delay(LED_LIGHT_TIMEOUT);
    digitalWrite(i, LOW);
    delay(NEXT_LED_TIMEOUT);
  }  
}
