#include "coption.h"
#include <stdio.h>

int main(void) {
  Coption op = coption_create(sizeof(double));
  coption_somify(&op, ECOCONST(99.0, double));
  coption_free(&op);
  return 0;
}
