#include "malib.h"

void version(void);

void version(void) {
  version_t v = {0, 1, 1000};
  getVersion(&v);
}

bool tempHumaine(size_t timestamp, float degrees) {

  return true;
}

bool tempAmbiante(size_t timestamp, float degrees) {

  return true;
}

bool pulsationMin(size_t timestamp, float ppm) {

  return true;
}

bool signalRssi(size_t timestamp, signed short power, size_t id) {

  return true;
}

bool echangeData(size_t timestamp, size_t id, size_t Idpn) {

  return true;
}


//************************************SORTIES*******************************************************

bool sortieDix(unsigned int transaction, size_t timestamp, size_t id, unsigned char puissanceEmetteur) {

  if(id == 0) {
    id = 9999;
  }

  if ( puissanceEmetteur > 4 || puissanceEmetteur < 2) {
    puissanceEmetteur = 2;
  }
  printf("%d %zu %zu %hhu\n", transaction, timestamp, id, puissanceEmetteur);
  return true;
}

void sortieQuatorze(unsigned int transaction, size_t timestamp, size_t id, signal_t signal) {

//  printf("%u %zu %zu %f\n", transaction, timestamp, id, distanceMetres);

}

//void sortieQuinze(unsigned int transaction, size_t timestamp, size_t id, size_t[size_t] idPN) {

//  unsigned int transaction = 15;
//  printf("%u %zu %zu %zu\n", transaction, timestamp, id, idPN);

//}

void sortieVingtUn(unsigned int transaction, tempH_t tempH, tempA_t tempA, ppm_t ppm) {

  if(tempH.compteur != 0 && tempA.compteur != 0 && ppm.compteur != 0) {

    tempH.degrees = tempH.degrees / tempH.compteur;
    tempA.degrees = tempA.degrees / tempA.compteur;
    ppm.ppm = ppm.ppm / ppm.compteur;
  } else if(tempH.compteur == 0) {
      tempH.degrees = 0.0;
    } else if(tempA.compteur == 0) {
        tempA.degrees = 0.0;
      } else {
          ppm.ppm = 0.0;
        }
  printf("%u %.1f %.1f %zu\n", transaction, tempH.degrees, tempA.degrees, (size_t) ppm.ppm);
}


void sortieVingtDeux(unsigned int transaction, size_t compteurTh, size_t compteurTa, size_t compteurPpm) {

  printf("%u %zu %zu %zu\n", transaction, compteurTh, compteurTa, compteurPpm);

}

void sortieVingtTrois(unsigned int transaction, size_t cumulTh, size_t cumulTa, size_t cumulPpm) {

  printf("%u %zu %zu %zu\n", transaction, cumulTh, cumulTa, cumulPpm);

}

