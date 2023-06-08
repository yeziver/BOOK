### Dijkstra's identifies the shortest path for nodes further and further away, in terms of total edge weight, from the starting node.
BFS works in rounds, where the nodes discovered in the next round are one edge more distant than the nodes in the current round. However, in Dijkstra's, the most recent shortest paths are not necessarily the shortest path for a new node.

## IMPORTANT!!! 
#### After we finish processing one node, we check to see if we can use it to improve any of the shortest paths for nodes that not yet done.
