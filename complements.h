/*
    Si necesita añadir otra clase de sensor
    tienes que especificar lo siguiente:
    variables privadas a las que se asignan los pines de los sensores 
     en la placa Arduino
    Función para init este pin y configurar este pin
    Función para leer los datos del sensor
*/

class PIR {

  public:

    void init(unsigned int pin_) {
      pin = pin_;
      pinMode(pin, INPUT);   //,make this pin as input
    }
    bool readmotion() {
      unsigned int  state = digitalRead(pin);   // read the pin state
      if (state == HIGH) {            // if motion detected
        return true;
      }
      else {  //if no motion detected
        return false;
      }
    }
  private:
    unsigned int pin;
};


class Infrarrojo {

  public:

    void init(unsigned int pin_) {
      pin = pin_;
      pinMode(pin, INPUT);   //,make this pin as input
    }
    bool readmotion() {
      unsigned int  state = digitalRead(pin);   // read the pin state
      if (state == HIGH) {            // if motion detected
        return true;
      }
      else {  //if no motion detected
        return false;
      }
    }
  private:
    unsigned int pin;
};


class Generico {

  public:

    void init(unsigned int pin_) {
      pin = pin_;
      pinMode(pin, INPUT);   //,make this pin as input
    }
    bool readmotion() {
      unsigned int  state = digitalRead(pin);   // read the pin state
      if (state == HIGH) {            // if motion detected
        return true;
      }
      else {  //if no motion detected
        return false;
      }
    }
  private:
    unsigned int pin;
};


class HCSR04 {

  private:
    unsigned int out;  //define pins
    unsigned int echo;


  public:

    void init(int out, int echo) {
      this->out = out;
      this->echo = echo;
      pinMode(this->out, OUTPUT); // comfigure pins
      pinMode(this->echo, INPUT);
    }


    ///////////////////////////////////////////////////dist
    float dist()
    {
      // read distance using measuring distance algorthim of ultrasonic sensor
      digitalWrite(this->out, LOW);
      delayMicroseconds(2);
      digitalWrite(this->out, HIGH);
      delayMicroseconds(10);
      digitalWrite(this->out, LOW);
      noInterrupts();
      float d = pulseIn(this->echo, HIGH);
      interrupts();
      return d / 58.0;
    }
};
