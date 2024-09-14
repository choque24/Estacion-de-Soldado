#include "var_const.h"
#include "funciones.h"
void setup() {
  Serial.begin(115200);
  Serial.println("      SENSOR DE TEMPERATURA MAX6675 CON ARDUINO     ");
  Serial.println("                  Choque, Mella Soria               ");
  //Pines
  pinMode(soldador, OUTPUT);
  pinMode(ledbuilt, OUTPUT);
  // Bluetooth Low Energy
  ble.begin("Calisto");
  ble.setTimeout(10);
  //PWM
  ledcAttachChannel(LED, 10000, 8, 0);
  ledcWriteChannel(0, 0);
  // Bucles
  // cambio_salida.attach(2, toggle_salida);
  lectura_soldador.attach(0.5, leer_temperatura);
  muestra_soldador.attach(1, mostrar_temperatura);
}

void loop() {

  if (temperatura_int > dato_int) {
    salida = LOW;
    digitalWrite(soldador, salida);
    digitalWrite(ledbuilt, salida);
  } else {
    salida = HIGH;
    digitalWrite(soldador, salida);
    digitalWrite(ledbuilt, salida);
  }

  if (ble.connected()) {                                               //Si esta conectado BLE
    if (condicion_conexion) toggleconexion(LOW, HIGH, "Establecida");  //Ocurre la primera vez
    bool dato = recibir_ble();
    if (dato) regular_temperatura_ble();
  } else {                                                               // Si esta desconectado BLE
    if (condicion_desconexion) toggleconexion(HIGH, LOW, "Finalizada");  //Ocurre la primera vez
  }
}
