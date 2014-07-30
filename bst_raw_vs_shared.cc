#include <iostream>
#include <memory>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

/// Binary Search Tree
template <typename T>
struct bst_raw
{
  struct node_raw
  {
    typedef node_raw * node_ptr;

    node_raw(const T& v) : value(v) {}

    T        value;
    node_ptr left  = nullptr;
    node_ptr right = nullptr;

    ~node_raw()
    {
      delete left;
      delete right;
    }
  };

  typedef typename node_raw::node_ptr node_ptr;
  node_ptr root = nullptr;

  node_ptr insert(const T& v)
  {
    if (root == nullptr)
      return root = new node_raw(v);

    node_ptr prev = root;
    node_ptr p = root;
    while (p != nullptr)
    {
      prev = p;
      p = (v < p->value) ? p->left : p->right;
    }
    if (v < prev->value)
      return prev->left = new node_raw(v);
    else
      return prev->right = new node_raw(v);
  }

  ~bst_raw()  { delete root; }
};

/// Binary Search Tree using shared ptr
template <typename T>
struct bst
{
  struct node
  {
    typedef std::shared_ptr<node> node_ptr;

    node(const T& v) : value(v) {}

    T        value;
    node_ptr left  = nullptr;
    node_ptr right = nullptr;
  };

  typedef typename node::node_ptr node_ptr;
  node_ptr root;

  node_ptr insert(const T& v)
  {
    if (root == nullptr)
      return root = std::make_shared<node>(v);

    node_ptr prev = root;
    node_ptr p = root;
    while (p != nullptr)
    {
      prev = p;
      p = (v < p->value) ? p->left : p->right;
    }
    if (v < prev->value)
      return prev->left = std::make_shared<node>(v);
    else
      return prev->right = std::make_shared<node>(v);
  }
};

int main(int, char **)
{
  int n = 1000000;

  if (1)
  {
    bst_raw<int> t;
    for (int i = 0; i < n; i++)
    {
      int v = rand() % n;
      t.insert(v);
    }
    // -O3 ~1s
  }
  else
  {
    bst<int> t;
    for (int i = 0; i < n; i++)
    {
      int v = rand() % n;
      t.insert(v);
    }
    // -O3 ~1,5s
  }
}
