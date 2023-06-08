//none of the specified optimizations are used in this code- this is the raw uncut version haha

#include <ctime>
#include <iostream>
using namespace std;

#define MAX_CELLS 100

typedef struct edge {
  int to_cell, length;
  struct edge *next;
} edge;

int find_time(edge *adj_list[], int num_cells, int from_cell, int exit_cell) {
  static int done[MAX_CELLS + 1];
  static int min_times[MAX_CELLS + 1];
  int i, j, found;
  int min_time, min_time_index, old_time;
  edge *e;
  for (i = 1; i <= num_cells; i++) {
    done[i] = 0; 
    min_times[i] = -1;
  }
  min_times[from_cell] = 0; // shortest path from starting cell to itself is zero
  
  for (i = 0; i < num_cells; i++) {
    min_time = -1;
    found = 0; // whether a new cell can be found or not
    for (j = 1; j <= num_cells; j++) { // identify the cell whose shortest path will be found next
      if (!done[j] && min_times[j] >= 0) { // eligible cells are not done
        if (min_time == -1 || min_times[j] < min_time) { // if no eligible cell yet or current cell is better, we update
          min_time = min_times[j];
          min_time_index = j;
          found = 1;
        }
      }
    }
    if (!found) { //if no cell is found, we stop
      break;
    }
    done[min_time_index] = 1; // otherwise set identified cell to done and loop through outgoing edges to find shorter paths
    
    e = adj_list[min_time_index];
    
    while(e) {
      old_time = min_times[e->to_cell]; //loop through outgoing edges to see if we can improve any of the shortest paths for nodes
      if (old_time == -1 || old_time > min_time + e->length) { //if the new time is better or the old one doesnt exist, 
        min_times[e->to_cell] = min_time + e->length; // replace it
      }
      e = e->next;
    }
  }
  return min_times[exit_cell]; // return the shortest path to the exit cell
}

int main(void) {
  static edge *adj_list[MAX_CELLS + 1];
  int num_cases, case_num, i;
  int num_cells, exit_cell, time_limit, num_edges;
  int from_cell, to_cell, length;
  int total, min_time;
  edge *e;
  
  cin >> num_cases;
  for (case_num = 1; case_num <= num_cases; case_num++) {
    cin >> num_cells >> exit_cell >> time_limit;
    cin >> num_edges;
    
    for (i = 1; i <= num_cells; i++) { // clear adjacency list
      adj_list[i] = NULL;
    }
    
    for (i = 0; i < num_edges; i++) {
      cin >> from_cell >> to_cell >> length;
      e = new edge;
      if (e == NULL) {
        cout << "malloc error\n";
        exit(1);
      }
      e->to_cell = to_cell;
      e->length = length;
      e->next = adj_list[from_cell];
      adj_list[from_cell] = e;
    }
    total = 0;
    for (i = 1; i <= num_cells; i++) {
      min_time = find_time(adj_list, num_cells, i, exit_cell);
      if (min_time >= 0 && min_time <= time_limit) {
        total++;
      }
      cout << total << endl;
    }
  }
  return 0;
}
