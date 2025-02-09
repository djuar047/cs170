#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
    public:
    // puzzle board
    vector<vector<int>> state;
    //pointer to parent node
    Node* parent;
    // path cost
    int cost;
    // type of heuristic
    int heuristic;
    // depth of the tree
    int depth;

    Node(Node* parent, vector<vector<int>> currState, int cost, int heuristic, int currDepth);
    // destructor
    ~Node();

    // check is the puzzle has been solved
    bool solvedPuzzle();
    // search down the tree
    vector<Node*> explore();
    // covert to string
    string puzzletoString();

    // void PrintPuzzle();
};

#endif