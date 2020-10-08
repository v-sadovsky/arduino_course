#define PHOTO_PIN A1

void setup() {
  Serial.begin(9600);

}

int photo_signal;

void loop() {
  photo_signal = analogRead(PHOTO_PIN);
  Serial.print("ADC conversion value is ");
  Serial.println(photo_signal); 
  delay(500);
}
