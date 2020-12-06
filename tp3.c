#include "malib.h"

int main() {

  int ligne = 0;
  user_t *mainId = (user_t*) malloc(sizeof(user_t));
  tempH_t *tempH = (tempH_t*) malloc(sizeof(tempH_t));
  tempA_t *tempA = (tempA_t*) malloc(sizeof(tempA_t));
  ppm_t *ppm = (ppm_t*) malloc(sizeof(ppm_t));
  signal_t *signal = (signal_t*) malloc(sizeof(signal_t));
  echange_t *echange = (echange_t*) malloc(sizeof(echange_t));
  temp_t courant = initCourant();
  unsigned int build = initVersion();
  char *input =  malloc(sizeof(courant));

  while(ligne != -1 && fgets(input, sizeof(temp_t), stdin) != NULL) {

    ligne = sscanf(input, "%zu %s %s %s", &courant.timestamp, courant.event, courant.argTrois, courant.argQuatre); //pour qu'on puissent recevoir moins d'entrees (numLigne).

    if(ligne == 4 && courant.timestamp >= mainId->timestamp && strcmp(courant.event, "00") == 0) {
      sortieDix(mainId, courant);
    }
    if(ligne == 3 && courant.timestamp >= mainId->timestamp && strcmp(courant.event, "01") == 0) {
      tempHumaine(tempH, courant, build);
    }
    if(ligne == 3 && courant.timestamp >= tempH->timestamp && strcmp(courant.event, "02") == 0) {
      tempAmbiante(tempA, courant, build);
    }
    if(ligne == 3 && courant.timestamp >= tempA->timestamp && strcmp(courant.event, "03") == 0) {
      pulsationMin(ppm, courant, build);
    }
    if(ligne == 4 && courant.timestamp >= ppm->timestamp && strcmp(courant.event, "04") == 0) {
      sortieQuatorze(signal, courant, mainId, build);
    }
    if(ligne == 4 && courant.timestamp >= signal->timestamp && strcmp(courant.event, "05") == 0) {
//      sortieQuinze(echange, courant, mainId, signal->id[0], build);
    }
  }
    sortieVingtUn(*tempH, *tempA, *ppm);
    sortieVingtDeux(tempH->compteurInvalide, tempA->compteurInvalide, ppm->compteurInvalide);
    sortieVingtTrois(tempH->compteurError, tempA->compteurError, ppm->compteurError);
    free(input);
    vider(mainId, tempH, tempA, ppm, signal, echange);
    return 0;
}
