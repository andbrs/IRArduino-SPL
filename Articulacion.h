#include <Arduino.h>
#include <Servo.h>
//delcaración de los metodos y variables
class Articulacion
{
  protected:
    String Motor_type;
    Servo S1;
    int posActual = 0;
    int pin;
    int pin1, pin2;
  public:
    void initServo(String Motor_tag_, int pin);
    void  initDC(String Motor_tag_, int pin1, int pin2);
    void mover( int posI, int posF) ;
};
