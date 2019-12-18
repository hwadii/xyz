#include "./string.hpp"

String String::char_at(int index) {
  try {
    return String(std::string(1, _el.at(index)));
  } catch (std::out_of_range &e) {
    return String("");
  }
}

std::size_t String::index_of(const String &s) {
  return _el.find(s.get_string());
}

bool String::includes(const String &s) {
  return _el.find(s.get_string()) == -1 ? false : true;
}

String String::substring(size_t a, size_t b) {
  return String(_el.substr(a, b - a));
}

std::vector<String> String::split(const String &sep) {
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

String String::concat(int first, ...) {
  va_list vars;
  va_start(vars, first);
  std::string current;
  std::string s(_el);
  while ((current = va_arg(vars, std::string)) != "") {
    s += current;
  }
  va_end(vars);
  return String(s);
}

String &String::operator+=(const String &other) {
  _el += other.get_string();
  return *this;
}

String &String::operator=(const std::string &el) {
  _el = el;
  return *this;
}

std::ostream &operator<<(std::ostream &out, const String &s) {
  out << s._el;
  return out;
}

std::ostream &operator<<(std::ostream &out, const std::vector<String> &ss) {
  auto format = [](const std::string &prev, const String &curr) {
    return prev + ", " + curr.get_string();
  };
  std::string ret = std::accumulate(std::next(ss.begin()), ss.end(), ss.at(0).get_string(), format);
  out << "[ " << ret << " ]";
  return out;
}

std::istream &operator>>(std::istream &in, String &s) {
  in >> s._el;
  return in;
}
