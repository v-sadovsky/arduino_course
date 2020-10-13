
#define SERIES_RESISTOR 100000
#define THERMISTOR_PIN A4
#define SAMPLES_CNT    5.0

#define T0    298.15
#define B     3950
#define R0    100000
#define TEMP_DIFF 273.15 

void setup(void) {
  Serial.begin(9600);
}

int adc_reading = 0;
float average_reading = 0;
float resistance = 0;

void loop(void) {
  // накапливаем отсчеты АЦП для усреднения
  for (int i = 0; i < SAMPLES_CNT; i++) {
    adc_reading += analogRead(THERMISTOR_PIN);
    delay(20);
  }
  
  average_reading = adc_reading / SAMPLES_CNT;
  adc_reading = 0;

  // преобразуем полученные значения в сопротивление
  resistance = SERIES_RESISTOR * (1023.0 / average_reading - 1);

  // получаем температуру в кельвинах
  float kelvin = (T0 * B) / (B + T0 * log(resistance / R0));

  // преобразуем в градусы по цельсию
  kelvin -= TEMP_DIFF;
  Serial.print("Temperature ");
  Serial.println(kelvin);

  delay(1000);
}
