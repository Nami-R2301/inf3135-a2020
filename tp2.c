#include "tcv.h"
#include "malib.h"

int main(void) {

  struct identification_s id = {0, "00", 9999, '2'};

  printf("\nVersion #: 0.1.10005\n");
  scanf("%zu %s %zu %hhu", &id.timestamp, id.event, &id.id, &id.puissanceEmetteur);

  if (evenementId(id.timestamp, id.event, id.id, id.puissanceEmetteur)) {
    sortieDix(id.timestamp, id.id, id.puissanceEmetteur);
  } else {
      return -1;
    }

  return 0;
}
