
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using std::cout;
using std::endl;
using std::cin;

struct item
{
  int value;
  int weight;
};

struct ks
{
  std::vector<item> items;
  int value;

  int get_total_weight()
  {
    int sum = 0;
    for (auto& e : items)
      sum += e.weight;
    return sum;
  }
};


void println(const std::string& msg, int depth)
{
  while (depth--)
    cout << "  ";
  cout << msg << endl;
}

// KnapSnack Problem Solver with Memoisation
// Pseudo polynomial O(nW)
ks& max_value_set(std::vector<item> items, int max_w, int depth,
                  std::map<int, ks>& memo)
{
  if (max_w <= 0)
  {
    memo[0] = {{}, 0};
    return memo[0];
  }

  if (memo.find(max_w) != memo.end())
    return memo[max_w];

  std::vector<item> max_set;
  int max = 0;
  std::size_t last_size = -1;

  for (auto& e : items)
  {
    auto rest = max_value_set(items, max_w - e.weight, depth + 1, memo);
    int current_value = e.value + rest.value;
    if (current_value >= max &&
        rest.items.size() < last_size &&
        (rest.get_total_weight() + e.weight) <= max_w)
    {
      last_size = rest.items.size();
      max_set = rest.items;
      max_set.push_back(e);
      max = current_value;
    }
  }

  memo[max_w] = {max_set, max};
  return memo[max_w];
}

int main(int, char **)
{
  // value, weight
  std::vector<item> items = { {6,2}, {3,1} };
  int max_w = 7;

  std::map<int, ks> memo;
  auto item_set = max_value_set(items, max_w, 0, memo);

  cout << "max value: " << item_set.value << endl;
  cout << "element value,weight " << endl;
  for (auto& e : item_set.items)
  {
    cout << e.value << "," << e.weight << endl;
  }
}
