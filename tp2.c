#include "malib.h"

int main(void) {

  bool valideId = false;
  int ligne = 0;
  bool valideTempH = false;
//  bool valideTempA = false;
//  bool validePpm = false;
  version_t v = {0, 1, 1000};
  getVersion(&v);
  printf("Version #: %hhu.%hhu.%u\n", v.major, v.minor, v.build);
  do {

    struct invalideSim = {0, 0, 0};
    struct erreur_s erreurSim = {0, 0, 0};
    struct identification_s id = {0, "00", 9999, 2};
    struct tempHumaine_s tempH = {id.timestamp, "01", 36.9};

    if(!valideId) {
      ligne = scanf("%zu %s %zu %hhu", &id.timestamp, id.event, &id.id, &id.puissanceEmetteur);
      valideId = sortieDix(10, id.timestamp, id.id, id.puissanceEmetteur);
    }

    if(valideId && !valideTempH) {
      ligne = scanf("%zu %s %.1f", &tempH.timestamp, tempH.event, &tempH.degrees);
      valideTempH = evenementTempH(tempH.timestamp, tempH.event, tempH.degrees);
    }

  } while(!valideId && !valideTempH);
  return 0;
}
