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
    if(!tranquille && !infoDetails && !infoSomme && !infoSomme) {
      return 3;
    }
  } else {
      return 2;
    }
  return args;
}

void printOptions(int args, transactions_t* trs, temp_t* courant) {

  if(args != 0 && args != 2) {

    if(args < 0) args = (args * -1);

      if((args == 15 || args == 10 || args == 6 ||  args == 1) && (courant->timeInvalide +  courant->trsInconnu) != 0) {
        printf("information invalide\n  trx non reconnue : %zu\n  trx avec ts non sequentiel : %zu\n", courant->trsInconnu, courant->timeInvalide);
      }
      if(args == 15 || args == 14 || args == 6 || args == 5) {
        printf("information detaillee\n  trx 00 : %zu\n  trx 01 : %zu\n  trx 02 : %zu\n  trx 03 : %zu\n  trx 04 : %zu\n  trx 05 : %zu\n  le dernier ts lu : %zu\n", trs->mainId->compteurTrs, trs->tempH->compteurTrs, trs->tempA->compteurTrs, trs->ppm->compteurTrs,
        trs->signal->compteurTrs, trs->echange->compteurTrs, courant->timestamp);
      }
      if(args == 15 || args == 14 || args == 10 || args == 9) {
        printf("information sommaire\n  nbr trx valides : %zu\n  nbr trx (total) : %zu\n", trs->compteurTrsValide, trs->compteurTrs);
      }
  }
}

float distanceMetres(int _signal, int _power) {

  if(_signal <= -35 && _signal >= -85) return (float) pow(10, (-69 - (float) _signal) / (float) (10 * _power));
  else return -1.0f;
}
