## Depth First Search 
Every time DFS hits a branching point, DFS will choose one of the unvisited neighbors and visit this neighbor vertex. DFS repeats this process and goes until it reaches a vertex where it cannot go any further. Next, DFS will ‘backtrack’ and explore another unvisited neighbor.

### Subsection: Finding Arituclation Points
Two numbers are maintained; dfs_num() and dfs_low(). dfs_num() represents the iteration counter when the vertex u is visited for the first time during the traversal. It is used to keep track of the order in which vertices are visited. dfs_low() stores the minimum dfs_num among all the vertices that can be reached from u through a path consisting of tree edges and at most one back edge.
When we are in a vertex u with v as its neighbor and dfs_low(v) ≥ dfs_num(u), then u is an articulation vertex.

## Breadth First Search
BFS visits vertices that are direct neighbors of the first layer, neighbors of the second layer, and so on, layer by layer. The proccess: take out the front most vertex u from the queue, enqueue all unvisited neighbors of u, and mark them as visited.

