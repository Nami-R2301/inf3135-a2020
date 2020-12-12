#include "outil3.h"

int cmd(int argc, char **argv) {

  bool infoInvalide = false;
  bool infoDetails = false;
  bool infoSomme = false;
  bool tranquille = false;
  int args = 0;
  if(argc != 1) {

    for(int i = 1; i < argc; ++i) {

      if(!infoInvalide && strcmp(argv[i], OPTION_I) == 0) infoInvalide = true;
      else if(!infoDetails && strcmp(argv[i], OPTION_D) == 0) infoDetails = true;
      else if(!infoSomme && strcmp(argv[i], OPTION_S) == 0) infoSomme = true;
      else if(!tranquille && strcmp(argv[i], OPTION_T) == 0) tranquille = true;
    }

    if(infoInvalide) args++;
    if(infoDetails) args += 5;
    if(infoSomme) args += 9;
    if(tranquille) args = (args * -1);
  } else {
      return 2;
    }
  return args;
}

void printOptions(int args, transactions_t* trs) {

  if(args != 0 && args != 2) {

    if(args < 0) args = (args * -1);

      if(args == 15 || args == 10 || args == 6 ||  args == 1) printf("information invalide\n");
      if(args == 15 || args == 14 || args == 6 || args == 5) printf("information detaillee\n");
      if(args == 15 || args == 14 || args == 10 || args == 9) printf("information sommaire\n");
  }
}

float distanceMetres(int _signal, int _power) {

  if(_signal <= -35 && _signal >= -85) return (float) pow(10, (-69 - (float) _signal) / (float) (10 * _power));
  else return -1.0f;
}
