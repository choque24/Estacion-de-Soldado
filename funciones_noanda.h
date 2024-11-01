#include "Arduino.h"

// Cambia el estado del LED integrado
void toggle_salida();

// Lee la temperatura del termopar y la envía por BLE
int leer_temperatura();

// Manda Temperatura por Ble a la Aplicacion
void enviar_ble();

//Muestra la temperatura actual por el puerto serie
void mostrar_temperatura();

// Actualiza y muestra el estado de la conexión Bluetooth
void toggleconexion();

// Verifica si una cadena es un código binario válido
bool esCodigoBinario(const String& cadena);

// Regula canal PWM
void regular_PWM(int intensidad);

// lee, cambia temperatura
void regular_temperatura_ble();

// Controla la temperatura del soldador
void controlar_temperatura();