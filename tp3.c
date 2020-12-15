#include "malib.h"
#include "outil3.h"

int main(int argc, char *argv[]) {

  int ligne = 0;
  transactions_t *trs = initStructs();
  temp_t* courant = initCourant();
  char input[sizeof(transactions_t)] = "";
  trs->optionT = cmd(argc, argv);
  float (*distance)(int, int) = distanceMetres;
  long prevTime = -1;
  printf("Version #: %hhu.%hhu.%u\n", courant->v->major, courant->v->minor, courant->v->build);

  while(fgets(input, sizeof(temp_t), stdin) != NULL && strcmp(input, "\n") != 0) {

    ligne = sscanf(input, "%zu %s %s %s", &courant->timestamp, courant->event, courant->argTrois, courant->argQuatre);

    if(ligne >= 3 && prevTime < (long) courant->timestamp) {
      prevTime = (long) courant->timestamp;
      if(ligne == 4 && strcmp(courant->event, EVENT0) == 0) sortieDix(trs, courant);
      else if(ligne == 3 && strcmp(courant->event, EVENT1) == 0) tempHumaine(trs, courant);
      else if(ligne == 3 && strcmp(courant->event, EVENT2) == 0) tempAmbiante(trs, courant);
      else if(ligne == 3 && strcmp(courant->event, EVENT3) == 0) pulsationMin(trs, courant);
      else if(ligne == 4 && strcmp(courant->event, EVENT4) == 0) sortieQuatorze(trs, courant, distance);
      else if(strcmp(courant->event, EVENT5) == 0) sortieQuinze(trs, courant);
      else {
        prevTime = -1;
        courant->trsInconnu++;
      }
    } else courant->timeInvalide++;
  }
  sortiesFin(trs);
  printOptions(trs->optionT, trs, courant);
  vider(trs, courant);
  return 0;
}
