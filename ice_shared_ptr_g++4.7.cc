
#include <iostream>
#include <memory>


using std::cout;
using std::endl;
using std::cin;

template <typename T>
struct node
{
  //node(const T& v)
  //: value(v), left(nullptr), right(nullptr)
  //{}
  T value;
  std::shared_ptr<node> left;
  std::shared_ptr<node> right;
};

template <typename T>
struct bst
{
  std::shared_ptr<node<T>> root;

  void insert(const T& v)
  {
    if (root == nullptr)
      root = std::make_shared<node<T>>(v); // ice if ctor does not exist

    std::shared_ptr< node<int> > prev = root;
    std::shared_ptr< node<int> > p = root;
    while (p != nullptr)
    {
      prev = p;
      if (v < p->value)
        p = p->left;
      else
        p = p->right;
    }
    if (v < prev->value)
      prev->left = std::make_shared<node<T>>(v);
    else
      prev->right = std::make_shared<node<T>>(v);
  }
};

int main(int, char **)
{
  bst<int> t;
  t.insert(4);
}
