#include "var_const.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to and enable it
#endif

void setup() {
  // PREPARAR LA INTERFAZ SERIAL
  Serial.begin(9600);

  // IMPRIMR MENSAJE INICIAL A LA TERMINAL
  Serial.println(F("----------------------------------------------------"));
  Serial.println(F("      SENSOR DE TEMPERATURA MAX6675 CON ARDUINO     "));
  Serial.println(F("                  Choque, Mella Soria                 "));
  Serial.println(F("----------------------------------------------------"));
  SerialBT.begin(device_name);  // Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  // ESPERAR UN SEGUNDO
  delay(1000);
}

void loop() {
  // LEER EL TERMOPAR Y ALMACENAR EL VALOR EN UNA VARIABLE
  // ESPERAR UN SEGUNDO ENTRE LAS LECTURAS
  if (millis() - anterior_tiempo > 500) {
    float t = thermocouple.readCelsius();
    anterior_tiempo = millis();
    Serial.print("ªC = ");
    Serial.println(t);
  }
}
