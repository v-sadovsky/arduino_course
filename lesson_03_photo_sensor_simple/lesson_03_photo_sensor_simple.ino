#define PHOTO_PIN A1
#define LED_PIN   9
#define DAY_LIGHT 10

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

int photo_signal;

void loop() {
  photo_signal = analogRead(PHOTO_PIN);
  Serial.print("ADC conversion value is ");
  Serial.println(photo_signal); 
  delay(500);

  if (photo_signal < DAY_LIGHT) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
