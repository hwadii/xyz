#include <iostream>
#include "./string.hpp"

String String::char_at(int index)
{
  try {
    return String(std::string(1, _el.at(index)));
  } catch (std::out_of_range& e) {
    return String("");
  }
}

std::size_t String::index_of(String s)
{
  return _el.find(s.get_string());
}

bool String::includes(String s)
{
  return _el.find(s.get_string()) == -1 ? false : true;
}

String String::substring(size_t a, size_t b)
{
  return String(_el.substr(a, b-a));
}

std::vector<String> String::split(String sep)
{
  std::string current = "";
  std::vector<String> substrs;
  size_t i = 0, next = 0;
  
  while (next != -1) {
    next = _el.find(sep.get_string(), i);
    substrs.push_back(this->substring(i, next));
    i = next + sep.len;
  }
  return substrs;
}

std::ostream& operator<<(std::ostream& out, const String& s)
{
  out << s._el;
  return out;
}

std::ostream& operator<<(std::ostream& out, const std::vector<String>& ss)
{
  int len = ss.size();
  out << "[ ";
  for (size_t i = 0; i < len; i++) {
    if (i < len-1)
      out << ss.at(i) << ", ";
    else
      out << ss.at(i);
  }
  out << " ]";
  return out;
}

std::istream& operator>>(std::istream& in, String& s)
{
  in >> s._el;
  return in;
}
