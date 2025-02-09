#include "heuristicCalc.h"
#include <iostream>
#include <vector>
#include <cmath>
// Solved state for the puzzle
const vector<vector<int>> goal = {
        {1,2,3},
        {4,5,6},
        {7,8,0}
        };

// Counts the number of tiles that are misplaced
// does not count the tile with 0
int misplacedTileHeuristic(const vector<vector<int>>& state) {
    int count = 0;
    // counts the number of misplaced tiles
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            // checks if the tiles are empty and if it matches the solved puzzle.
            // Tile with 0 is excluded
            if (state[i][j] != 0 && state[i][j] != goal[i][j]) {
                count++;
            }
        }
    }
    return count;
}

// Uses this calculation |x_1 - x_2| + |y_1 - y_2|
int manhattanDistHeuristic(const vector<vector<int>>& state) {
    int distance = 0;
    // loop through the puzzle board
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            // do not count the tile with "0"
            if (state[i][j] != 0) {
                int val = state[i][j] - 1;
                // row of the solved puzzle
                int solvedX = val / 3;
                // column of the puzzle
                int solvedY = val % 3;
                //Manhattan distance calculation
                // |x_1 - x_2| + |y_1 - y_2|
                distance += abs(i - solvedX) + abs(j - solvedY);
            }
        }
    }
    // return the manhattan distance
    return distance;
}