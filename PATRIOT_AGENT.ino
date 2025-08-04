#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "html.h"
#include "consts.h"
#include "read_temperature.h"
#include "info.h"
#include "buildTime.h"
#include "PCF8575.h"

// Включение/отключение отладки
// #define DEBUG_ENABLE
#ifdef DEBUG_ENABLE
#define DEBUG(x) Serial.println(x)
#else
#define DEBUG(x)
#endif

// дополнительные переменные
uint16_t pinStates = 0;                 // используем 16-битное число для хранения состояний выходов на плате расширения
int lastButtonState;                                // Последнее состояние кнопки
bool isHardwareOverride = false;
ESP8266WebServer server(80);
uint32_t tmr;                                       // Для таймера измерения температуры

// Инициализация объекта PCF8575 с I2C адресом по умолчанию (0x20)
PCF8575 pcf8575(0x20);


// ФУНКЦИИ-ОБРАБОТЧИКИ ДЛЯ СЕРВЕРА

// Функция для отправки текущего состояния всех пинов и Т в формате JSON
void sendStates() {
    bool masterState = true;
    String json = "{\"states\":[";
    for (int i = 0; i < USED_PINS; i++) {
        bool state = (pinStates >> i) & 1;
        json += state ? "true" : "false";
        if (i < USED_PINS - 1) json += ",";
    }
    json += "], \"master\":";
    json += masterState ? "true" : "false";
    json += ", \"analog\":" + String(T);
    json += "}";

    server.send(200, "application/json", json);
}

// Отправляет статическую конфигурацию: названия элементов и другие лейблы
void handleGetConfig() {
    String json = "{";
    json += "\"used_pins\":" + String(USED_PINS) + ",";
    json += "\"labels\":[";
    for (int i = 0; i < USED_PINS; i++) {
        json += "\"" + ALL_SWITCH_LABELS[i] + "\"";
        if (i < USED_PINS - 1) json += ",";
    }
    json += "],";
    json += "\"name\":\"" + NAME + "\",";
    json += "\"model\":\"" + MODEL + "\",";
    json += "\"footer_left\":\"" + SN + "\",";
    json += "\"version\":\"" + V + BUILD_YEAR + BL + BUILD_MONTH + BL + BUILD_DAY + "\"";
    json += "}";
    server.send(200, "application/json", json);
}

// Обработчик для корневого URL ("/")
void handleRoot() {
    server.send(200, "text/html", HTML_CONTENT);
}

// Инициализация используемых пинов как выходов
void setAllPins(bool state) {
    uint16_t mask = (1 << USED_PINS) - 1;
    if (state) {
        pinStates |= mask; // Включить только используемые биты
    } else {
        pinStates &= ~mask; // Выключить только используемые биты
    }
    pcf8575.write16(pinStates);
}

// Обработчик для URL "/update"
void handleUpdate() {
    if (isHardwareOverride) {
        sendStates();
        return;
    }
    int id = server.arg("id").toInt();
    bool state = server.arg("state").toInt() == 1;

    if (id == 0) {
        setAllPins(state);
    } else if (id >= 1 && id <= USED_PINS) {
        int pinIndex = id - 1;
        if (state) {
            bitSet(pinStates, pinIndex);
        } else {
            bitClear(pinStates, pinIndex);
        }
        pcf8575.write16(pinStates);
    }
    sendStates();
}

// Обработчик для запроса состояния "/state"
void handleGetState() {
    sendStates();
}


void setup() {
    // Инициализация Serial для диагностики
    #ifdef DEBUG_ENABLE
    Serial.begin(115200);
    DEBUG("Start DEBUG");
    #endif

    // инициализация i2c-шины
    Wire.begin(D2, D1);

    // проверка подключения модуля расширения портов
    #ifdef DEBUG_ENABLE
    if (!pcf8575.begin()) {
        Serial.println("PCF8575 не найден!");
    } else {
        Serial.println("PCF8575 найден.");
    }
    #endif
    
    // инициализация выходов
    // pcf8575.pinMode(i, OUTPUT);

    // Инициализация пина кнопки
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    lastButtonState = digitalRead(BUTTON_PIN);
    isHardwareOverride = (lastButtonState == LOW);
    setAllPins(isHardwareOverride);

    // Инициализация пина термистора
    pinMode(T_PIN, INPUT);

    // Подключаемся к Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        DEBUG("Connecting to WiFi..");
    }

    // Выводим полученный IP адрес
    DEBUG(WiFi.localIP());

    // Регистрация обработчиков URL
    server.on("/", HTTP_GET, handleRoot);
    server.on("/config", HTTP_GET, handleGetConfig);
    server.on("/update", HTTP_GET, handleUpdate);
    server.on("/state", HTTP_GET, handleGetState);

    server.begin();
    DEBUG("http-server started");
}

void loop() {
    // Обработка клиентских запросов
    server.handleClient();

    // Постоянно проверяем состояние аппаратной кнопки
    // При изменении состояния кнопки (нажата/отпущена), принудительно включаем или выключаем все GPIO
    // Аппаратная кнопка имеет приоритет включения перед программной: если нажата аппаратная, то программная не может ничего выключить
    int currentButtonState = digitalRead(BUTTON_PIN);
    if (currentButtonState != lastButtonState) {
        // Простая защита от дребезга контактов
        delay(50); 
        // Читаем еще раз после паузы
        currentButtonState = digitalRead(BUTTON_PIN);
        if (currentButtonState != lastButtonState) {
            lastButtonState = currentButtonState;
            isHardwareOverride = (currentButtonState == LOW);
            setAllPins(isHardwareOverride);
            DEBUG(isHardwareOverride ? "Hardware override ON" : "Hardware override OFF");
        }
    }

    // обработка таймера измерения температуры
    if (millis() - tmr >= 1000) {
        tmr = millis();                 // сброс таймера
        read_temperature();             // вычислячем температуру
        DEBUG(T);
    }
}