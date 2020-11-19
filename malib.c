#include <stdio.h>
#include <string.h>
#include <math.h>
#include "malib.h"

bool evenementId(size_t timestamp, unsigned int event, size_t id, unsigned char puissanceEmetteur) {

  if (id < 1) {
    id = 9999;
  }

  if (event != 00) {
    event = 00;
  }

  if (puissanceEmetteur > '4' || puissanceEmetteur < '2' || sizeof(puissanceEmetteur) != 1) {
    puissanceEmetteur = '2';
  }

  sortieDix(timestamp, id, puissanceEmetteur);

  return true;
}

//bool tempHumaine(size_t timestamp, const evenement, float|ERREUR degree);


//bool tempAmbiante(size_t timestamp, const evenement, float|ERREUR degree);


//bool pulsationMin(size_t timestamp, const evenement, float|ERREUR ppm);


//bool signalRSSI(size_t timestamp, const evenement, signed short puissanceSignal, size_t id);


//bool echangeDonnees(size_t timestamp, const evenement, size_t id, size_t[size_t] idPN);


//************************************SORTIES*******************************************************

void sortieDix(size_t timestamp, size_t id, unsigned char puissanceEmetteur) {

  int transaction = 10;
  printf("%d %zu %zu %c\n", transaction, timestamp, id, puissanceEmetteur);

}

//void sortieQuatorze(const transaction, size_t timestamp, size_t id, float distanceMetres);


//void sortieQuinze(const transaction, size_t timestamp, size_t id, size_t[size_t] idPN);


//int sortieVingtEtUn(const transaction, float avgTH, float avgTA, size_t avgPuls);


//int sortieVingtDeux(const transaction, size_t compteurTH, size_t compteurTA, size_t compteurPuls);


//int sortieVingtTrois(const transaction, size_t cumulTH, size_t cumulTA, size_t cumulPuls);

