#include "var_const.h"
#include "funciones.h"
void setup() {
  Serial.begin(115200);
  Serial.println("      Estacion de Soldado comunicacion BLE Calisto  ");
  Serial.println("                  Choque, Mella Soria               ");
  //Pines
  pinMode(SOLDADOR_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  // Bluetooth Low Energy
  ble.begin("Calisto");
  ble.setTimeout(10);
  //PWM
  ledcAttachChannel(LED_PIN, 10000, 8, 0);
  ledcWriteChannel(0, 0);
  // Bucles
  // cambio_salida.attach(2, toggle_salida);
  lectura_soldador.attach(0.5, leer_temperatura);
  muestra_soldador.attach(1, mostrar_temperatura);
  envio_ble.attach(1, enviar_ble);
  cambio_conexion.attach(1, toggleconexion, ble.connected());
}

void loop() {
  controlar_temperatura();

  if (ble.connected()) {  //Si esta conectado BLE
    regular_temperatura_ble();
  }
}
