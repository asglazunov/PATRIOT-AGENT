// --- ОСНОВНЫЕ НАСТРОЙКИ ---
// Имя и пароль для точки доступа Wi-Fi
const char* ssid = "astracom wi-fi 2.4 Ghz";
const char* password = "fhvbz42yjcf++";

// GPIO для светодиодов
const int gpioPins[] = {1, 2, 3, 4, 5};
// const int gpioPins[] = {2, 4, 5};
const int NUM_PINS = sizeof(gpioPins) / sizeof(int);

const String BL = "-";

// GPIO для аппаратной кнопки
// Подключаем кнопку с фиксацией между пином и землёй
// Используем внутренний подтягивающий резистор ESP8266, поэтому внешний резистор не нужен
#define BUTTON_PIN 0

// Пин для термистора
#define T_PIN A0