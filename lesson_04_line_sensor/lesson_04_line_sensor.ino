#define LINE_PIN  A2

void setup() {
  Serial.begin(9600);
}

void loop() {
  int data = analogRead(LINE_PIN);
//  if (data > 50) {
//    Serial.println("White ");
//  } else {
//    Serial.println("Black ");
//  }
  Serial.println(data);
//  delay(1000);
}
