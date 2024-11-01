//INCLUSION DE LAS LIBRERIAS
#include <BleSerial.h> //Comunicación Bluetooth Low Energy
#include "max6675.h"
#include <Ticker.h>
#include <map>
#include <LiquidCrystal.h>
//LCD
const int rs = 3, en = 21, d4 = 19, d5 = 18, d6 = 5, d7 = 17;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



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
bool estado_anterior_conexion = false;


//Mensajes
String dato_ble = "";
String boton4 = "prender ";
String boton3 = "apagar ";
String boton2 = "mitad ";

std::map<String, int> casosPWM = {
  { boton4, 255 },
  { boton3, 0 },
  { boton2, 50 }
};

// CREACION OBJETOS
MAX6675 thermocouple(CONFIG_TCSCK_PIN, CONFIG_TCCS_PIN, CONFIG_TCDO_PIN); //Soldador 
BleSerial ble;          //Comunicación BLE
Ticker cambio_salida;  // Libreria Ticker Sistema Sincrono
Ticker lectura_soldador;
Ticker muestra_soldador;
Ticker cambio_conexion;
Ticker envio_ble;