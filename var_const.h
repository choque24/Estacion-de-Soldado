//INCLUSION DE LAS LIBRERIAS
#include <BleSerial.h>
#include "max6675.h"
#include <Ticker.h>
#include <map>

// CONSTANTES Y VARIABLES
const uint8_t CONFIG_TCSCK_PIN = 18;  // SPI SCK
const uint8_t CONFIG_TCCS_PIN = 5;   // SPI CS
const uint8_t CONFIG_TCDO_PIN = 19;    // SPI SO
const uint8_t LED = 23;               //Salida PWM
const uint8_t soldador = 22;
const uint8_t ledbuilt = 2;
bool salida = 0;

float temperatura_float;
int temperatura_int;
int i = 0;

int dato_int;
String dato_string = "";
bool condicion_conexion = HIGH;
bool condicion_desconexion = LOW;
String boton4 = "prender ";
String boton3 = "apagar ";
String boton2 = "mitad ";

std::map<String, int> casosPWM = {
    {boton4, 255},
    {boton3, 0},
    {boton2, 50}
};

// CREACION OBJETOS
MAX6675 thermocouple(CONFIG_TCSCK_PIN, CONFIG_TCCS_PIN, CONFIG_TCDO_PIN);
BleSerial ble;
Ticker cambio_salida;
Ticker lectura_soldador;
Ticker muestra_soldador;