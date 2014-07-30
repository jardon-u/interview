
#include <iostream>
#include <vector>
#include "test.hh"

using std::cout;
using std::endl;
using std::cin;

int binary_search(std::vector<int> v, int e, int begin, int end)
{
  if (begin == end)
    return -1;
  int middle = begin + (end - begin) / 2;
  if (e < v[middle])
    return binary_search(v, e, begin, middle);
  if (e > v[middle])
    return binary_search(v, e, middle + 1, end);
  return middle;
}

int main(int, char **)
{
  std::vector<int> v = {1, 2, 5, 8, 89, 99, 111, 1000};

  are_equal(binary_search(v, 5, 0, v.size()),     2);
  are_equal(binary_search(v, 4, 0, v.size()),    -1);
  are_equal(binary_search(v, 1000, 0, v.size()),  7);
  are_equal(binary_search(v, 1011, 0, v.size()), -1);
  are_equal(binary_search(v, 1, 0, v.size()),     0);
}
