#include "./string.hpp"
#include <iostream>

int main(int argc, char **argv) {
  String s1 = String("foo");
  String s2 = String("bar");
  String s3 = String("baz");
  String ss;
  ss = ss.concat(0, s1, s2, s3, String(""));
  std::cout << ss << std::endl;
  return 0;
}
