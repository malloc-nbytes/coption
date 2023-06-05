#ifndef COPTION_H
#define COPTION_H


#include <stddef.h>

#define COSOME 1
#define CONONE 0

#define CO_COMPOUND_LITERAL(x) ((void *)&(typeof(x)){(x)})
#define CO_EXPLICIT_COMPOUND_LITERAL(x, type) ((void *)&(type){(x)})
#define COCONST(x) CO_COMPOUND_LITERAL(x)
#define ECOCONST(x, type) CO_EXPLICIT_COMPOUND_LITERAL(x, type)

typedef struct {
  void *data;
  size_t elem_size;
  int state;
} Coption;

Coption coption_create(size_t elem_size);
void coption_somify(Coption *op, void *data);
void coption_nonify(Coption *op);
int coption_is_some(Coption *op);
int coption_is_none(Coption *op);
void *coption_unwrap(Coption *op);
void *coption_unwrap_or(Coption *op, void *fallback);
void coption_free(Coption *op);

#endif // COPTION_H
