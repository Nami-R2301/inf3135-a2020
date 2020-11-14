#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "tcv.h"

int main(void) {

  version_t *v = {};
  getVersion(v);
  char ligne[30];

  printf("\n\n\nHello World\n\n\n");
  scanf("%s", ligne);
  printf("%s\n\n", ligne);
  return 0;
}
