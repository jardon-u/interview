#include <iostream>
#include <memory>
#include <boost/timer.hpp>

using std::cout;
using std::endl;
using std::cin;

template <typename T>
struct node
{
  node(const T& v)
  : value(v), left(nullptr), right(nullptr) {}

  T value;
  std::shared_ptr<node> left  = nullptr;
  std::shared_ptr<node> right = nullptr;

  int level; // only for aat
};

/// Binary Search Tree
template <typename T>
struct bst
{
  typedef std::shared_ptr< node<T> > node_ptr;
  node_ptr root;

  node_ptr insert(const T& v)
  {
    if (root == nullptr)
      return root = std::make_shared<node<T>>(v);

    node_ptr prev = root;
    node_ptr p = root;
    while (p != nullptr)
    {
      prev = p;
      p = (v < p->value) ? p->left : p->right;
    }
    if (v < prev->value)
      return prev->left = std::make_shared<node<T>>(v);
    else
      return prev->right = std::make_shared<node<T>>(v);
  }
};

// AA tree
//
// Simpler to implement than a black/red tree
// and offers similar performances
template <typename T>
struct aat
{
  typedef std::shared_ptr< node<T> > node_ptr;
  node_ptr root;

  void insert(const T& v)
  {
    root = insert_in(root, v);
  }

private:
  node_ptr insert_in(node_ptr p, const T& v)
  {
    if (p == nullptr)
      return std::make_shared<node<T>>(v);
    if (v < p->value)
      p->left = insert_in(p->left, v);
    else
      p->right = insert_in(p->right, v);

    p = skew(p);
    p = split(p);

    return p;
  }

  node_ptr skew(node_ptr p)
  {
    if (p == nullptr)
      return p;
    if (p->left == nullptr)
      return p;
    if (p->left->level == p->level)
      // Swap the pointers of horizontal left links.
    {
      node_ptr l = p->left;
      p->left = l->right;
      l->right = p;
      return l;
    }
    return p;
  }

  node_ptr split(node_ptr p)
  {
    if (p == nullptr)
      return p;
    if (p->right == nullptr || p->right->right == nullptr)
      return p;
    if (p->level == p->right->right->level)
      // We have two horizontal right links.
      // Take the middle node, elevate it, and return it.
    {
      node_ptr r = p->right;
      p->right = r->left;
      r->left = p;
      r->level += 1;
      return r;
    }
    return p;
  }
};

template <typename T>
void print_node(std::shared_ptr< node<T> > p)
{
  if (p == nullptr)
  {
    cout << "∅";
    return;
  }
  if (p->left == nullptr && p->right == nullptr)
  {
    cout << p->value;
    return;
  }
  cout << p->value << " ( ";
  print_node(p->left);
  cout << " , ";
  print_node(p->right);
  cout << " )";
}

template <typename T>
void print(const T& tree)
{
  cout << "(";
  print_node(tree.root);
  cout << " )" << endl;
}


int main(int, char **)
{
  {
    bst<int> t;
    auto p = t.insert(4);
    cout << "insert: " << p->value << endl;
    p = t.insert(6);
    cout << "insert: " << p->value << endl;
    p = t.insert(7);
    cout << "insert: " << p->value << endl;
    p = t.insert(5);
    cout << "insert: " << p->value << endl;

    print(t);
  }

  {
    aat<int> t;
    t.insert(4);
    cout << "insert: 4" << endl;
    t.insert(7);
    cout << "insert: 7" << endl;
    t.insert(8);
    cout << "insert: 8" << endl;
    t.insert(5);
    cout << "insert: 5" << endl;
    print(t);

    t.insert(6);
    cout << "insert: 6" << endl;
    print(t);
  }
}
