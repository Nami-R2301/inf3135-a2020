#include "malib.h"

int main(void) {

  int ligne = 0;
  bool valideId = false;
//  bool valideTempH = false;
//  bool valideTempA = false;
//  bool validePpm = false;
  version_t v = {0, 1, 1000};
  getVersion(&v);
  printf("Version #: %hhu.%hhu.%u\n", v.major, v.minor, v.build);
  do {

    struct temp_s prev = {0, "00", "", ""};
    struct temp_s courant = {0, "No", "ID", "Power"};
//    struct tempHumaine_s tempH = {id.timestamp, "01", 0.0};
//    struct tempAmbiante_s tempA = {tempH.timestamp, "02", 20.0};

    ligne = scanf("%zu %s %s %s", &courant.argUn, courant.argDeux, courant.argTrois, courant.argQuatre);

    if(!valideId && ligne >= 2 && strcmp(courant.argDeux, "00") == 0 && prev.argUn >= courant.argUn) {

      valideId = sortieDix(10, courant.argUn, strtoul(courant.argTrois, NULL, 0), (unsigned) atoi(courant.argQuatre));
    }

//    if(prev.argUn >= ) {

//      ligne = scanf("%zu %s %.1f", &tempH.timestamp, tempH.event, &tempH.degrees);
//      valideTempH = evenementTempH(tempH.timestamp, tempH.event, tempH.degrees);
//    }

//    if(valideId && valideTempH && !valideTempA) {

//      ligne = scanf("%zu %s %.1f", &tempA.timestamp, tempA.event, &tempA.degrees);
//      valideTempA = evenementTempA(tempA.timestamp, tempA.event, tempA.degrees);
//    }

//    if(

    prev = courant;

  } while(!valideId && ligne != 0);
  return 0;
}
