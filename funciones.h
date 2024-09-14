//Cambia Estado Salida
void toggle_salida();


// Lee temperatura Soldador la devuelve as INT
int leer_temperatura();
//Mostrar Monitor Serie Datos Recibidos BLE
void mostrar_temperatura();
//Cambia Condiciones de Conexion y Muestra Estado Conexion
void toggleconexion(bool conexion, bool desconexion, String estado_conexion);
//Si es binario devuelve True
bool esCodigoBinario(const String& cadena);
// Si recibe String
void regular_PWM(int intensidad);
// lee devuelve temperatura
//Si no es binario es String
void regular_temperatura_ble();