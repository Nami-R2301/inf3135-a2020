#include "malib.h"

transactions_t* initStructs() {

  transactions_t *transactions = (transactions_t*) malloc(sizeof(transactions_t));
  transactions->mainId = (user_t*) malloc(sizeof(user_t));
  transactions->tempH = (tempH_t*) malloc(sizeof(tempH_t));
  transactions->tempA = (tempA_t*) malloc(sizeof(tempA_t));
  transactions->ppm = (ppm_t*) malloc(sizeof(ppm_t));
  transactions->signal = (signal_t*) malloc(sizeof(signal_t));
  transactions->echange = (echange_t*) malloc(sizeof(echange_t));
  return transactions;
}

temp_t initCourant() {

  temp_t courant;
  courant.argTrois = malloc(sizeof(char));
  courant.argQuatre = malloc(sizeof(char));
  return courant;
}

unsigned int initVersion() {

  version_t v;
  getVersion(&v);
  printf("Version #: %hhu.%hhu.%u\n", v.major, v.minor, v.build);
  return v.build;
}

bool tempHumaine(tempH_t* tempH, temp_t courant, unsigned char build) {

  tempH->degrees = (float) strtod(courant.argTrois, NULL);

  if(build <= 1003 || build <= 1008) {
    return validerTH_1((unsigned int)(tempH->degrees * 10));
  }
  return false;
}

bool tempAmbiante(tempA_t* tempA, temp_t courant, unsigned char build) {

  tempA->degrees = (float) strtod(courant.argTrois, NULL);

  if(build <= 1003) {
    return validerTA_3((signed short) (tempA->degrees * 10));
  } else if(build <= 1008) {
      return validerTA_1((signed int) (tempA->degrees * 10));
    }
  return false;
}

bool pulsationMin(ppm_t* ppm, temp_t courant, unsigned char build) {

  ppm->ppm = (signed short) strtol(courant.argTrois, NULL, 0);

  if(build <= 1003) {
    return validerPulsation_3((unsigned short) ppm->ppm);
  } else if(build <= 1008) {
      return validerPulsation_1((unsigned int) (ppm->ppm * 10));
    }
  return false;
}

bool signalRssi(size_t timestamp, signed short power, size_t id, unsigned char build) {

  if(build <= 1003) {
    return validerSignal_2((signed) power);
  } else if (build <= 1008) {
      return validerSignal_3(power);
    }
  return false;
}

bool echangeData(size_t timestamp, size_t id, size_t Idpn) {

  return true;
}


//************************************SORTIES*******************************************************

void sortieDix(user_t* mainId, temp_t courant) {

  mainId->timestamp = courant.timestamp;
  mainId->id = (size_t) strtoul(courant.argTrois, NULL, 0);
  mainId->puissanceEmetteur = (unsigned) strtol(courant.argQuatre, NULL, 0);

  if(mainId->id == 0) {
    mainId->id = 9999;
  }

  if ( mainId->puissanceEmetteur > 4 || mainId->puissanceEmetteur < 2) {
    mainId->puissanceEmetteur = 2;
  }
  printf("%d %zu %zu %hhu\n", 10, mainId->timestamp, mainId->id, mainId->puissanceEmetteur);
}

void sortieQuatorze(transactions_t *transactions, temp_t courant, unsigned char build) {

  transactions->signal->timestamp = courant.timestamp;
  transactions->signal->power = (short) *courant.argTrois;
  transactions->signal->id[0] = (unsigned char) *courant.argQuatre;
  signalRssi(transactions->signal->timestamp, transactions->signal->power, transactions->signal->id[0], build);
  float distanceMetres = (float) pow(10, (-69 - (float) transactions->signal->power) / (float) (10 * transactions->mainId->puissanceEmetteur));
  printf("%u %zu %zu %0.1f\n", 14, transactions->signal->timestamp, transactions->signal->id[0], distanceMetres);
  transactions->signal->compteurId++;
}

//void sortieQuinze(transactions_t *transactions, temp_t courant, unsigned char build) {

//  echange->timestamp = courant.timestamp;
//  echange->id = (size_t) strtoul(courant.argTrois, NULL, 0);
//  echange->idPn = (size_t) strtoul(courant.argQuatre, NULL, 0);
//  echangeData(echange->timestamp, echange->id, echange->idPn);
//  printf("%u %zu %zu %zu\n", 15, echange->timestamp, mainId->id, echange->idPn);

//}

void sortiesFin(transactions_t *transactions) {

  if(transactions->tempH->compteur != 0) {
    transactions->tempH->degrees = transactions->tempH->degrees / transactions->tempH->compteur;

  } else if(transactions->tempA->compteur != 0) {
      transactions->tempH->degrees = 0.0f;
      transactions->tempA->degrees = transactions->tempA->degrees / transactions->tempA->compteur;

    } else if(transactions->ppm->compteur != 0) {
        transactions->tempA->degrees = 0.0f;
        transactions->tempH->degrees = 0.0f;
        transactions->ppm->ppm = transactions->ppm->ppm / transactions->ppm->compteur;

      } else {
          transactions->tempA->degrees = 0.0f;
          transactions->tempH->degrees = 0.0f;
          transactions->ppm->ppm = 0.0f;
        }
  printf("%u %.1f %.1f %zu\n", 21, transactions->tempH->degrees, transactions->tempA->degrees, (size_t) transactions->ppm->ppm);
  printf("%u %zu %zu %zu\n", 22, transactions->tempH->compteur, transactions->tempA->compteur, transactions->ppm->compteur);
  printf("%u %zu %zu %zu\n", 23, transactions->tempH->cumul, transactions->tempA->cumul, transactions->ppm->cumul);
}

void viderTransactions(transactions_t *transactions) {

  free(transactions->mainId);
  free(transactions->tempH);
  free(transactions->tempA);
  free(transactions->ppm);
  free(transactions->signal);
  free(transactions->echange);
  free(transactions);
}
