#include "hash.h"

const int size = 17;

t_hash init() {
  t_hash hm = calloc(size, sizeof(int));
  return hm;
}

int get(t_hash hm, int key) {
  return key;
}

int set(t_hash hm, int key, int value) {
  return value;
}

void print_map(t_hash hm) {
  for (size_t i = 0; i < size; i++) {
    printf("%d ", hm[i]);
  }
  printf("\n");
}
