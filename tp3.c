#include "malib.h"

int main() {

  int ligne = 0;
  transactions_t *transactions = initStructs();
  unsigned int build = initVersion();
  temp_t courant = initCourant();
  char *input =  malloc(sizeof(courant));
  int prevTime = -1;

  while(fgets(input, sizeof(temp_t), stdin) != NULL) {

    ligne = sscanf(input, "%zu %s %s %s", &courant.timestamp, courant.event, courant.argTrois, courant.argQuatre);
    if(ligne != -1 && prevTime < (signed int) courant.timestamp) {
      prevTime = courant.timestamp;
      if(strcmp(courant.event, EVENT0) == 0) {
        sortieDix(transactions->mainId, courant);
      } else if(ligne == 3 && strcmp(courant.event, EVENT1) == 0) {
          tempHumaine(transactions->tempH, courant, build);
      } else if(ligne == 3 && strcmp(courant.event, EVENT2) == 0) {
          tempAmbiante(transactions->tempA, courant, build);
      } else if(ligne == 3 && strcmp(courant.event, EVENT3) == 0) {
          pulsationMin(transactions->ppm, courant, build);
      } else if(ligne == 4 && strcmp(courant.event, EVENT4) == 0) {
          sortieQuatorze(transactions, courant, build);
      } else if(ligne == 4 && strcmp(courant.event, EVENT5) == 0) {
          sortieQuinze(transactions, courant);
      }
    }
  }
  sortiesFin(transactions);
  free(input);
  viderTransactions(transactions);
  return 0;
}
