
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

template <typename T>
void bucketsort(T& v, std::size_t min, std::size_t max)
{
  std::vector<int> buckets(max - min + 1, 0);

  for (auto& i: v)
    buckets[i - min]++;

  int k = 0;
  for (std::size_t l = 0; l < buckets.size(); l++)
  {
    while (buckets[l]--)
    {
      v[k] = l + min;
      k++;
    }
  }
}

int main(int, char **)
{
  std::vector<int> v = { 2, 4, 3, 7, 6, 10, 1 };
  bucketsort(v, 1, 10);
  for (auto& i: v)
    cout << i << " ";
  cout << endl;
}
