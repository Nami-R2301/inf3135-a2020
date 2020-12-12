#include "outil3.h"

int cmd(int argc, char **argcv) {

  return 0;
}

float distanceMetres(int _signal, int _power) {

  if(_signal <= -35 && _signal >= -85) return (float) pow(10, (-69 - (float) _signal) / (float) (10 * _power));
  else return -1.0f;
}
