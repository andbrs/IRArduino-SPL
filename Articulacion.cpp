#include "Articulacion.h"

void Articulacion::initServo(String Motor_tag_, int pin)
{
  // Aquí se declaro un objeto servo como una abstracción de la Articulación y se adjunta al pin
  S1.attach(pin);
  this->Motor_type = "SERVO";
  // //Especifica la etiqueta del servo
}
void Articulacion::initDC(String Motor_tag_, int pin1, int pin2) {
  //configurar a dc motor
  /*
    //por ejemplo, digamos que una de los pines conectados en alto
  */
  this->Motor_type = "DC";

}
void Articulacion::mover( int posI, int posF)
{
  if (Motor_type == "SERVO") {
    S1.write(posI);  // Yendo a posición inicial
    delay(500); // espera un tiempo
    S1.write(posF);  // Va de posición inicial a final
    delay(500); // espera un tiempo
  }
  else if (Motor_type == "DC") {
    // codigo para motor
  }
}
