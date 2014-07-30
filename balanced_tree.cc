
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::cin;

template <typename T>
struct node
{
  node(const T& v, int d)
    : value(v), left(nullptr), right(nullptr), depth(d) {}

  T value;
  std::shared_ptr<node> left  = nullptr;
  std::shared_ptr<node> right = nullptr;

  int depth;
};


template <typename T>
struct balanced_tree // Not a search tree (no particular order)
{
  std::shared_ptr< node<T> > root;

  balanced_tree()
  {
    root = nullptr;
  }

  std::shared_ptr<node<T>>
  insert(std::shared_ptr<node<T>> tree, const T& v)
  {
    if (tree == nullptr)
      return std::make_shared< node<T> >(v, 0);
    if (tree->right != nullptr && tree->left != nullptr)
    {
      if (tree->right->depth < tree->left->depth)
        tree->right = insert(tree->right, v);
      else
        tree->left = insert(tree->left, v);
    }
    else
    {
      if (tree->right == nullptr)
        tree->right = insert(tree->right, v);
      else
        tree->left = insert(tree->left, v);
    }
    tree->depth++;
    return tree;
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
  balanced_tree<int> tree;
  tree.root = tree.insert(tree.root, 1);
print(tree);
  tree.root = tree.insert(tree.root, 2);
print(tree);
  tree.root = tree.insert(tree.root, 3);
print(tree);
  tree.root = tree.insert(tree.root, 4);
print(tree);
  tree.root = tree.insert(tree.root, 5);
  print(tree);
tree.root = tree.insert(tree.root, 6);
  print(tree);
tree.root = tree.insert(tree.root, 7);
  print(tree);
}
