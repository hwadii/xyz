#include "./tests.hpp"
#include <iostream>

int main(int argc, char **argv) {
  Tests::test_split("test_split");
  Tests::test_concat("test_concat");
  return 0;
}

