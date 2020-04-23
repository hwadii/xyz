#include "./string.hpp"
#include "./tests.hpp"
// Helpers
std::vector<String> do_split(const std::string &s, const String &delim) {
  return String(s).split(delim);
}

void Tests::test_split(const std::string &desc) {
  std::cout << desc << std::endl;
  std::vector<String> splits = do_split("this-is-a-string", String("-"));
  assert(splits.size() == 4);
  assert(splits.front().get_string() == String("this"));
  assert(splits.back().get_string() == String("string"));
  splits = do_split("-this-is-a-", String("-"));
  assert(splits.size() == 5);
  assert(splits.front().get_string() == "");
  assert(splits.back().get_string() == "");
}

void Tests::test_concat(const std::string &desc) {
  std::cout << desc << std::endl;
  String s = String("Foo");
  String s1 = String(" Bar");
  String s2 = String(" Baz");
  String expected_string = String("Foo Bar Baz");
  assert(s.concat(0, s1, s2, String("")) == expected_string);
}
