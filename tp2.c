#include "malib.h"

int main(void) {

  version_t v = {0, 1, 1000};
  getVersion(&v);
  printf("Version #: %hhu.%hhu.%u\n", v.major, v.minor, v.build);
  struct identification_s id = {0, "00", 9999, 2};
  int ligne = scanf("%zu %s %zu %hhu", &id.timestamp, id.event, &id.id, &id.puissanceEmetteur);

  if (ligne == 4 && !feof(stdin)) {

    evenementId(id.timestamp, id.event, id.id, id.puissanceEmetteur);
    printf("%s\n", id.event);
  }

/**  do {

    struct tempHumaine_s tempH = {id.timestamp, "01", 36.9};

    bool valideTempH = false;
    bool valideTempA = false;
    bool validePpm = false;
    size_t tempTime = 0;
    char tempEvent[3];
    float tempDegrees = 0.0;
    ligne = scanf( "%zu %s %f", &tempTime, tempEvent, &tempDegrees);

    if(ligne == 3 && !valideTempH && strcmp(tempEvent, "01") == 0) {
      valideId = evenementTempH();
    }

  } while(!valideTempH && !valideTempA && !validePpm && !feof(stdin));
*/
  return 0;
}
