#ifndef __HASH_H
#define __HASH_H

#include <stdio.h>
#include <stdlib.h>

typedef int* t_hash;

t_hash init();
int get(t_hash, int);
int set(t_hash, int, int);
int hash(char *);
void print_map(t_hash);

#endif