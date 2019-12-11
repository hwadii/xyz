#include "./string.hpp"
#include <iostream>

int main(int argc, char **argv) {
  String s;
  while (std::cin >> s) {
    std::cout << s.split(String("-")) << std::endl;
  }
  return 0;
}
