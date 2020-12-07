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
  float degrees;
  size_t compteurInvalide;
  size_t compteur;
  size_t cumul;

} tempH_t;

typedef struct tempAmbiante_s {

  size_t timestamp;
  float degrees;
  size_t compteurInvalide;
  size_t compteur;
  size_t cumul;

} tempA_t;

typedef struct ppm_s {

  size_t timestamp;
  float ppm;
  size_t compteurInvalide;
  size_t compteur;
  size_t cumul;

} ppm_t;

typedef struct signalRSSI_s {

  size_t timestamp;
  signed short power;
  size_t compteurId;
  size_t id[sizeof(size_t)];

} signal_t;

typedef struct echangeDonnees_s {

  size_t timestamp;
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

//**************************INITIALISATION-STRUCTS**************************************

transactions_t* initStructs();

temp_t initCourant();

unsigned int initVersion();

//**************************VALIDATION-ENTREES******************************************

void tempHumaine(tempH_t*, temp_t, unsigned char);

void tempAmbiante(tempA_t*, temp_t, unsigned char);

void pulsationMin(ppm_t*, temp_t, unsigned char);

//**************************SORTIES*****************************************************

void sortieDix(user_t*, temp_t);

void sortieQuatorze(transactions_t*, temp_t, unsigned char);

void sortieQuinze(transactions_t*, temp_t, unsigned char);

void sortiesFin(transactions_t*);

void viderTransactions(transactions_t*);

#endif
