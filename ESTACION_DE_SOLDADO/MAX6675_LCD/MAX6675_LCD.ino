
 


#include "LiquidCrystal.h"
#include "max6675.h"
 
// CONFIGURACION DE LOS PINES UTILIZADOS PARA LA COMUNICACIÓN CON EL MAX6675

#define CONFIG_TCSCK_PIN      10  // SPI SCK
#define CONFIG_TCCS_PIN       9  // SPI CS
#define CONFIG_TCDO_PIN       8  // SPI SO
 
// CONSTRUCTOR PARA LA PANTALLA LCD 16X2
// AQUI SE CONFIGURAN LOS PINES PARA LA COMUNICACION CON LA PANTALLA
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
// OBJETO UTILIZADO PARA LA COMUNICACION CON EL MAX6675
MAX6675 thermocouple(CONFIG_TCSCK_PIN, CONFIG_TCCS_PIN, CONFIG_TCDO_PIN);
 
void setup() {
  // PREPARAR LA INTERFAZ SERIAL
  Serial.begin(9600);
 
  // IMPRIMR MENSAJE INICIAL A LA TERMINAL
  Serial.println(F("----------------------------------------------------"));
  Serial.println(F("      SENSOR DE TEMPERATURA MAX6675 CON ARDUINO     "));
  Serial.println(F("                  ELECTROMAN YOUTUBE                "));
  Serial.println(F("----------------------------------------------------"));
 

 
  // INDICAMOS QUE TENEMOS CONECTADA UNA PANTALLA DE 16X2
  // IMPRIMIR MENSAJE INICIAL EN PANTALLA
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print(F("TERMOPAR ARDUINO"));
  lcd.setCursor( 0, 1 );
  lcd.print(F("  CON MAX6675   "));
 
  // ESPERAR UN SEGUNDO
  delay(1000);
}
 
void loop() {
  // LEER EL TERMOPAR Y ALMACENAR EL VALOR EN UNA VARIABLE
  double t = thermocouple.readCelsius();
 
  // PRIMERO LIMPIAMOS LA PANTALLA Y LUEGO IMPRIMIMOS LA TEMPERATURA
  lcd.clear();
  lcd.print(F("->TEMPERATURA<-"));
  lcd.setCursor( 3, 1 );
  lcd.print(t);
 
  // IMPRIMIR LA TEMPERATURA EN LA TERMINAL SERIAL
  Serial.print("ªC = ");
  Serial.println(t);
 
  // ESPERAR UN SEGUNDO ENTRE LAS LECTURAS
  delay(1000);
}
