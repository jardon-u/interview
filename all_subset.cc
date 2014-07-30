#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

// Count number of bits set to one
// Can be written more efficiently
int hamilton_weight(int i, int nb_bits)
{
    int cur = 1;
    int k = 0;
    for (int j = 0; j < nb_bits; j++)
    {
      k += (cur & i) > 0 ? 1 : 0;
      cur = cur << 1;
    }
    return k;
}

// Iterate on every subsets of a set v
// You usually never want to do this
//         /!\   O(2^n)
void print_all_subset_sum(std::vector<int> v)
{
  int nb_subset = std::pow(2, v.size());
  for (int i = 0; i < nb_subset; i++)
  {
    int sum = 0;
    for (int j = 0; j < v.size(); j++)
    {
      int cur = std::pow(2, j);
      if (cur & i)
      {
        cout << v[j] << " ";
        sum += v[j];
      }
    }
    cout << " -> " << sum << endl;
  }
}

// the number of subsets of size k among a set of n elements:
// comb(k,n) = n! / (k!(n-k)!)

int main(int, char **)
{
  std::vector<int> v = {0, 1, 2, 3};

  print_all_subset_sum(v);
}
