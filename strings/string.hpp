#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include <ostream>

class String
{
  private:
    std::string _el;

  public:
    String() : _el(""), len(0) {};
    String(std::string el) : _el(el), len(el.size()) {};
    ~String() {};
    inline std::string get_string() { return _el; } // ✅
    String char_at(int); // ✅
    std::size_t index_of(String); // ✅ 
    bool includes(String); // ✅
    String substring(size_t, size_t);
    String concat(String);
    std::vector<String> split(String);
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend std::ostream& operator<<(std::ostream&, const std::vector<String>&);
    friend std::istream& operator>>(std::istream&, String&);

    int len;
};
