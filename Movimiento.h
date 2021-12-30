#include "Articulacion.h"

class Movimiento
{
  private:
    Articulacion art;
    int posI = 0;
    int posF = 0;

  public:

    void addMovimiento(Articulacion art, int posI, int posF);
    void execute();
};
