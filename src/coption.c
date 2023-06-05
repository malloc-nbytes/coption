#include "coption.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COPANIC(msg, stream, ...)                                       \
  do {                                                                  \
    fprintf(stream, "PANIC [%s:%s:%d]: " msg "\n", __FILE__, __func__,  \
            __LINE__, ##__VA_ARGS__);                                   \
    exit(EXIT_FAILURE);                                                 \
  } while (0)

#define COTODO(stream)                                          \
  do {                                                          \
    fprintf(stream, "TODO [%s:%s:%d]", __FILE__, __func__,      \
            __LINE__);                                          \
    exit(EXIT_FAILURE);                                         \
  } while (0)


Coption coption_create(size_t elem_size) {
  Coption op;
  op.data = (void *)malloc(elem_size);
  if (!op.data) {
    COPANIC("failed to allocate %zu bytes", stderr, elem_size);
  }
  op.elem_size = elem_size;
  op.state = CONONE;
  return op;
}

void coption_somify(Coption *op, void *data) {
  memcpy(op->data, data, op->elem_size);
  op->state = COSOME;
}

void coption_nonify(Coption *op) {
  op->state = CONONE;
}

void *coption_unwrap(Coption *op) {
  if (op->state == CONONE) {
    COPANIC("called unwrap on None value", stderr);
  }
  return op->data;
}

int coption_is_some(Coption *op) {
  return op->state == COSOME;
}

int coption_is_none(Coption *op) {
  return op->state == CONONE;
}

void *coption_unwrap_or(Coption *op, void *fallback) {
  return op->state == COSOME ? op->data : fallback;
}

void coption_free(Coption *op) {
  free(op->data);
  op->state = CONONE;
}

