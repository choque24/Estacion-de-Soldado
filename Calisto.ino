#include "var_const.h"
#include "funciones.h"
/*
Proyecto: Estacion de Soldado - Calisto
Finalidad Objetivos:  
  Regulador de temperatura de soldador.(entre 200 y 400)

Cosas que hace:
  Conexion mediante BLE a Aplicacion controladora
  Control de temperatura con botones en Hardware

Metas: Simplificar code, que ande todo, que sea entendible escalable, etc

Opiniones:
  Gian: 
  Jesus: Puede mejorar, Arregla mauricio 
  
Valoraciones: 
  Jesus: 10
  ING Mauricio: 10 estrellas es poco
 
Mejoras:
Faltantes:
  Hardware: 
  LCD, hardware, (on off), Posible implementacion potenciometro
  B4a: Correccion detalles apariencia, implemetancion paginas, Correccion fallas crasheo,( Modo avion, salir y volver a entrar).
Cosas que tiene que saber todos:
Que hace la Estacion
Porque la hacemos
Que conocimientos se utilizan
Proceso y Fabricación, Pasos
Componentes
BLE, 
App, que hace, como lo hace,( que usa,) en donde se hizo(lenguaje), como se usa(Celular, descargar app, dar permisos)

*/
void setup() {
  Serial.begin(115200);
  Serial.println("      Estacion de Soldado comunicacion BLE Calisto  ");
  Serial.println("                  Choque, Mella Soria               ");
  //Pines Salidas - Entradas
  pinMode(SOLDADOR_PIN, OUTPUT);  //Inicialización Entradas Salidas digitales
  pinMode(LED_BUILTIN, OUTPUT);
  // Bluetooth Low Energy
  ble.begin("Calisto");  //Inicialización Comunicación BLE Arduino
  ble.setTimeout(10);
  //PWM
  ledcAttachChannel(LED_PIN, 10000, 8, 0);
  ledcWriteChannel(0, 0);
  // Bucles
  cambio_salida.attach(2, toggle_salida);           //anda
  lectura_soldador.attach(0.5, leer_temperatura);   //anda
  muestra_soldador.attach(1, mostrar_temperatura);  //Anda
  envio_ble.attach(5, enviar_ble);                  //anda
  // cambio_conexion.attach(1, toggleconexion, ble.connected());  //anda
}

void loop() {
  toggleconexion(ble.connected());
  controlar_temperatura();
  

    if (ble.connected()) {  //Si esta conectado BLE
    regular_temperatura_ble();
  }
}