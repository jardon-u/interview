
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

void display(const std::vector<int>& v,
             std::size_t begin,
             std::size_t end)
{
  for (std::size_t i = 0; i < v.size(); i++)
  {
    if (i >= begin && i < end)
      cout << v[i] << " ";
    else
      cout << "# ";
  }
}

void merge(std::vector<int>& v,
           std::size_t begin,
           std::size_t middle,
           std::size_t end)
{
  std::vector<int> merged;
  std::size_t ia = begin;
  std::size_t ib = middle;

  while (ia != middle || ib != end)
  {
    if (ia == middle)
    {
      for (std::size_t i = ib; i < end; i++)
        merged.push_back(v[i]);
      ib = end;
      continue;
    }
    if (ib == end)
    {
      for (std::size_t i = ia; i < middle; i++)
        merged.push_back(v[i]);
      ia = middle;
      continue;
    }
    if (v[ia] <= v[ib])
      merged.push_back(v[ia++]);
    else
      merged.push_back(v[ib++]);
  }

  for (std::size_t i = 0; i < merged.size(); i++)
  {
    v[begin+i] = merged[i];
  }

  //display(v, begin, end);
  //cout << " merged" <<  endl;
}


// Merge Sort - In place
// Usually if you can sort in place
// quick sort is better.
// Not in place implementation is simpler.
void merge_sort(std::vector<int>& v,
                int begin,
                int end)
{
  //display(v, begin, end);
  //cout << endl;

  if ((end - begin) == 1)
    return;

  int  middle = begin + (end - begin) / 2;

  merge_sort(v, begin, middle);
  merge_sort(v, middle, end);

  merge(v, begin, middle, end);
}

int main(int, char **)
{
  std::vector<int> v = {2, 9, 4, 1};

  merge_sort(v, 0, v.size());

  for (auto e : v)
    cout << e << " ";
   cout << endl;
}
