#include "search.h"
#include "heuristicCalc.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <queue>
#include <cmath>
#include <set>
#include <unordered_map>

using namespace std;

// This struct is used to check cost and heuristic
struct CheckNodes {
    bool operator()(Node* a, Node* b) {
        // mini heap
        return (a->cost + a->heuristic) > (b->cost + b->heuristic);
    }
};

//A - star search with either misplaced tile heuristic or manhattan distance heuristic
Node* Astar(vector<vector<int>> puzzle, int heuristicChoice) {
    // Check which heuristic is needed
    int heuristicValue; 
    if (heuristicChoice == 1) {
        heuristicValue = misplacedTileHeuristic(puzzle);
    }
    else {
        heuristicValue = manhattanDistHeuristic(puzzle);
    }
    // Create a root node with the initial state and cost, depth
    Node* nodeStart = new Node(nullptr, puzzle, 0, heuristicValue, 0);

    // mini heap
    priority_queue<Node*, vector<Node*>, CheckNodes> queueing;
    // Used to track the nodes that have been visisted
    unordered_map<string, bool> Visited;

    // push the first node into the queue
    queueing.push(nodeStart);
    // size of queue and nodes counters initialized
    int maxqSize = 0;
    int expandedNodesCount = 0;
    // A star search 
    while (!queueing.empty()) {
        int qSize = queueing.size();
        if (qSize > maxqSize) {
            maxqSize = qSize;
        }
        // Get the node with the least cost and the estimated distance to the goal
        //(optimal and complete as well as fast)
        Node* currNode = queueing.top();
        queueing.pop();
        // cout << "Current Node Cost " << currNode -> cost << endl;
        // currNode -> PrintPuzzle();
        // Check if the puzzle has been solved
        if (currNode -> solvedPuzzle()) {
            // output data
            cout << "Solution found using A-star: " << endl;
            cout << "Max queue size: " << maxqSize << endl;
            cout << "Nodes expanded: " << expandedNodesCount << endl;
            return currNode;
        }
        // mark current location as visited
        Visited[currNode -> puzzletoString()] = true;
        // increment 
        expandedNodesCount++;

        // expand further down the tree
        vector <Node*> children = currNode -> explore();
        for (int i = 0; i < children.size(); i++) {
            Node* child = children[i];
            int childHeuristic;
            // Determine which heuristic is being used
            if(heuristicChoice == 1) {
                // misplaced tile
                childHeuristic = misplacedTileHeuristic(child -> state);
            }
            else {
                // manhattan distance
                childHeuristic = manhattanDistHeuristic(child -> state);
            }
            // assign the heuristic to the child node
            child -> heuristic = childHeuristic;
            // add to queue if this state is new
            if (Visited.find(child -> puzzletoString()) == Visited.end()) {
                queueing.push(child);
            }
        }
    }
    // no solution
    cout << "Could not find a solution, please try again!" << endl;
    return nullptr;
}

//uniform cost search 
Node* uniformCostSearch(vector<vector<int>> puzzle) {
    // new root node with no cost values
    Node* nodeStart = new Node(nullptr, puzzle, 0, 0 ,0);
    // use a mini heap to store nodes based on cost
    priority_queue<Node*, vector<Node*>, CheckNodes> queueing;

    //This map will track nodes already visited to prevent them from getting visited again
    unordered_map<string, bool> Visited;
    // push node to queue
    queueing.push(nodeStart);
    // size of queue and expanded nodes counter
    int maxqSize = 0;
    int expandedNodesCount = 0;

// loop to expand the nodes based on their cost (g)
while (!queueing.empty()) {
    // max queue size tracking
    int qSize = queueing.size();
    if (qSize > maxqSize) {
        maxqSize = qSize;
    }
    // Get the node with the lowest cost 
    Node* currNode = queueing.top();
    // queueing.pop();
    // cout << "Current node cost: " << currNode -> cost << endl;
    // currNode -> PrintPuzzle();

    // check if the puzzle has been solved
    if (currNode -> solvedPuzzle()) {
        // solution found 
        // return the queue size, node count and the current node
        cout << "Puzzle has been solved using Uniform Cost Search" << endl;
        cout << "Max queue size: " << maxqSize << endl;
        cout << "Nodes expanded: " << expandedNodesCount << endl;
        return currNode;
    }
    // mark the current state as visited
    Visited[currNode -> puzzletoString()] = true;
    expandedNodesCount++;
    // expand child nodes
    vector<Node*> children = currNode -> explore();

    // this loop will add to the current queue if the puzzle state has not been visited
    for(int i = 0; i < children.size(); i++) {
        Node* child = children[i];
        if (Visited.find(child -> puzzletoString()) == Visited.end()) {
            queueing.push(child);
        }
    }
}
// no solution found
cout << "Could not find a solution to this problem, try again!" << endl;
return nullptr;
}

