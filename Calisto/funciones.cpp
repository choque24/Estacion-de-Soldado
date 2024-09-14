#include <Arduino.h>
#include "funciones.h"
// CREACION FUNCIONES
void toggle_salida() {  //Cambia Estado Salida
  bool salida_ledbuilt = !digitalRead(ledbuilt);
  digitalWrite(ledbuilt, salida_ledbuilt);
  Serial.print("Led Built ");
  Serial.println(salida_ledbuilt ? "Encendido" : "Apagado");
}
int leer_temperatura() {                           // Lee temperatura Soldador la devuelve as INT
  temperatura_float = thermocouple.readCelsius();  // LEER EL TERMOPAR Y ALMACENAR EL VALOR EN UNA VARIABLE
  temperatura_int = int(temperatura_float);
  i++;
  if (i % 2 == 0) ble.print("Temperatura: "); //esto da el resto
  else ble.println(temperatura_int);
  return temperatura_int;
}
  void mostrar_temperatura() {  //Mostrar Monitor Serie Datos Recibidos BLE
  Serial.print("Temperatura INT: ");
  Serial.print(temperatura_int);
  Serial.println(" C°");
  Serial.print("Temperatura FLOAT: ");
  Serial.print(temperatura_float);
  Serial.println(" C°");
}
void toggleconexion(bool conexion, bool desconexion, String estado_conexion) {  //Cambia Condiciones de Conexion y Muestra Estado Conexion
  Serial.print("Conexion Bluetooth ");
  Serial.println(estado_conexion);
  Serial.println("-------------------------------");
  condicion_conexion = conexion;
  condicion_desconexion = desconexion;
}
bool esCodigoBinario(const String& cadena) {  //Si es binario devuelve True
  for (char c : cadena) {
    if (c != '0' && c != '1') {
      return false;
    }
  }
  // Puedes agregar aquí más condiciones, como un límite de longitud
  return true;
}
void regular_PWM(int intensidad) {
  ledcWriteChannel(0, intensidad);
}

// Si recibe String
bool recibir_ble() {
  if (!ble.available()) return LOW;  //Si no hay datos sale
  dato_string = ble.readString();
  return HIGH;
}

// lee devuelve temperatura
void regular_temperatura_ble() {
  if (!esCodigoBinario(dato_string)) {  //Si no es binario es String
    Serial.println("Dato Recibido String: " + dato_string);
    auto it = casosPWM.find(dato_string);
    if (it != casosPWM.end()) {  // Si se encuentra el comando, establecer la intensidad correspondiente
      regular_PWM(it->second);
      return;
      // ledcWriteChannel(0, it->second);
      // Serial.println("Comando reconocido: " + dato_string);
    }
    Serial.println("Que mandas campo");
    return;
  }
  dato_int = strtol(dato_string.c_str(), NULL, 2);
  Serial.print("Dato Recibido Entero: ");
  Serial.println(dato_int);
  ledcWriteChannel(0, dato_int);
}