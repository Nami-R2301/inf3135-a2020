#include "malib.h"

transactions_t* initStructs() {

  transactions_t *trs = (transactions_t*) malloc(sizeof(transactions_t));
  trs->mainId = (user_t*) malloc(sizeof(user_t));
  trs->tempH = (tempH_t*) malloc(sizeof(tempH_t));
  trs->tempA = (tempA_t*) malloc(sizeof(tempA_t));
  trs->ppm = (ppm_t*) malloc(sizeof(ppm_t));
  trs->signal = (signal_t*) malloc(sizeof(signal_t));
  trs->echange = (echange_t*) malloc(sizeof(echange_t));
  *trs->mainId = (user_t) {9999, 2};
  *trs->tempH = (tempH_t) {0, 0, 0, 0};
  *trs->tempA = (tempA_t) {0, 0, 0, 0};
  *trs->ppm = (ppm_t) {0, 0, 0, 0};
  *trs->signal = (signal_t) {0,0};
  *trs->echange = (echange_t) {0};
  trs->optionT = 0;
  return trs;
}

temp_t* initCourant() {

  temp_t* courant = (temp_t*) malloc(sizeof(temp_t));
  courant->argTrois = (char*) malloc(sizeof(size_t));
  courant->argQuatre = (char*) malloc(sizeof(size_t));
  courant->v = (version_t*) malloc(sizeof(version_t));
  getVersion(courant->v);
  return courant;
}

void tempHumaine(tempH_t* tempH, temp_t* courant) {

  if(strcmp(courant->argTrois, ERREUR) != 0) {

      if(courant->v->build <= 1008) {

        if(validerTH_1((int) (strtod(courant->argTrois, NULL) * 10))) {
          tempH->compteur++;
          tempH->degrees += (float) strtod(courant->argTrois, NULL);

        } else tempH->compteurInvalide++;
      }
  } else tempH->cumul++;
}

void tempAmbiante(tempA_t* tempA, temp_t* courant) {

  if(strcmp(courant->argTrois, ERREUR) != 0) {

      bool valide = false;
      if(courant->v->build <= 1003) valide = validerTA_3((short) (strtod(courant->argTrois, NULL) * 10));
      else if(courant->v->build <= 1008) valide = validerTA_1((int) (strtod(courant->argTrois, NULL) * 10));

      if(valide) {
        tempA->compteur++;
        tempA->degrees += (float) strtod(courant->argTrois, NULL);

      } else tempA->compteurInvalide++;
  } else tempA->cumul++;
}

void pulsationMin(ppm_t* ppm, temp_t* courant) {

  if(strcmp(courant->argTrois, ERREUR) != 0) {

      bool valide = false;
      if(courant->v->build <= 1003) valide = validerPulsation_3((short) strtol(courant->argTrois, NULL, 0));
      else if(courant->v->build <= 1008) valide = validerPulsation_1((int) strtol(courant->argTrois, NULL, 0));

      if(valide) {
        ppm->ppm = (short) strtol(courant->argTrois, NULL, 0);
        ppm->compteur++;

      } else ppm->compteurInvalide++;
  } else ppm->cumul++;
}

void sortieDix(transactions_t* trs, temp_t* courant) {

  if((size_t) strtoul(courant->argTrois, NULL, 0) != 0) trs->mainId->id = (size_t) strtoul(courant->argTrois, NULL, 0);

  if(strtol(courant->argQuatre, NULL, 0) <= 4 && strtol(courant->argQuatre, NULL, 0) >= 2) {
    trs->mainId->puissanceEmetteur = (unsigned) strtol(courant->argQuatre, NULL, 0);
  }
  if(trs->optionT > 0) {
    printf("%d %zu %zu %hhu\n", 10, courant->timestamp, trs->mainId->id, trs->mainId->puissanceEmetteur);
  }
}

void sortieQuatorze(transactions_t *trs, temp_t* courant) {

  bool valide = false;

  if(trs->mainId->id != strtoul(courant->argQuatre, NULL, 0) && courant->v->build <= 1003) {
    valide = validerSignal_2((signed char) strtol(courant->argTrois, NULL, 0));
  } else if (trs->mainId->id != strtoul(courant->argQuatre, NULL, 0)  && courant->v->build <= 1008) {
      valide = validerSignal_3((signed short) strtol(courant->argTrois, NULL, 0));
  }

  if(valide) {
    trs->signal->power = (short) strtol(courant->argTrois, NULL, 0);
    trs->signal->id[trs->signal->compteurId] = (size_t) strtoul(courant->argQuatre, NULL, 0);
    trs->signal->compteurId++;

    if(trs->optionT > 0) {
      printf("%u %zu %zu", 14, courant->timestamp, trs->signal->id[trs->signal->compteurId]);
    }
  }
}

void sortieQuinze(transactions_t *trs, temp_t* courant) {

  if(trs->signal->compteurId != 0 && trs->optionT > 0) {
    printf("%u %zu %zu ", 15, courant->timestamp, trs->mainId->id);

    for(int i = 0; i < trs->signal->compteurId; i++) {
      if(trs->signal->id[i] != trs->mainId->id) {
        trs->echange->idPn = trs->signal->id[i];
        printf("%zu ", trs->echange->idPn);
      }
    }
    printf("\n");
  }
}

void sortiesFin(transactions_t *trs) {

  float resultatH = (float) trs->tempH->compteur;
  float resultatA = (float) trs->tempA->compteur;
  float resultatPpm = (float) trs->ppm->compteur;

  if(resultatH != 0.0f) resultatH = trs->tempH->degrees / trs->tempH->compteur;
  if(resultatA != 0.0f) resultatA = trs->tempA->degrees / trs->tempA->compteur;
  if(resultatPpm != 0.0f) resultatPpm = trs->ppm->ppm = trs->ppm->ppm / trs->ppm->compteur;

  if(trs->optionT > 0) {
    printf("%u %.1f %.1f %zu\n", 21, resultatH, resultatA, (size_t) resultatPpm);
    printf("%u %zu %zu %zu\n", 22, trs->tempH->compteurInvalide, trs->tempA->compteurInvalide, trs->ppm->compteurInvalide);
    printf("%u %zu %zu %zu\n", 23, trs->tempH->cumul / 3, trs->tempA->cumul / 3, trs->ppm->cumul / 3);
  }
}

void vider(transactions_t *trs, temp_t* courant) {

  free(courant->v);
  free(courant->argQuatre);
  free(courant->argTrois);
  free(courant);
  free(trs->echange);
  free(trs->signal);
  free(trs->ppm);
  free(trs->tempA);
  free(trs->tempH);
  free(trs->mainId);
  free(trs);
}
