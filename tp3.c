#include "malib.h"

int main() {

  int ligne = 0;
  transactions_t *transactions = initStructs();
  temp_t courant = initCourant();
  unsigned int build = initVersion();
  char *input =  malloc(sizeof(courant));

  while(ligne != -1 && fgets(input, sizeof(temp_t), stdin) != NULL) {

    ligne = sscanf(input, "%zu %s %s %s", &courant.timestamp, courant.event, courant.argTrois, courant.argQuatre);

    if(ligne == 4 && courant.timestamp >= transactions->mainId->timestamp && strcmp(courant.event, "00") == 0) {
      sortieDix(transactions->mainId, courant);
    }
    if(ligne == 3 && courant.timestamp >= transactions->mainId->timestamp&& strcmp(courant.event, "01") == 0) {
      tempHumaine(transactions->tempH, courant, build);
    }
    if(ligne == 3 && courant.timestamp >= transactions->tempH->timestamp&& strcmp(courant.event, "02") == 0) {
      tempAmbiante(transactions->tempA, courant, build);
   }
    if(ligne == 3 && courant.timestamp >= transactions->tempA->timestamp&& strcmp(courant.event, "03") == 0) {
      pulsationMin(transactions->ppm, courant, build);
    }
    if(ligne == 4 && courant.timestamp >= transactions->ppm->timestamp&& strcmp(courant.event, "04") == 0) {
      sortieQuatorze(transactions, courant, build);
    }
    if(ligne == 4 && courant.timestamp >= transactions->signal->timestamp&& strcmp(courant.event, "05") == 0) {
      sortieQuinze(transactions, courant, build);
    }
  }
  sortiesFin(transactions);
  free(input);
  free(courant.argTrois);
  free(courant.argQuatre);
  viderTransactions(transactions);
  return 0;
}
