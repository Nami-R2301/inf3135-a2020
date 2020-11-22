#ifndef MALIB_H
#define MALIB_H
#define ERREUR "ERREUR"

#include "tcv.h"
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

typedef struct identification_s {

  size_t timestamp;
  char event[3];
  size_t id;
  unsigned char puissanceEmetteur;

} user_t;

typedef struct temp_s {

  size_t timestamp;
  char event[3];
  char argTrois[50];
  char *argQuatre[];

} temp_t;

typedef struct tempHumaine_s {

  size_t timestamp;
  char event[3];
  float degrees;
  size_t compteur;
  size_t cumul;

} tempH_t;

typedef struct tempAmbiante_s {

  size_t timestamp;
  char event[3];
  float degrees;
  size_t compteur;
  size_t cumul;

} tempA_t;

typedef struct ppm_s {

  size_t timestamp;
  char event[3];
  unsigned int ppm;
  size_t compteur;
  size_t cumul;

} ppm_t;

typedef struct signalRSSI_s {

  size_t timestamp;
  char event[3];
  signed short power;
  size_t id;

} signal_t;

typedef struct echangeDonnees_s {

  size_t timestamp;
  char event[3];
  size_t id;

} echange_t;

//**************************ENTREES******************************************

bool tempHumaine(size_t timestamp, char event[], float degrees);

bool tempAmbiante(size_t timestamp, char event[], float degrees);

bool pulsationMin(size_t timestamp, char event[], float ppm);

bool signalRssi(size_t timestamp, char event[], signed short power, size_t id);

bool echangeData(size_t timestamp, char event[], size_t id);


//**************************SORTIES******************************************

bool sortieDix(unsigned int transaction, size_t timestamp, size_t id, unsigned char puissanceEmetteur); 

void sortieQuatorze(unsigned int transaction, size_t timestamp, size_t id, float distance);

void sortieQuinze(unsigned int transaction, size_t timestamp, size_t id);

void sortieVingtUn(unsigned int transaction, float avgTh, float avgTa, size_t avgPpm);

void sortieVingtDeux(unsigned int transaction, size_t compteurTh, size_t compteurTa, size_t compteurPpm);

void sortieVingtTrois(unsigned int transaction, size_t cumulTh, size_t cumulTa, size_t cumulPpm);


#endif
