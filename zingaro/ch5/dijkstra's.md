### Dijkstra's identifies the shortest path for nodes further and further away, in terms of total edge weight, from the starting node.
BFS works in rounds, where the nodes discovered in the next round are one edge more distant than the nodes in the current round. However, in Dijkstra's, the most recent shortest paths are not necessarily the shortest path for a new node.

## IMPORTANT!!! 
#### After we finish processing one node, we check to see if we can use it to improve any of the shortest paths for nodes that not yet done.
So basically we loop through the nodes that the current node poits to, or the outgoing edges of said node. We check to see if the updated path using the current node is better than what we already have for that node.

### When choosing a new node to process, it must be an unprocessed one with the least possible weight.


## Time Optimizations
  * As soon as the exit cell is set to done, we terminate the algorithm.
  * Reverse all directions in the graph and call Dijkstra's once- with the exit cell as the starting cell!
