#include "malib.h"

int main() {

  int ligne = 0;
  user_t mainId = {0, "00", 9999, 2};
  tempH_t tempH = {0, "01", 0.0, 0, 0, 0, 0};
  tempA_t tempA = {0, "02", 0.0, 0, 0, 0, 0};
  ppm_t ppm = {0, "03", 0.0, 0, 0, 0, 0};
  signal_t signal = {0, "04", 0, 0};
  echange_t echange = {0, "05", 0, 0};
  temp_t courant = {0, "00", ""};
  char input[100];

  version_t v;
  getVersion(&v);
  printf("Version #: %hhu.%hhu.%u\n", v.major, v.minor, v.build);

    while(!feof(stdin) && ligne != -1 && fgets(input, 100, stdin) != NULL) {

      ligne = sscanf(input, "%zu %s %s %s", &courant.timestamp, courant.event, courant.argTrois, courant.argQuatre); //pour qu'on puissent recevoir moins d'entrees (numLigne).

      if(ligne == 4 && strcmp(courant.event, mainId.event) == 0) {

        mainId.timestamp = courant.timestamp;
        mainId.id = (size_t) strtoul(courant.argTrois, NULL, 0);
        mainId.puissanceEmetteur = (unsigned) atoi(courant.argQuatre);
        sortieDix(10, mainId.timestamp, mainId.id, mainId.puissanceEmetteur);

        if(mainId.puissanceEmetteur == 0) {
          mainId.puissanceEmetteur = 2;
        }
        if(mainId.id == 0) {
          mainId.id = 9999;
        }
      }

      if(ligne == 3 && courant.timestamp > mainId.timestamp && strcmp(courant.event, tempH.event) == 0) {

        if(strcmp(courant.argTrois, ERREUR) != 0) {

          tempH.timestamp = courant.timestamp;
          tempH.degrees += (float) atof(courant.argTrois);

          if(tempHumaine(tempH.timestamp, tempH.degrees, v.build)) {
            tempH.compteur++;
          } else {
              tempH.compteurInvalide++;
            }
        } else {
            tempH.cumul++;

            if (tempH.cumul % 3 == 0) {
              tempH.compteurError++;
            }
          }
      }

      if(ligne == 3 && courant.timestamp > tempH.timestamp && strcmp(courant.event, tempA.event) == 0) {

        if(strcmp(courant.argTrois, ERREUR) != 0) {

          tempA.timestamp = courant.timestamp;
          tempA.degrees += (float) atof(courant.argTrois);

          if(tempAmbiante(tempA.timestamp, tempA.degrees, v.build)) {
            tempA.compteur++;
          } else {
              tempA.compteurInvalide++;
            }
        } else {
            tempA.cumul++;

            if (tempA.cumul % 3 == 0) {
              tempA.compteurError++;
            }
          }
      }

      if(ligne == 3 && courant.timestamp > tempA.timestamp && strcmp(courant.event, ppm.event) == 0) {

        if(strcmp(courant.argTrois, ERREUR) != 0) {

          ppm.timestamp = courant.timestamp;
          ppm.ppm += atof(courant.argTrois);

          if(pulsationMin(ppm.timestamp, ppm.ppm, v.build)) {
            ppm.compteur++;
          } else {
              ppm.compteurInvalide++;
            }
        } else {
            ppm.cumul++;

            if (ppm.cumul % 3 == 0) {
              ppm.compteurError++;
            }
          }
      }

      if(ligne == 4 && courant.timestamp > ppm.timestamp && strcmp(courant.event, signal.event) == 0) {

        signal.timestamp = courant.timestamp;
        signal.power = (signed short) atoi(courant.argTrois);
        signal.id[signal.compteurId] = (size_t) strtoul(courant.argQuatre, NULL, 0);

        if(signalRssi(signal.timestamp, signal.power, signal.id[signal.compteurId], v.build)) {
          signal.compteurId++;
        }
        sortieQuatorze(14, signal.timestamp, signal.id[signal.compteurId], signal.power, mainId);
        signal.compteurId++;
      }

      if(ligne == 4 && courant.timestamp > signal.timestamp && strcmp(courant.event, echange.event) == 0) {

        echange.timestamp = courant.timestamp;
        echange.id = (size_t) strtoul(courant.argTrois, NULL, 0);
        echange.idPn = (size_t) strtoul(courant.argQuatre, NULL, 0);
//      echangeData(echange.timestamp, echange.id, *echange.idpn);
      }

    }
      sortieVingtUn(21, tempH, tempA, ppm);
      sortieVingtDeux(22, tempH.compteurInvalide, tempA.compteurInvalide, ppm.compteurInvalide);
      sortieVingtTrois(23, tempH.compteurError, tempA.compteurError, ppm.compteurError);
      return 0;
}
