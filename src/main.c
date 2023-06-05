#include "coption.h"
#include <stdio.h>

int main(void) {

  Coption op = coption_create(sizeof(int));

  coption_somify(&op, COCONST(99));

  printf("%d\n", *(int *)coption_unwrap(&op));

  return 0;
}

