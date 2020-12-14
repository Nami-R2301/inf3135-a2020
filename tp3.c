#include "malib.h"
#include "outil3.h"

int main(int argc, char *argv[]) {

  int ligne = 0;
  transactions_t *trs = initStructs();
  temp_t* courant = initCourant();
  char *input =  malloc(sizeof(temp_t));
  trs->optionT = cmd(argc, argv);
  int prevTime = -1;
  printf("Version #: %hhu.%hhu.%u\n", courant->v->major, courant->v->minor, courant->v->build);

  while(ligne != -1 && fgets(input, sizeof(temp_t), stdin) != NULL) {

    ligne = sscanf(input, "%zu %s %s %s", &courant->timestamp, courant->event, courant->argTrois, courant->argQuatre);

    if(ligne != -1 && prevTime < (int) courant->timestamp) {
      prevTime = courant->timestamp;
      if(ligne == 4 && strcmp(courant->event, EVENT0) == 0) sortieDix(trs, courant);
      else if(ligne == 3 && strcmp(courant->event, EVENT1) == 0) tempHumaine(trs, courant);
      else if(ligne == 3 && strcmp(courant->event, EVENT2) == 0) tempAmbiante(trs, courant);
      else if(ligne == 3 && strcmp(courant->event, EVENT3) == 0) pulsationMin(trs, courant);
      else if(ligne == 4  && strcmp(courant->event, EVENT4) == 0) {
        sortieQuatorze(trs, courant);
        float (*distance)(int, int) = distanceMetres;
        float dist = (*distance)((int) trs->signal->power, (int) trs->mainId->puissanceEmetteur);
        if(dist != -1.0 && trs->optionT > 0) printf(" %0.1f\n", dist);

      } else if(ligne >= 3 && strcmp(courant->event, EVENT5) == 0) sortieQuinze(trs, courant);
        else prevTime = -1;
    }
  }
  sortiesFin(trs);
  free(input);
  printOptions(trs->optionT, trs);
  vider(trs, courant);
  return 0;
}
