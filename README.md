# coption
A generic optional datatype.

## Functions

### `coption_create`
`Coption coption_create(size_t elem_size);`

Creates a `coption`. Provide it an element size.

Example:
```c
int main(void) {
  Coption op = coption_create(sizeof(int));
  coption_free(&op);
  return 0;
}
```

### `coption_somify`
`void coption_somify(Coption *op, void *data);`

Put a value inside of `op` and make it `some`.

Example:
```c
int main(void) {
  Coption op = coption_create(sizeof(int));

  coption_somify(&op, COCONST(1));

  // or
  // int i = 1;
  // coption_somify(&op, &i);

  coption_free(&op);
  return 0;
}
```

### `coption_nonify`
`void coption_nonify(Coption *op);`

Set `op` to `none`.

Example:
```c
int main(void) {
  Coption op = coption_create(sizeof(int));

  coption_somify(&op, COCONST(1));
  coption_nonify(&op);

  coption_free(&op);
  return 0;
}
```

### `coption_is_some`
`int coption_is_some(Coption *op);`

Check if `op`op` is `none`.

Example:
```c
int main(void) {
  Coption op = coption_create(sizeof(int));

  coption_somify(&op, COCONST(1));

  printf("%s\n",
         coption_is_none(&op) ? "true" : "false");

  coption_free(&op);
  return 0;
}
```
Output:
```
false
```

### `coption_unwrap`
`void *coption_unwrap(Coption *op);`

Get the underlying data inside of `op`. Panics if it is `none`.

Example:
```c
int main(void) {
  Coption op = coption_create(sizeof(float));

  coption_somify(&op, COCONST(99.f));

  printf("%f\n", *(float *)coption_unwrap(&op));

  coption_free(&op);
  return 0;
}
```
Output:
```
99.000000
```

### `coption_unwrap_or`
`void *coption_unwrap_or(Coption *op, void *fallback);`

Get the underlying data inside of `op`. If `op` is `none`, it will return `fallback`.

Example:
```c
int main(void) {
  Coption op = coption_create(sizeof(float));

  coption_somify(&op, COCONST(99.f));
  coption_nonify(&op);

  printf("%f\n", *(float *)coption_unwrap_or(&op, COCONST(1.f)));

  coption_free(&op);
  return 0;
}
```
Output:
```
1.000000
```

### `coption_free`
`void coption_free(Coption *op);`

`free()` `op`.

Example:
```c
int main(void) {
  Coption op = coption_create(sizeof(float));
  coption_somify(&op, COCONST(99.f));
  coption_free(&op);
  return 0;
}
```

