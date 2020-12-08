#include "malib.h"

transactions_t* initStructs() {

  transactions_t *transactions = (transactions_t*) malloc(sizeof(transactions_t));
  transactions->mainId = (user_t*) malloc(sizeof(user_t));
  transactions->tempH = (tempH_t*) malloc(sizeof(tempH_t));
  transactions->tempA = (tempA_t*) malloc(sizeof(tempA_t));
  transactions->ppm = (ppm_t*) malloc(sizeof(ppm_t));
  transactions->signal = (signal_t*) malloc(sizeof(signal_t));
  transactions->echange = (echange_t*) malloc(sizeof(echange_t));
  *transactions->mainId = (user_t){00, 9999, 3};
  *transactions->tempH = (tempH_t) {00, 0.0f, 0, 0, 0};
  *transactions->tempA = (tempA_t) {00, 0.0f, 0, 0, 0};
  *transactions->ppm = (ppm_t) {00, 0.0f, 0, 0, 0};
  *transactions->signal = (signal_t) {00, 0, 0};
  *transactions->echange = (echange_t) {00, 0, 0};
  return transactions;
}

temp_t initCourant() {

  temp_t courant = {00, ""};
  courant.argTrois = malloc(sizeof(size_t));
  courant.argQuatre = malloc(sizeof(size_t));
  *courant.argTrois = 'N';
  *courant.argQuatre = 'N';
  return courant;
}

unsigned int initVersion() {

  version_t v;
  getVersion(&v);
  printf("Version #: %hhu.%hhu.%u\n", v.major, v.minor, v.build);
  return v.build;
}

void tempHumaine(tempH_t* tempH, temp_t courant, unsigned int build) {

  if(strcmp(courant.argTrois, ERREUR) != 0) {
    tempH->timestamp = courant.timestamp;

    if(build <= 1008) {
      if(validerTH_1((int) strtol(courant.argTrois, NULL, 0) * 10)) {
        tempH->compteur++;
        tempH->degrees += (float) strtod(courant.argTrois, NULL);
      } else {
          tempH->compteurInvalide++;
      }
    }
  } else {
      tempH->cumul++;
  }
}

void tempAmbiante(tempA_t* tempA, temp_t courant, unsigned int build) {

  if(strcmp(courant.argTrois, ERREUR) != 0) {
    bool valide = false;
    tempA->timestamp = courant.timestamp;

    if(build <= 1003) {
      valide = validerTA_3((short) strtol(courant.argTrois, NULL, 0) * 10);
    } else if(build <= 1008) {
        valide = validerTA_1((int) strtol(courant.argTrois, NULL, 0) * 10);
    }
    if(valide) {
      tempA->compteur++;
      tempA->degrees += (float) strtod(courant.argTrois, NULL);
    } else {
        tempA->compteurInvalide++;
    }
  } else {
      tempA->cumul++;
  }
}

void pulsationMin(ppm_t* ppm, temp_t courant, unsigned int build) {

  if(strcmp(courant.argTrois, ERREUR) != 0) {
    bool valide = false;

    if(build <= 1003) {
      valide = validerPulsation_3((short) strtol(courant.argTrois, NULL, 0));
    } else if(build <= 1008) {
        valide = validerPulsation_1((int) strtol(courant.argTrois, NULL, 0));
    }
    if(valide) {
      ppm->ppm = (short) strtol(courant.argTrois, NULL, 0);
      ppm->compteur++;
    } else {
        ppm->compteurInvalide++;
    }
  } else {
      ppm->cumul++;
  }
}

void sortieDix(user_t* mainId, temp_t courant) {

  if((size_t) strtoul(courant.argTrois, NULL, 0) != 0 && (unsigned) strtol(courant.argQuatre, NULL, 0) < 4 && (unsigned) strtol(courant.argQuatre, NULL, 0) > 2) {
      mainId->timestamp = courant.timestamp;
      mainId->id = (size_t) strtoul(courant.argTrois, NULL, 0);
      mainId->puissanceEmetteur = (unsigned) strtol(courant.argQuatre, NULL, 0);
  }
  printf("%d %zu %zu %hhu\n", 10, mainId->timestamp, mainId->id, mainId->puissanceEmetteur);
}

void sortieQuatorze(transactions_t *transactions, temp_t courant, unsigned int build) {

  float distanceMetres = 0.0f;
  bool valide = false;
  transactions->signal->timestamp = courant.timestamp;
  transactions->signal->id[transactions->signal->compteurId] = (size_t) strtoul(courant.argQuatre, NULL, 0);
  if(build <= 1003) {
    valide = validerSignal_2((signed char) strtol(courant.argTrois, NULL, 0));
  } else if (build <= 1008) {
      valide = validerSignal_3((signed short) strtol(courant.argTrois, NULL, 0));
  }
  if(valide) {
    transactions->signal->power = (short) strtol(courant.argTrois, NULL, 0);
    distanceMetres = (float) pow(10, (-69 - (float) transactions->signal->power) / (float) (10 * transactions->mainId->puissanceEmetteur));
    printf("%u %zu %zu %0.1f\n", 14, transactions->signal->timestamp, transactions->signal->id[transactions->signal->compteurId], distanceMetres);
    transactions->signal->compteurId++;
  }
}

void sortieQuinze(transactions_t *transactions, temp_t courant) {

  transactions->echange->timestamp = courant.timestamp;
  printf("%u %zu %zu ", 15, transactions->echange->timestamp, transactions->mainId->id);
  for( int i = 0; i < transactions->signal->compteurId; i++) {
    transactions->echange->idPn = transactions->signal->id[i];
    printf("%zu ", transactions->echange->idPn);
  }
  printf("\n");
}

void sortiesFin(transactions_t *transactions) {

  float resultatH = (float) transactions->tempH->compteur;
  float resultatA = (float) transactions->tempA->compteur;
  float resultatPpm = (float) transactions->ppm->compteur;

  if(resultatH != 0.0f) {
      resultatH = transactions->tempH->degrees / transactions->tempH->compteur;
  }
  if(resultatA != 0.0f) {
      resultatA = transactions->tempA->degrees / transactions->tempA->compteur;
  }
  if(resultatPpm != 0.0f) {
      resultatPpm = transactions->ppm->ppm = transactions->ppm->ppm / transactions->ppm->compteur;
  }
  printf("%u %.1f %.1f %zu\n", 21, resultatH, resultatA, (size_t) resultatPpm);
  printf("%u %zu %zu %zu\n", 22, transactions->tempH->compteurInvalide, transactions->tempA->compteurInvalide, transactions->ppm->compteurInvalide);
  printf("%u %zu %zu %zu\n", 23, transactions->tempH->cumul / 3, transactions->tempA->cumul / 3, transactions->ppm->cumul / 3);
}

void viderTransactions(transactions_t *transactions) {

  free(transactions->echange);
  free(transactions->signal->id);
  free(transactions->signal);
  free(transactions->ppm);
  free(transactions->tempA);
  free(transactions->tempH);
  free(transactions->mainId);
  free(transactions);
}
