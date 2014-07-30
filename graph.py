# Adjacency List Graph Implementation
class Node:
    def __init__(self, i, conns):
        self.id = i
        self.conns = conns

    def __str__(self):
        return "Node(" + str(self.id) \
          + "," + str(self.conns) + ")"

    def __repr__(self):
        return "Node(" + str(self.id) \
          + ", ...)" # + repr(self.conns) + ")"

    def __getitem__(self, i):
        if i == 0:
            return self.id
        if i == 1:
            return self.conns
        raise IndexError

class Graph:
    def __len__(self):
        return len(self.nodes)

    def __str__(self):
        v = "adjacency list:\n"
        for n in self.nodes:
            babies = [str(c.id) for c in n.conns]
            v += str(n.id) + ": "
            v += " ".join(babies) + "\n"
        print " ------- ",
        return v

    def __getitem__(self, i):
        return self.nodes[i]

    def __init__(self):
        self.nodes = []

    def add_conns(self, a, b):
        self.nodes[a].conns.append(graph[b])
        self.nodes[b].conns.append(graph[a])

    def add_node(self, conns):
        id_ = len(graph)
        self.nodes.append(Node(id, [graph[i] for i in conns]))
        for i in conns:
            self.nodes[i].conns.append(graph[id])
        return id_

    def edges(self):
        edges = []
        for n in self.nodes:
            edges.extend((n.id,j.id) for j in n.conns)
        return edges

# Depth First Search
def dfs(g):
    print "dfs:"
    def dfs_rec(g, i, checked):
        print i,
        checked[i] = True
        for id_, _ in g[i].conns:
            if not checked[i]:
                dfs_rec(g, id_, checked)
    checked = [False] * len(g)
    for i in xrange(len(g)):
        if not checked[i]:
            dfs_rec(g, i, checked)
    print

# Breadth First Search
def bfs(g):
    print "bfs:"
    checked = [False] * len(g)
    checked[0] = True
    tosee = [0]
    print 0,
    while tosee:
        i = tosee.pop()
        for id_, _ in g[i].conns:
            if not checked[id_]:
                print id_,
                tosee.insert(0,id_)
                checked[id_] = True
    print

def find_set(i, reps):
    rep = i
    while reps[rep] != rep:
        rep = reps[rep]
    return rep

def link(x,y, rank, reps):
    if rank[x] > rank[y]:
        reps[y] = x
    else:
        reps[x] = y
        if rank[x] == rank[y]:
            rank[y] = rank[y] + 1

def union(x, y, rank, reps):
    link(find_set(x, reps), find_set(y, reps), rank, reps)

# Minimum Spanning Tree
def mst_kruskal(g):
    reps = [-1] * len(g.nodes)
    for n in g.nodes:
        reps[n.id] = n.id
    rank = [0] * len(g.nodes)
    A = set(tuple())
    for e in g.edges(): # sorted decreasing by weight
        if find_set(e[0], reps) != find_set(e[1], reps):
            A = set.union(A, [e])
            union(e[0], e[1], rank, reps)
    return A

graph = Graph()

graph.add_node([])
graph.add_node([])

graph.add_conns(0, 1)

graph.add_node([0,1])
graph.add_node([2])
graph.add_node([0])
graph.add_node([1])

print graph

dfs(graph)
bfs(graph)

print "mst_kuskal:"
print mst_kruskal(graph)
