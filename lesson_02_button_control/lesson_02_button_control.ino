#define BUTTON_PIN 3

int pinState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, HIGH);
}

void loop() {
  pinState = digitalRead(BUTTON_PIN);
  Serial.print("Состояние кнопки ");
  Serial.println(pinState);
  
  if (pinState == HIGH) {   
    Serial.println("Кнопка не нажата");
  }
  else {
    Serial.println("Кнопка нажата");
  }

  delay(500);
}
