#include "BluetoothSerial.h"
#include <SPI.h>
#include <SD.h>
#include "LiquidCrystal.h"
#include "max6675.h"

// CONFIGURACION DE LOS PINES UTILIZADOS PARA LA COMUNICACIÓN CON EL MAX6675
#define CONFIG_TCSCK_PIN 10  // SPI SCK
#define CONFIG_TCCS_PIN 9    // SPI CS
#define CONFIG_TCDO_PIN 8    // SPI SO
unsigned long anterior_tiempo;
// OBJETO UTILIZADO PARA LA COMUNICACION CON EL MAX6675
MAX6675 thermocouple(CONFIG_TCSCK_PIN, CONFIG_TCCS_PIN, CONFIG_TCDO_PIN);

