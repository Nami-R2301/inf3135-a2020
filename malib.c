#include "malib.h"

bool tempHumaine(size_t timestamp, float degrees, unsigned char build) {

  if(build <= 1003 || build <= 1008) {
    return validerTH_1((unsigned int)(degrees * 10));
  }
  return false;
}

bool tempAmbiante(size_t timestamp, float degrees, unsigned char build) {

  if(build <= 1003) {
    return validerTA_3((signed short) (degrees * 10));
  } else if(build <= 1008) {
      return validerTA_1((signed int) (degrees * 10));
    }
  return false;
}

bool pulsationMin(size_t timestamp, float ppm, unsigned char build) {

  if(build <= 1003) {
    return validerPulsation_3((unsigned short) ppm);
  } else if(build <= 1008) {
      return validerPulsation_1((unsigned int) (ppm * 10));
    }
  return false;
}

bool signalRssi(size_t timestamp, signed short power, size_t id, unsigned char build) {

  if(build <= 1003) {
    return validerSignal_2((signed) power);
  } else if (build <= 1008) {
      return validerSignal_3(power);
    }
  return false;
}

bool echangeData(size_t timestamp, size_t id, size_t Idpn) {

  return true;
}


//************************************SORTIES*******************************************************

bool sortieDix(unsigned int transaction, user_t* mainId, temp_t courant) {

  mainId->timestamp = courant.timestamp;
  mainId->id = (size_t) strtoul(courant.argTrois, NULL, 0);
  mainId->puissanceEmetteur = (unsigned) atoi(courant.argQuatre);
  if(mainId->id == 0) {
    mainId->id = 9999;
  }

  if ( mainId->puissanceEmetteur > 4 || mainId->puissanceEmetteur < 2) {
    mainId->puissanceEmetteur = 2;
  }
  printf("%d %zu %zu %hhu\n", transaction, mainId->timestamp, mainId->id, mainId->puissanceEmetteur);
  return true;
}

void sortieQuatorze(unsigned int transaction, size_t timestamp, size_t id, signed short power, user_t mainId) {

  float distanceMetres = pow(10, (-69 - (float) power) / (10 * mainId.puissanceEmetteur));

  printf("%u %zu %zu %0.1f\n", transaction, timestamp, id, distanceMetres);

}

//void sortieQuinze(unsigned int transaction, size_t timestamp, size_t id, size_t[size_t] idPN) {

//  unsigned int transaction = 15;
//  printf("%u %zu %zu %zu\n", transaction, timestamp, id, *idPN);

//}

void sortieVingtUn(unsigned int transaction, tempH_t tempH, tempA_t tempA, ppm_t ppm) {

  if(tempH.compteur != 0) {
    tempH.degrees = tempH.degrees / tempH.compteur;

  } else if(tempA.compteur != 0) {
      tempH.degrees = 0.0;
      tempA.degrees = tempA.degrees / tempA.compteur;

   } else if(ppm.compteur != 0) {
        tempA.degrees = 0.0;
        tempH.degrees = 0.0;
        ppm.ppm = ppm.ppm / ppm.compteur;

      } else {
          tempA.degrees = 0.0;
          tempH.degrees = 0.0;
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

