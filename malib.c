#include "malib.h"

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

void sortieQuatorze(signal_t* signal, temp_t courant, user_t* mainId, unsigned char build) {

  signal->timestamp = courant.timestamp;
  signal->power = (short) *courant.argTrois;
  signal->id[0] = (unsigned char) *courant.argQuatre;
  signalRssi(signal->timestamp, signal->power, signal->id[0], build);
  float distanceMetres = (float) pow(10, (-69 - (float) signal->power) / (float) (10 * mainId->puissanceEmetteur));
  printf("%u %zu %zu %0.1f\n", 14, signal->timestamp, signal->id[0], distanceMetres);
}

//void sortieQuinze(echange_t* echange, temp_t courant, user_t* mainId, size_t id, unsigned char build) {

//  unsigned int transaction = 15;
//  printf("%u %zu %zu %zu\n", transaction, timestamp, id, *idPN);
//  echange->timestamp = courant.timestamp;
//    echange->id = (size_t) strtoul(courant.argTrois, NULL, 0);
//    echange->idPn = (size_t) strtoul(courant.argQuatre, NULL, 0);
//    echangeData(echange->timestamp, echange->id, echange->idPn);
//    printf("%u %zu %zu %zu\n", 15, echange->timestamp, mainId->id, echange->idPn);

//}

void sortieVingtUn(tempH_t tempH, tempA_t tempA, ppm_t ppm) {

  if(tempH.compteur != 0) {
    tempH.degrees = tempH.degrees / tempH.compteur;

  } else if(tempA.compteur != 0) {
      tempH.degrees = 0.0;
      tempA.degrees = tempA.degrees / tempA.compteur;

   } else if(ppm.compteur != 0) {
        tempA.degrees = 0.0;
        tempH.degrees = 0.0;
        ppm.ppm = ppm.ppm / ppm.compteur;

      } else {
          tempA.degrees = 0.0;
          tempH.degrees = 0.0;
          ppm.ppm = 0.0;
        }
  printf("%u %.1f %.1f %zu\n", 21, tempH.degrees, tempA.degrees, (size_t) ppm.ppm);
}


void sortieVingtDeux(size_t compteurTh, size_t compteurTa, size_t compteurPpm) {

  printf("%u %zu %zu %zu\n", 22, compteurTh, compteurTa, compteurPpm);
}

void sortieVingtTrois(size_t cumulTh, size_t cumulTa, size_t cumulPpm) {

  printf("%u %zu %zu %zu\n", 23, cumulTh, cumulTa, cumulPpm);
}

void vider(user_t* mainId, tempH_t* tempH, tempA_t* tempA, ppm_t* ppm, signal_t* signal, echange_t* echange) {

  free(mainId);
  free(tempH);
  free(tempA);
  free(ppm);
  free(signal);
  free(echange);
}
