#define THERMO_PIN A4
#define U_SOURCE  5.0
#define R         100000
#define R0        110000

#define TERM_DIFF 273.15
#define T0        25 + TERM_DIFF
#define B         3950

#define SAMPLES   5.0

void setup() {
  Serial.begin(9600);
}

float adc_signal = 0.0;
int   adc_sum = 0;
float adc_to_volt = 0.0;
float tr = 0.0;
float k_temperature = 0;
float c_temperature = 0;

void loop() {
  adc_sum = 0;
  for (int i = 0; i < SAMPLES; i++) {
    adc_sum += analogRead(THERMO_PIN);
    delay(20);  
  }

  adc_signal = adc_sum / SAMPLES;

  adc_to_volt = U_SOURCE / 1023 * adc_signal;

  tr = R * (1023.0 / adc_signal - 1);

  k_temperature = T0 * B / (B + T0*log(tr/R0));
  c_temperature = k_temperature - TERM_DIFF;

  Serial.print("Temperature ");
  Serial.println(c_temperature);
  
  delay(1000);
}
