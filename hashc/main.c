#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "hash.h"

void test_hm();

int main(int argc, char **argv)
{
  test_hm();
  return 0;
}

void test_hm() {
  t_hash hm = init();
  set(hm, 0, 1);
  set(hm, 1, 2);
  assert(get(hm, 0) == 1);
  assert(get(hm, 1) == 2);
  free(hm);
}
