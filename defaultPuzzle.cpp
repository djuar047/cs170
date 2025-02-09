#include "defaultPuzzle.h"

vector<vector<int>> defaultPuzzle(int depth) {
    if (depth == 1) {
        return {{1,2,3},{4,5,6},{0,7,8}};
    }
    else if (depth == 2) {
        return {{1,3,6},{5,0,7},{4,8,2}};
    }
    else if (depth == 3) {
        return {{0,7,2},{4,6,1},{3,5,8}};
    }
    else
    cout << "An error occured, terminating program!" << endl;
    return {
        {1,2,3},
        {4,5,6},
        {7,8,0}
        };

}