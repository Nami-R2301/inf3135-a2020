#define ERREUR 0.0

#include "stdbool.h"

extern typedef struct identification_s {

  size_t timestamp;
  const unsigned int event = 00;
  size_t id = 9999;
  unsigned char puissanceEmetteur = 2;

} identification_t;

extern typedef struct tempHumaine_s {

  size_t timestamp;
  const unsigned int event = 01;
  float degrees;

} tempH_t;

extern typedef struct tempAmbiante_s {

  size_t timestamp;
  const unsigned int event = 02;
  float degrees;

} tempA_t;

extern typedef struct ppm_s {

  size_t timestamp;
  const unsigned int event = 03;
  float ppm;

} ppm_t;

extern typedef struct signalRSSI_s {

  size_t timestamp;
  const unsigned int event = 04;
  signed short power;
  size_t id;

} signal_t;

extern typedef struct echangeDonnees_s {

  size_t timestamp;
  const unsigned int event = 05;
  size_t id;
 
bool sortieDix(size_t timestamp, size_t id, unsigned char puissanceEmetteur); 


bool sortieQuatorze(size_t timestamp, const char* evenement, float|ERREUR degree);


bool sortieQunize(size_t timestamp, const char* evenement, float|ERREUR degree);


bool sortieVingtUn(size_t timestamp, const char* evenement, float|ERREUR ppm);


bool sortieVingtDeux(size_t timestamp, const char* evenement, signed short puissanceSignal, size_t id);


bool sortieVingtTrois(size_t timestamp, const char*evenement, size_t id, size_t[size_t] idPN);


