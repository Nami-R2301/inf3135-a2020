//
// Created by Nami on 2020-12-05.
//

#ifndef _MALIB_H
#define _MALIB_H
#define ERREUR "ERREUR"
#define EVENT0 "00"
#define EVENT1 "01"
#define EVENT2 "02"
#define EVENT3 "03"
#define EVENT4 "04"
#define EVENT5 "05"

#include "tcv.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

typedef struct identification_s {

  size_t id;
  unsigned char puissanceEmetteur;

} user_t;

typedef struct temp_s {

  size_t timestamp;
  char event[3];
  char *argTrois;
  char *argQuatre;
  version_t *v;
  size_t trsInconnu;
  size_t timeInvalide;

} temp_t;

typedef struct tempHumaine_s {

  float degrees;
  size_t compteurInvalide;
  size_t compteur;
  size_t cumul;
  size_t compteurTrsUn;

} tempH_t;

typedef struct tempAmbiante_s {

  float degrees;
  size_t compteurInvalide;
  size_t compteur;
  size_t cumul;
  size_t compteurTrsDeux;

} tempA_t;

typedef struct ppm_s {

  float ppm;
  size_t compteurInvalide;
  size_t compteur;
  size_t cumul;
  size_t compteurTrsTrois;

} ppm_t;

typedef struct signalRSSI_s {

  signed short power;
  size_t compteurId;
  size_t id[sizeof(size_t)];
  size_t compteurTrsQuatre;

} signal_t;

typedef struct echangeDonnees_s {

  size_t idPn;
  size_t compteurTrsCinq;
  size_t compteurValide;

} echange_t;

typedef struct transactions_s {

  user_t *mainId;
  tempH_t *tempH;
  tempA_t *tempA;
  ppm_t *ppm;
  signal_t *signal;
  echange_t *echange;
  int optionT;
  size_t compteurTrs;
  size_t compteurTrsValide;

} transactions_t;

//**************************INITIALISATION-STRUCTS**************************************

transactions_t* initStructs();

temp_t* initCourant();

//**************************VALIDATION-ENTREES******************************************

void tempHumaine(transactions_t*, temp_t*);

void tempAmbiante(transactions_t*, temp_t*);

void pulsationMin(transactions_t*, temp_t*);

//**************************SORTIES*****************************************************

void sortieDix(transactions_t*, temp_t*);

void sortieQuatorze(transactions_t*, temp_t*, float (*distance)(int, int));

void sortieQuinze(transactions_t*, temp_t*);

void sortiesFin(transactions_t*);

void vider(transactions_t*, temp_t*);

#endif //_MALIB_H

