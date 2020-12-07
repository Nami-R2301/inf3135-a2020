#ifndef MALIB_H
#define MALIB_H
#define ERREUR "ERREUR"

#include "tcv.h"
#include <stdlib.h>
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
  char *argTrois;
  char *argQuatre;

} temp_t;

typedef struct tempHumaine_s {

  size_t timestamp;
  char event[3];
  float degrees;
  size_t compteurInvalide;
  size_t compteur;
  size_t cumul;
  size_t compteurError;

} tempH_t;

typedef struct tempAmbiante_s {

  size_t timestamp;
  char event[3];
  float degrees;
  size_t compteurInvalide;
  size_t compteur;
  size_t cumul;
  size_t compteurError;

} tempA_t;

typedef struct ppm_s {

  size_t timestamp;
  char event[3];
  float ppm;
  size_t compteurInvalide;
  size_t compteur;
  size_t cumul;
  size_t compteurError;

} ppm_t;

typedef struct signalRSSI_s {

  size_t timestamp;
  char event[3];
  signed short power;
  size_t compteurId;
  size_t id[];

} signal_t;

typedef struct echangeDonnees_s {

  size_t timestamp;
  char event[3];
  size_t id;
  size_t idPn;

} echange_t;

typedef struct transactions_s {

    user_t *mainId;
    tempH_t *tempH;
    tempA_t *tempA;
    ppm_t *ppm;
    signal_t *signal;
    echange_t *echange;

} transactions_t;

//**************************ENTREES******************************************

transactions_t* initStructs();

temp_t initCourant();

unsigned int initVersion();

bool tempHumaine(tempH_t*, temp_t, unsigned char);

bool tempAmbiante(tempA_t*, temp_t, unsigned char);

bool pulsationMin(ppm_t*, temp_t, unsigned char);

bool signalRssi(size_t, signed short, size_t, unsigned char);

bool echangeData(size_t, size_t, size_t);

//**************************SORTIES******************************************

void sortieDix(user_t*, temp_t);

void sortieQuatorze(transactions_t*, temp_t, unsigned char);

void sortieQuinze(transactions_t*, temp_t, unsigned char);

void sortiesFin(transactions_t*);

void viderTransactions(transactions_t*);

#endif
