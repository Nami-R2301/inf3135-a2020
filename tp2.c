#include "malib.h"

int main(void) {

  int ligne = 0;
  bool valideId = false;
  bool valideTempH = false;
//  bool valideTempA = false;
//  bool validePpm = false;
  version_t v = {0, 1, 1000};
  getVersion(&v);
  printf("Version #: %hhu.%hhu.%u\n", v.major, v.minor, v.build);
  do {

    char input[100];
    struct identification_s mainId = {0, "00", 9999, 2};
    struct temp_s courant;
    struct tempHumaine_s tempH = {0, "01", 0.0, 0, 0};
//    struct tempAmbiante_s tempA = {tempH.timestamp, "02", 20.0};

    fgets(input, 100, stdin);
    ligne = sscanf(input, "%zu %s %s %s", &courant.timestamp, courant.event, courant.argTrois, courant.argQuatre);

    if(!valideId && ligne == 4 && strcmp(courant.event, mainId.event) == 0) {

      mainId.timestamp = courant.timestamp;
      mainId.id = (size_t) strtoul(courant.argTrois, NULL, 0);
      mainId.puissanceEmetteur = (unsigned) atoi(courant.argQuatre);
      valideId = sortieDix(10, mainId.timestamp, mainId.id, mainId.puissanceEmetteur);
    }

    if(valideId && ligne == 3 && strcmp(courant.event, tempH.event) == 0) {

      if(strcmp(courant.argTrois, ERREUR) != 0) {

        tempH.timestamp = courant.timestamp;
        tempH.degrees = (float) round(atof(courant.argTrois));
        printf("%lf\n\n", tempH.degrees);
        valideTempH = evenementTempH(tempH.timestamp, tempH.event, tempH.degrees);

        if(!valideTempH) {
          tempH.compteur++;
        }
      } else {
          tempH.cumul++;
      }
    }

//    if(valideId && valideTempH && !valideTempA) {

//      ligne = scanf("%zu %s %.1f", &tempA.timestamp, tempA.event, &tempA.degrees);
//      valideTempA = evenementTempA(tempA.timestamp, tempA.event, tempA.degrees);
//    }

//    if(

  } while(!valideTempH);

//sortieVingtUn();
//sortieVingtDeux();
//sortieVingtTrois();
  return 0;
}
