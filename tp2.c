#ifndef MALIB_H
#include "malib.h"
#endif

int main(void) {

  struct identification_s id = {0, 00, 9999, '2'};
  printf("\nVersion #: 0.1.10005\n");
  int ligne = scanf("%zu %u %zu %c", &id.timestamp, &id.event, &id.id, &id.puissanceEmetteur);
  int valideId = evenementId(id.timestamp, id.event, id.id, id.puissanceEmetteur);

  while(ligne > 2 && valideId && !feof(stdin)) {

    ligne = scanf( "%zu %u %zu %1c", &id.timestamp, &id.event, &id.id, &id.puissanceEmetteur);

    if(ligne == 4) {
      valideId = evenementId(id.timestamp, id.event, id.id, id.puissanceEmetteur);
    }
  }

  return 0;
}
