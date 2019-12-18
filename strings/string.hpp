#include <cstdarg>
#include <iostream>
#include <istream>
#include <numeric>
#include <ostream>
#include <string>
#include <vector>

class String {
private:
  std::string _el;

public:
  String() : _el(""), len(0){};
  String(const std::string &el) : _el(el), len(el.size()){};
  ~String(){};
  inline std::string get_string() const { return _el; } // ✅
  String char_at(int);                                  // ✅
  std::size_t index_of(const String &);                 // ✅
  bool includes(const String &);                        // ✅
  String substring(size_t, size_t);                     // ✅
  std::vector<String> split(const String &);            // ✅
  String concat(int, ...);                              // ✅

  friend bool operator==(const String &s1, const String &s2) {
    return s1.get_string() == s2.get_string();
  }
  friend bool operator!=(const String &s1, const String &s2) {
    return !(s1 == s2);
  }
  String &operator+=(const String &);
  String &operator=(const std::string &);
  friend std::ostream &operator<<(std::ostream &, const String &);
  friend std::ostream &operator<<(std::ostream &, const std::vector<String> &);
  friend std::istream &operator>>(std::istream &, String &);

  int len;
};
