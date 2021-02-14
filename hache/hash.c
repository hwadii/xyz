#include "hash.h"

hash init() {
  uint size = 17;
  hash h = { .values = calloc(size, sizeof(int)), .size = size };
  return h;
}

int get(t_hash hm, uint key) {
  uint curr = hash_key(hm, key);
  return hm->values[curr];
}

int set(t_hash hm, uint key, int value) {
  if (key > hm->size) {
    hm->size = key;
    hm->values = realloc(hm->values, hm->size * sizeof(int));
  }
  uint curr = hash_key(hm, key);
  hm->values[curr] = value;
  return value;
}

uint hash_key(t_hash m, uint key) {
  /* Robert Jenkins' 32 bit Mix Function */
  key += (key << 12);
  key ^= (key >> 22);
  key += (key << 4);
  key ^= (key >> 9);
  key += (key << 10);
  key ^= (key >> 2);
  key += (key << 7);
  key ^= (key >> 12);

  /* Knuth's Multiplicative Method */
  key = (key >> 3) * 2654435761;
  return key % m->size;
}

void print_map(t_hash hm) {
  for (size_t i = 0; i <= hm->size; i++) {
    printf("%d ", hm->values[i]);
  }
  printf("\n");
}
