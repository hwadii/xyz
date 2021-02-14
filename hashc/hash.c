#include "hash.h"

hash init() {
  uint size = 17;
  hash h = { .values = calloc(size, sizeof(int)), .size = size };
  return h;
}

int get(t_hash hm, uint key) {
  return hm->values[key];
}

int set(t_hash hm, uint key, int value) {
  if (key > hm->size) {
    hm->size = key;
    hm->values = realloc(hm->values, hm->size * sizeof(int));
  }
  hm->values[key] = value;
  return value;
}

void print_map(t_hash hm) {
  for (size_t i = 0; i <= hm->size; i++) {
    printf("%d ", hm->values[i]);
  }
  printf("\n");
}
