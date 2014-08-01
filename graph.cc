
#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::cin;

// Adjacency List Graph Implementation
template <typename T>
struct graph
{
  template <typename T>
  struct node
  {
    T value;
    std::vector<std::size_t> conns;
  };

  std::vector< node<T> > nodes;

  std::size_t add_node(const T& v)
  {
    nodes.push_back({v,{}});
    return nodes.size() - 1;
  }

  bool add_edge(std::size_t a, std::size_t b)
  {
    if (a >= nodes.size() && b >= nodes.size())
      return false;

    nodes[a].conns.push_back(b);
    nodes[b].conns.push_back(a);
    return true;
  }
};

std::vector<std::size_t> unwind(const std::vector<std::size_t>& parents,
                                std::size_t a, std::size_t b)
{
  if (b == a)
    return {a};
  auto path = unwind(parents, a, parents[b]);
  path.push_back(b);
  return path;
}

// BFS Shortest Path / no weights on edges
template <typename T>
std::vector<std::size_t> shortest_path(const graph<T>& g, std::size_t a, std::size_t b)
{
  std::vector<bool>        seen(g.nodes.size());
  std::vector<std::size_t> parents(g.nodes.size());

  std::queue<std::size_t> queue;
  queue.push(a);
  while (!queue.empty())
  {
    auto current_node = queue.front(); // dijkstra: same with min in priority queue
    cout << current_node << endl;
    for (auto& e: g.nodes[current_node].conns)
    {
      if (!seen[e])
      {
        parents[e] = current_node;
        if (e == b)                    // dijkstra: cannot return here, there is a possibly better path
          return unwind(parents,a,b);

        seen[e] = true;                // dijkstra: update distance to e here
        queue.push(e);
      }
    }
    queue.pop();
  }
  return {};
}

int main(int, char **)
{
  graph<int> g;

  cout << "add nodes" << endl;
  auto a = g.add_node(1);
  auto b = g.add_node(1);
  auto c = g.add_node(1);
  auto d = g.add_node(1);
  auto e = g.add_node(1);

  cout << "add edges" << endl;
  g.add_edge(a, c);
  g.add_edge(a, b);
  g.add_edge(b, c);
  g.add_edge(c, d);
  g.add_edge(d, e);
  g.add_edge(b, e);

  cout << "shortest_path" << endl;
  auto path = shortest_path(g, a, e);
  for (auto& e: path)
    cout << e << " ";
  cout << endl;
}
