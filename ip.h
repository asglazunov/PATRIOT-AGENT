// --- ETHERNET ---

// Настройки модуля W5500
// Подключение:
// D5 GPIO_14 SCLK
// D6 GPIO_12 MISO
// D7 GPIO_13 MOSI
// D8 GPIO_15 SCS (Chip Select)

#pragma once
// #include <Ethernet.h>

// MAC-адрес взят из пула АСТРАКОМ
byte mac[] = { 0x8C, 0x1F, 0x64, 0x75, 0xF0, 0x77 };

// Статический IP-адрес устройства
IPAddress ip(10, 1, 4, 35);

// IP-адрес шлюза
IPAddress gateway(10, 1, 4, 1);

// Маска подсети
IPAddress subnet(255, 255, 255, 0);

// DNS-сервер не нужен
// IPAddress dns(8, 8, 8, 8);