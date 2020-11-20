#include "malib.h"

bool evenementTempH(size_t timestamp, char event[], float degrees) {

  if (strcmp(event, "01") == 0) {

  } else {
      return false;
    }
  return true;
}

//bool tempAmbiante(size_t timestamp, const evenement, float|ERREUR degree);


//bool pulsationMin(size_t timestamp, const evenement, float|ERREUR ppm);


//bool signalRSSI(size_t timestamp, const evenement, signed short puissanceSignal, size_t id);


//bool echangeDonnees(size_t timestamp, const evenement, size_t id, size_t[size_t] idPN);


//************************************SORTIES*******************************************************

bool sortieDix(unsigned int transaction, size_t timestamp, size_t id, unsigned char puissanceEmetteur) {

  if (strcmp(event, "00") == 0) {

    if(id == 0) {
      id = 9999;
    }

    if (puissanceEmetteur > 4 || puissanceEmetteur < 2 || sizeof(puissanceEmetteur) != 1) {
      puissanceEmetteur = 2;
    }
    printf("%d %zu %zu %hhu\n", transaction, timestamp, id, puissanceEmetteur);
  } else {
      return false;
    }
  return true
}

void sortieQuatorze(unsigned int transaction, size_t timestamp, size_t id, float distanceMetres) {

  printf("%u %zu %zu %f\n", transaction, timestamp, id, distanceMetres);

}

//void sortieQuinze(unsigned int transaction, size_t timestamp, size_t id, size_t[size_t] idPN) {

//  unsigned int transaction = 15;
//  printf("%u %zu %zu %zu\n", transaction, timestamp, id, idPN);

//}

void sortieVingtEtUn(unsigned int transaction, float avgTh, float avgTa, size_t avgPpm) {

  printf("%u %f %f %zu\n", transaction, avgTh, avgTa, avgPpm);

}

void sortieVingtDeux(unsigned int transaction, size_t compteurTh, size_t compteurTa, size_t compteurPpm) {

  printf("%u %zu %zu %zu\n", transaction, compteurTh, compteurTa, compteurPpm);

}

void sortieVingtTrois(unsigned int transaction, size_t cumulTh, size_t cumulTa, size_t cumulPpm) {

  printf("%u %zu %zu %zu\n", transaction, cumulTh, cumulTa, cumulPpm);

}

