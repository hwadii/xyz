#ifndef __HASH_H
#define __HASH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *values;
  uint size;
} hash;

typedef hash *t_hash;

hash init();
int get(t_hash, uint);
int set(t_hash, uint, int);
uint hash_key(t_hash, uint);
void print_map(t_hash);

#endif
