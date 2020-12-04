#include <VL53L0X.h>  
#include <Wire.h>     

#define XSHUT_TOF_1  7
#define XSHUT_TOF_2  8

#define TOF_1_ADDR  0x2A
#define TOF_2_ADDR  0x2B

VL53L0X tof_1;
VL53L0X tof_2;


void setup() { 
  Serial.begin(9600);
  while (!Serial) {
    ; // ожидаем подключения монитора порта
  }
         
  // деактивируем оба модуля, чтобы избежать конфликтов адрессации
  pinMode(XSHUT_TOF_1, OUTPUT);
  pinMode(XSHUT_TOF_2, OUTPUT);

  Wire.begin();   // активируем интерфейс I2C, arduino будем мастером

  // назначаем адрес первому модулю, активируем его и ожидаем выхода на нормальный режим работы
  tof_1.setAddress(TOF_1_ADDR);
  pinMode(XSHUT_TOF_1, INPUT);
  delay(10);

  // назначаем адрес второму модулю, активируем его и ожидаем выхода на нормальный режим работы
  tof_2.setAddress(TOF_2_ADDR);
  pinMode(XSHUT_TOF_2, INPUT);
  delay(10);
   
  // задаем таймаут ожидания данных для каждого модуля
  tof_1.setTimeout(1000);
  tof_2.setTimeout(1000);

  // инициализируем модули
  if (tof_1.init() == 0) {
    Serial.println("Не удалось обнаружить и инициализировать датчик 1!");
    while (1) {}
  }

  if (tof_2.init() == 0) {
    Serial.println("Не удалось обнаружить и инициализировать датчик 2!");
    while (1) {}
  }

  // запускаем модули в continuius режиме измерений
  tof_1.startContinuous();
  tof_2.startContinuous();
}

int distance_1 = 0;
int distance_2 = 0;

void loop() {
  distance_1 = tof_1.readRangeContinuousMillimeters();
  if (tof_1.timeoutOccurred()) { 
    Serial.println(" ТАЙМАУТ"); 
  } else {
    Serial.println(distance_1);
  }

  distance_2 = tof_2.readRangeContinuousMillimeters();
  if (tof_2.timeoutOccurred()) { 
    Serial.println(" ТАЙМАУТ"); 
  } else {
    Serial.println(distance_2);
  }
}
