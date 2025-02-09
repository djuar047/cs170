#include "node.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>


//This node represts the state in the search tree
// Each node contains its parent, board state, cost, type of heuristic and depth.
Node::Node(Node* parent, vector <vector<int>> currState, int cost, int heuristic, int currDepth) 
: parent(parent), state(currState), cost(cost), heuristic(heuristic), depth(currDepth) {}

// destructor
Node::~Node() {
    for (Node* child : explore()) {
        delete child;
    }
}
// void Node::PrintPuzzle() {
//     for(int i = 0; i < 3; i++) {
//         for(int j = 0; j < 3;j++) {
//             if (state[i][j]==0) {
//                 cout << "0"; 
//             }
//             else {
//                 cout << state[i][j] << " ";
//             }
//         }
//         cout << endl;
//     }
//     cout << "-----------------" << endl;
// }
//Checks wether the state of the puzzle matches the solved puzzle, if not it returns false.
bool Node::solvedPuzzle() {
    vector<vector<int>> goal = {
        {1,2,3},
        {4,5,6},
        {7,8,0}
        };
        return state == goal;
}

// Converts the puzzle into a string to be used in a hashmap
// This string represents the puzzle's current state
string Node::puzzletoString() {
    stringstream puzzleBoard;

    int rows = state.size();
    int columns = state[0].size();

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            int x = state[i][j];
            puzzleBoard << x;
        }
    }
    return puzzleBoard.str();
}

// The operators can move the empty tile: up, down, left, right
vector<Node*> Node::explore() {
    // list all possible states
    vector<Node*> children;
    // coordinates of the blank tile (0)
    int emptyX = 0;
    int emptyY = 0;
    // locate the blank tile
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3;j++) {
            if (state[i][j]== 0) {
                emptyX = i;
                emptyY = j;
            }
        }
    }

// operators
vector<pair<int, int>> movesAllowed = {
    {-1,0},
    {1, 0},
    {0,-1},
    {0,1},
};
int sizeofMoves = movesAllowed.size();
// loop through each possible move
for (int i = 0; i < sizeofMoves; i++) {
    int Xpos = emptyX + movesAllowed[i].first;
    int Ypos = emptyY + movesAllowed[i].second;
// check wether the move is legal or not
    if (Xpos >= 0 && Xpos < 3 && Ypos >= 0 && Ypos < 3) {
        // copy the current puzzle
        vector<vector<int>> newState = state;
        // swap tiles
        swap(newState[emptyX][emptyY], newState[Xpos][Ypos]);
        // create new child with updated cost, depth values
        Node* child = new Node(this, newState, cost + 1, 0, depth + 1);
        // add to list of expanded nodes
        children.push_back(child);
    }
}
return children;
}

