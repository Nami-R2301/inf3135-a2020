#include "malib.h"

int main(void) {

  int ligne = 0;
  bool valideId = false;
  bool valideTempH = false;
  bool valideTempA = false;
  bool validePpm = false;
  bool valideSignal = false;
  bool valideData = false;
  char input[100];
  temp_t courant;
  user_t mainId = {0, "00", 9999, 2};
  tempH_t tempH = {0, "01", 35.0, 0, 0, 0};
  tempA_t tempA = {0, "02", 0.0, 0, 0, 0};
  ppm_t ppm = {0, "03", 0, 0, 0, 0};
  signal_t signal = {0, "04", 0, 0, 0};
  echange_t echange = {0, "05", 0, 0};
  char tempTab[] = "";
  *courant.argQuatre = tempTab;
  version_t v = {0, 1, 1000};
  getVersion(&v);
  printf("Version #: %hhu.%hhu.%u\n", v.major, v.minor, v.build);

  do {

    fgets(input, 100, stdin); //pour utiliser sscanf()
    ligne = sscanf(input, "%zu %s %s %s", &courant.timestamp, courant.event, courant.argTrois, *courant.argQuatre); //pour qu'on puissent recevoir moins d'entrees (numLigne).

    if(!valideId && ligne == 4 && strcmp(courant.event, mainId.event) == 0) {

      mainId.timestamp = courant.timestamp;
      mainId.id = (size_t) strtoul(courant.argTrois, NULL, 0);
      mainId.puissanceEmetteur = (unsigned) atoi(*courant.argQuatre);
      valideId = sortieDix(10, mainId.timestamp, mainId.id, mainId.puissanceEmetteur);
    }

    if(valideId && !valideTempH && !valideTempA && !validePpm && !valideSignal && ligne == 3 && courant.timestamp >= mainId.timestamp && strcmp(courant.event, tempH.event) == 0) {

      if(strcmp(courant.argTrois, ERREUR) != 0) {

        tempH.timestamp = courant.timestamp;
        tempH.degrees = (float) atof(courant.argTrois);
        valideTempH = tempHumaine(tempH.timestamp, tempH.degrees, v.build);

        if(!valideTempH) {
          tempH.compteurInvalide++;
        }
      } else {
          tempH.cumul++;
      }
      tempH.compteur++;
    }

    if(valideTempH && !valideTempA && !validePpm && !valideSignal && ligne == 3 && courant.timestamp >= tempH.timestamp && strcmp(courant.event, tempA.event) == 0) {

      if(strcmp(courant.argTrois, ERREUR) != 0) {

        tempA.timestamp = courant.timestamp;
        tempA.degrees = (float) atof(courant.argTrois);
        valideTempA = tempAmbiante(tempA.timestamp, tempA.degrees, v.build);

        if(!valideTempA) {
          tempA.compteurInvalide++;
        }
      } else {
          tempA.cumul++;
        }
      tempA.compteur++;
    }

    if(valideTempA && !validePpm && !valideSignal && ligne == 3 && courant.timestamp >= tempA.timestamp && strcmp(courant.event, ppm.event) == 0) {

      if(strcmp(courant.argTrois, ERREUR) != 0) {

        ppm.timestamp = courant.timestamp;
        ppm.ppm = (unsigned) atoi(courant.argTrois);
        validePpm = pulsationMin(ppm.timestamp, ppm.ppm, v.build);

        if(!valideTempH) {
          ppm.compteurInvalide++;
        }
      } else {
          ppm.cumul++;
        }
      ppm.compteur++;
    }

    if(validePpm && !valideSignal && ligne == 4 && courant.timestamp >= ppm.timestamp && strcmp(courant.event, signal.event) == 0) {

      signal.timestamp = courant.timestamp;
      signal.power = (signed short) atoi(courant.argTrois);
      signal.id = (size_t) strtoul(*courant.argQuatre, NULL, 0);
      valideSignal = signalRssi(signal.timestamp, signal.power, signal.id, v.build);

      if(valideSignal) {
        compteurIdpn++;
      }
    }

    if(valideSignal && ligne == 4 && courant.timestamp >= signal.timestamp && strcmp(courant.event, echange.event) == 0) {

      echange.timestamp = courant.timestamp;
      echange.id = (size_t) strtoul(courant.argTrois, NULL, 0);
      echange.idpn = (size_t) strtoul(*courant.argQuatre, NULL, 0);
      valideData = echangeData(echange.timestamp, echange.id, echange.idpn);
    }

  } while(ligne != -1 && !valideData);
  //sortieVingtUn();
  //sortieVingtDeux();
  //sortieVingtTrois();
  return 0;
}
