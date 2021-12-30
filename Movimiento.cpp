#include "Movimiento.h"

void  Movimiento::addMovimiento(Articulacion art, int posI, int posF)
{
  this->art = art;
  this->posI = posI;
  this->posF = posF;
}
// señal para mover el dispositivo
void Movimiento::execute()
{
  art.mover(posI, posF);
}
