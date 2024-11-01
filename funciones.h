// CREACION FUNCIONES
#include "Arduino.h"

void actualizar_lcd() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("temperatura_actual: ");
  lcd.print(temperatura_actual);
  lcd.setCursor(0, 1);

};






void toggle_salida() {  //Cambia Estado Salida
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  Serial.println("Led BUILTIN " + digitalRead(LED_BUILTIN) ? "Encendido" : "Apagado");  //
}
void leer_temperatura() {                          // Lee temperatura Soldador la devuelve as INT
  temperatura_float = thermocouple.readCelsius();  // LEER EL TERMOPAR Y ALMACENAR EL VALOR EN UNA VARIABLE
  temperatura_actual = int(temperatura_float);
}
void enviar_ble() {
  int i = 0;
  i++;
  if (i % 2 == 0) ble.print("Temperatura: ");  //esto da el resto
  else ble.println(temperatura_actual);
}
void mostrar_temperatura() {  //Mostrar Monitor Serie Datos Recibidos BLE
  Serial.print("Temperatura: ");
  Serial.print(temperatura_actual);
  Serial.println(" C°");
}
void controlar_temperatura() {
  salida = temperatura_actual < dato_ble_int;
  digitalWrite(SOLDADOR_PIN, salida);
  digitalWrite(LED_BUILTIN, salida);
}
void toggleconexion(bool conectado) {  //Cambia Condiciones de Conexion y Muestra Estado Conexion
  if (conectado != estado_anterior_conexion) {
    Serial.println("Conexión Bluetooth " + String(conectado ? "Establecida" : "Finalizada"));
    Serial.println("-------------------------------");
  }
  estado_anterior_conexion = conectado;
}
bool esCodigoBinario(const String& cadena) {  //Si es binario devuelve True
  for (char c : cadena) {
    if (c != '0' && c != '1') {
      return false;
    }
  }
  return true;
}
void regular_PWM(int intensidad) {
  ledcWriteChannel(0, intensidad);
}
void regular_temperatura_ble() {  // lee devuelve temperatura
  if (!ble.available()) return;   //Si no hay datos sale
  dato_ble = ble.readString();
  dato_ble.trim();
  if (!esCodigoBinario(dato_ble)) {                       //Si no es binario es String
    Serial.println("Dato Recibido String: " + dato_ble);  //
    auto it = casosPWM.find(dato_ble);
    if (it != casosPWM.end()) {  // Si se encuentra el comando, establecer la intensidad correspondiente
      regular_PWM(it->second);
      return;
    }
    Serial.println("Que mandas campo");
    return;
  }
  dato_ble_int = strtol(dato_ble.c_str(), NULL, 2);
  Serial.print("Dato Recibido Entero: ");
  Serial.println(dato_ble_int);
}