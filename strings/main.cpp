#include <iostream>
#include "./string.hpp"

int main(int argc, char **argv)
{
  /* String s = String("hss-w-www-dd-ff"); */
  /* String sub = String("llo"); */
  /* String sep = String("-"); */
  /* std::cout << s.len << " " << sub.len << std::endl; */
  /* std::cout << "char at: " << s.char_at(8) << std::endl; */
  /* std::cout << "index of: " << s.index_of(sub) << std::endl; */
  /* std::cout << "includes: " << s.includes(sub) << std::endl; */
  /* std::cout << "substring: " << s.substring(1, 9) << std::endl; */
  /* std::cout << "split: " << s.split(sep) << std::endl; */
  String s;
  while (std::cin >> s) {
    std::cout << s.split(String("fat_sep")) << std::endl;
  }
  return 0;
}
