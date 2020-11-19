#ifndef MALIB_H
#define MALIB_H

#include "tcv.h"
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "stdbool.h"

struct identification_s {

  size_t timestamp;
  unsigned int event;
  size_t id;
  unsigned char puissanceEmetteur;

};

struct tempHumaine_s {

  size_t timestamp;
  unsigned int event;
  float degrees;
  size_t compteur;
  size_t cumul;

};

struct tempAmbiante_s {

  size_t timestamp;
  unsigned int event;
  float degrees;
  size_t compteur;
  size_t cumul;

};

struct ppm_s {

  size_t timestamp;
  unsigned int event;
  float ppm;
  size_t compteur;
  size_t cumul;

} ppm_t;

struct signalRSSI_s {

  size_t timestamp;
  unsigned int event;
  signed short powerSignal;
  size_t id;

} signal_t;

struct echangeDonnees_s {

  size_t timestamp;
  unsigned int event;
  size_t id;

} echange_t;

//**************************ENTREES******************************************

bool evenementId(size_t timestamp, unsigned int event, size_t id, unsigned char powerEmetteur);

bool evenementTempH(size_t timestamp, char event[], float degrees);

bool evenementTempA(size_t timestamp, char event[], float degrees);

bool evenementPpm(size_t timestamp, char event[], float ppm);

bool evenementSignal(size_t timestamp, char event[], signed short powerSignal);

bool evenementEchange(size_t timestamp, char event[], size_t id);


//**************************SORTIES******************************************

void sortieDix(size_t timestamp, size_t id, unsigned char puissanceEmetteur); 

void sortieQuatorze(size_t timestamp, size_t id, float distance);

void sortieQunize(size_t timestamp, size_t id);

void sortieVingtUn(float avgTh, float avgTa, size_t avgPpm);

void sortieVingtDeux(size_t compteurTh, size_t compteurTa, size_t compteurPpm);

bool sortieVingtTrois(size_t cumulTh, size_t cumulTa, size_t cumulPpm);


#endif
