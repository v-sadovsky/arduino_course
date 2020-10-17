#define THERMO_PIN A4
#define U_SOURCE  5.0
#define R         100000
#define R0        110000

#define TERM_DIFF 273.15
#define T0        25 + TERM_DIFF
#define B         3950


void setup() {
  Serial.begin(9600);
}

int adc_signal = 0;
float adc_to_volt = 0.0;
float tr = 0.0;
float k_temperature = 0;
float c_temperature = 0;

void loop() {
  adc_signal = analogRead(THERMO_PIN);

  adc_to_volt = U_SOURCE / 1023 * adc_signal;

  tr = R * (1023.0 / adc_signal - 1);

  k_temperature = T0 * B / (B + T0*log(tr/R0));
  c_temperature = k_temperature - TERM_DIFF;

//  Serial.print("ADC signal ");
//  Serial.println(adc_signal);
//
//  Serial.print("Signal in volst ");
//  Serial.println(adc_to_volt);
//
//  Serial.print("Thermo resistance ");
//  Serial.println(tr);

  Serial.print("Temperature ");
  Serial.println(c_temperature);
  
  delay(1000);
}
