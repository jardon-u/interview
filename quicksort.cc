
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using std::cout;
using std::endl;
using std::cin;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::steady_clock;

template <typename T>
void print(const T& v)
{
  for (auto e : v)
    std::cout << e << ' ';
  std::cout << std::endl;
}

template <typename T>
void quicksort(T& v, int i, int j)
{
  if (i >= j)
    return;

  int p = i - 1;
  for (auto k = i; k < j; ++k)
    if (v[k] <= v[j])
      std::swap(v[++p], v[k]);
  std::swap(v[++p], v[j]);

  quicksort(v, i  , p-1);
  quicksort(v, p+1,   j);
}

int main(int, char **)
{
  std::vector<int> v;
  for (int i = 0; i < 1000; ++i)
    v.push_back(i);
  std::random_shuffle ( v.begin(), v.end() );

  steady_clock::time_point start = steady_clock::now();
  quicksort(v, 0, v.size()-1);
  steady_clock::time_point end = steady_clock::now();
  std::cout << duration_cast<microseconds>(end - start).count()
            << "\n";

  //std::cout << (std::is_sorted(v.begin(), v.end())
  //              ? "true" : "false") << std::endl;
}
