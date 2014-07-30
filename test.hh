#ifndef _TEST_HH
# define _TEST_HH

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
inline void are_equal(const T& expected,
                      const T& value,
                      const std::string& msg="")
{
  cout << "Expected : " << expected << " and was " << value
       << ((expected == value) ? " [OK]" : " Fail!")
       << " " << msg << std::endl;
}


inline void are_equal(bool expected,
                      bool value,
                      const std::string& msg="")
{
  cout << "Expected : " << (expected ? "true" : "false")
       << " and was " << (value ? "true" : "false")
       << ((expected == value) ? " [OK]" : " Fail!")
       << " " << msg << std::endl;
}

#endif /* _TEST_HH */
