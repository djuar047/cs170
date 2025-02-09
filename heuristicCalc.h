#ifndef HEURISTICCALC_H
#define HEURISTICCALC_H
#include <iostream>
#include <vector>

using namespace std;

// The distance using the manhattan distance heuristic
int manhattanDistHeuristic(const vector<vector<int>>& state);

// the current state of the puzzle 
int misplacedTileHeuristic(const vector<vector<int>>& state);

// the number of tiles that are correct
int fixedTiles(const vector<vector<int>>& state);


#endif