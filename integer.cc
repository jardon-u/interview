
#include <iostream>
#include <cctype>
#include <cmath>
#include "test.hh"

using std::cout;
using std::endl;
using std::cin;

struct integer
{
  int value = 0;

  bool parse(const std::string& s)
  {
    value = 0;

    int shift = (s.size() > 0 && s[0] == '-');
    for (std::size_t i = shift; i < s.size(); i++)
      if (!std::isdigit(s[i]))
        return false;

    for (int i = s.size(); i != shift;) {
      value += (s[i - 1] - '0') * std::pow(10, s.size() - i);
      i--;
    }
    if (shift)
      value *= -1;
    return true;
  }

  std::string to_string(int base = 10)
  {
    std::string s;
    int v = std::abs(value);

    if (v == 0)
      return "0";

    while (v != 0)
    {
      int rest = v % base;
      s = std::to_string(rest) + s;
      v = v / base;
    }
    if (value < 0)
      return "-" + s;
    return s;
  }
};

int main(int, char **)
{
  integer i;

  are_equal(i.parse("145"), true, "i.parse('145')");
  are_equal(i.value, 145);
  are_equal(i.to_string(), std::string("145"));

  are_equal(i.parse("-0997"), true, "i.parse('-0997')");
  are_equal(i.value, -997);
  are_equal(i.to_string(), std::string("-997"));

  are_equal(i.parse("1-0997"), false, "i.parse('1-0997')");
  are_equal(i.value, 0);
  are_equal(i.to_string(), std::string("0"));

  are_equal(i.parse("abs"), false, "i.parse('abs')");
  are_equal(i.value, 0);
  are_equal(i.to_string(), std::string("0"));
}
