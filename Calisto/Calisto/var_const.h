//INCLUSION DE LAS LIBRERIAS
#include <BleSerial.h>
#include "max6675.h"
#include <Ticker.h>
#include <map>

// Constantes
const uint8_t CONFIG_TCSCK_PIN = 18;  // SPI SCK
const uint8_t CONFIG_TCCS_PIN = 5;    // SPI CS
const uint8_t CONFIG_TCDO_PIN = 19;   // SPI SO
const uint8_t LED_PIN = 23;           // Salida PWM
const uint8_t SOLDADOR_PIN = 22;      // Salida Soldador
const uint8_t LED_BUILTIN = 2;        //LED builtin

// Variables globales
bool salida = 0;
float temperatura_float;
int temperatura_actual;
int dato_ble_int;
String dato_ble = "";

std::map<String, int> casosPWM = {
  { "prender ", 255 },
  { "apagar ", 0 },
  { "mitad ", 50 }
};

// CREACION OBJETOS
MAX6675 thermocouple(CONFIG_TCSCK_PIN, CONFIG_TCCS_PIN, CONFIG_TCDO_PIN);
BleSerial ble;
Ticker cambio_salida;
Ticker lectura_soldador;
Ticker muestra_soldador;
Ticker cambio_conexion;
Ticker envio_ble;