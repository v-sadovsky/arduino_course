#define MICRO_PIN A3
#define LED_PIN   9
#define TRESHOLD 3

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

int micro_signal;
int prev_state = 0;
void loop() {
  micro_signal = analogRead(MICRO_PIN);
  Serial.print("ADC conversion value is ");
  Serial.println(micro_signal); 

  if (micro_signal > TRESHOLD) {
    prev_state = prev_state ^ 1;
    digitalWrite(LED_PIN, prev_state);
    delay(300);
  }
}
