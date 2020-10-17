#define THERMO_PIN A4
#define U_SOURCE  5.0
#define R         100000

void setup() {
  Serial.begin(9600);
}

int adc_signal = 0;
float adc_to_volt = 0.0;
float tr = 0.0;

void loop() {
  adc_signal = analogRead(THERMO_PIN);

  adc_to_volt = U_SOURCE / 1023 * adc_signal;

  tr = R * (1023.0 / adc_signal - 1);

  

  Serial.print("ADC signal ");
  Serial.println(adc_signal);

  Serial.print("Signal in volst ");
  Serial.println(adc_to_volt);

  Serial.print("Thermo resistance ");
  Serial.println(tr);
  
  delay(1000);
}
