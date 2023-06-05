#include "coption.h"
#include <stdio.h>

int main(void) {
  Coption op = coption_create(sizeof(float));
  coption_somify(&op, COCONST(99.f));
  coption_free(&op);
  return 0;
}
