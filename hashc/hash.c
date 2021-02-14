#include "hash.h"

size_t size = 17;

t_hash init() {
  t_hash hm = calloc(size, sizeof(int));
  return hm;
}

int get(t_hash hm, uint key) {
  return hm[key];
}

int set(t_hash hm, uint key, int value) {
  if (key > size) {
    size = key;
    hm = realloc(hm, size * sizeof(int));
  }
  hm[key] = value;
  return value;
}

void print_map(t_hash hm) {
  for (size_t i = 0; i <= size; i++) {
    printf("%d ", hm[i]);
  }
  printf("\n");
}
