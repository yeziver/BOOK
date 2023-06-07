#include <cstdint>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX_LANGS 101
#define WORD_LENGTH 16

typedef struct edge {
  int to_lang, cost;
  struct edge *next;
} edge;

typedef int board[MAX_LANGS];
typedef int positions[MAX_LANGS];

int find_lang(string langs[], string lang) {
  int i = 0;
  while (langs[i] != lang) {
    i++;
  }
  return i;
}

void add_position(int from_lang, int to_lang, positions new_positions, int *num_new_positions, board min_moves) {
  if (min_moves[to_lang] == -1) {
    min_moves[to_lang] = 1 + min_moves[from_lang]; // same recursive structure in previous BFS codes !!
    
    new_positions[*num_new_positions] = to_lang;
    (*num_new_positions)++;
  }
}

void find_distances(edge *adj_list[], int num_langs, board min_costs) { // min_costs stores min cost edge that can be used to discover the langauge
  static board min_moves; // initialization from here
  static positions cur_positions, new_positions;
  int num_cur_positions, num_new_positions;
  int i, from_lang, added_lang, best;
  edge *e;
  for (i = 0; i < num_langs; i++) {
    min_moves[i] = -1;
    min_costs[i] = -1;
  }
  
  min_moves[0] = 0;
  cur_positions[0] = 0;
  num_cur_positions = 1;
  
  while (num_cur_positions > 0) {
    num_new_positions = 0;
    for (i = 0; i < num_cur_positions; i++) { // looping through current positions
      from_lang = cur_positions[i];
      e = adj_list[from_lang]; // tries each possible move
      
      while (e) {
        add_position(from_lang, e->to_lang, new_positions, &num_new_positions, min_moves);
        e = e->next;
      }
    }
    
    for (i = 0; i < num_new_positions; i++) {
      added_lang = new_positions[i]; // each of the new positions
      e = adj_list[added_lang];
      best = -1;
      
      while (e) {
        if (min_moves[e->to_lang] + 1 == min_moves[added_lang] &&
            (best == -1 || e->cost < best)) { //finds cheapest edge between added_lang and any new node
          best = e->cost;
        }
        e = e->next;
      }
      min_costs[added_lang] = best;
    }
    num_cur_positions = num_new_positions;
    for (i = 0; i < num_cur_positions; i++) {
      cur_positions[i] = new_positions[i];
    }
  }
}

void solve(int num_langs, board min_costs) {
  int i, total = 0;
  for (i = 1; i < num_langs; i++) {
    if (min_costs[i] == -1) {
      cout << "Impossible" << endl;
      return;
    } else {
      total = total + min_costs[i];
    }
    cout << total << endl;
  }
}

int main(void) {
  static edge *adj_list[MAX_LANGS] = {NULL};
  static string lang_names[MAX_LANGS];
  int i, num_targets, num_translators, cost, from_index, to_index;
  string from_lang, to_lang;
  edge *e;
  static board min_costs; // IMPORTANT! stored in here is the min cost edge that could be used to discover a language
  cin >> num_targets >> num_translators;
  lang_names[0] = "English";
  
  for (i = 1; i < num_targets; i++) {
    cin >> lang_names[i]; // map each integer to language names as we read them
  }
  
  for (i = 0; i < num_translators; i++) {
    cin >> from_lang;
    cin >> to_lang;
    cin >> cost;
    from_index = find_lang(lang_names, from_lang); // indexes are found by find_lang, which searches for a given language name
    to_index = find_lang(lang_names, to_lang);
    e = new edge;
    if (e == NULL) {
      cout << "malloc error\n";
      exit(1);
    }
    e->to_lang = to_index;
    e->cost = cost;
    e->next = adj_list[from_index];
    adj_list[from_index] = e; // add an edge, from_index to to_index
    e = new edge;
    if (e == NULL) {
      cout << "malloc error\n";
      exit(1);
    }
    e->to_lang = from_index;
    e->cost = cost;
    e->next = adj_list[to_index];
    adj_list[to_index] = e; // add another edge, to_index to from_index
  }
  find_distances(adj_list, num_targets + 1, min_costs);
  solve(num_targets + 1, min_costs);
  return 0;
}
