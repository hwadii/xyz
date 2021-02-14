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
  hash m = init();
  set(&m, 0, 1);
  set(&m, 1, 2);
  assert(get(&m, 0) == 1);
  assert(get(&m, 1) == 2);
  free(m.values);
}
