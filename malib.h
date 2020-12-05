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
  char argTrois[50];
  char argQuatre[];

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

//**************************ENTREES******************************************

bool tempHumaine(size_t, float, unsigned char);

bool tempAmbiante(size_t, float, unsigned char);

bool pulsationMin(size_t, float, unsigned char);

bool signalRssi(size_t, signed short, size_t, unsigned char);

bool echangeData(size_t, size_t, size_t);


//**************************SORTIES******************************************

bool sortieDix(unsigned int, user_t*, temp_t); 

void sortieQuatorze(unsigned int, size_t, size_t, signed short, user_t);

void sortieQuinze(unsigned int, size_t, size_t, echange_t);

void sortieVingtUn(unsigned int, tempH_t, tempA_t, ppm_t);

void sortieVingtDeux(unsigned int, size_t, size_t, size_t);

void sortieVingtTrois(unsigned int, size_t, size_t, size_t);

#endif
