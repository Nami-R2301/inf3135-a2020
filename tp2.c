#include "tcv.h"
#include "malib.h"

int main(void) {

  struct identification_s id = {0, "00", 9999, '2'};

  printf("\nVersion #: 0.1.10005\n");
  scanf("%zu %s %zu %hhu", &id.timestamp, id.event, &id.id, &id.puissanceEmetteur);

  evenementId(id.timestamp, id.event, id.id, id.puissanceEmetteur);
  return 0;
}
