#include "outil3.h"

int cmd(int argc, char **argcv) {

  return 0;
}

float distanceMetres(int _signal, int _power) {

 return (float) pow(10, (-69 - (float) _signal) / (float) (10 * _power));
}
