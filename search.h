#ifndef SEARCH_H
#define SEARCH_H

#include "node.h"
#include <iostream>
#include <vector>

using namespace std;

// search based on cost with h(n) being hardcoded to 0
Node* uniformCostSearch(vector<vector<int>> puzzle);

// search based on the function: f(n) = g(n) + h(n)
// The vector of vectors represents the puzzle and the heuristic will be used to determine
// the type of heuristic
Node* Astar(vector<vector<int>> puzzle, int heuristic);

#endif