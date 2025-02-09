#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <cmath>
#include <set>
#include "search.h"
#include "defaultPuzzle.h"


using namespace std;

int main() {

    int choice = 0;
    // vector initialized for the puzzle
    vector <vector<int>> matrix(3, vector<int>(3));
    //pointer to store the solved puzzle
    Node* solution = nullptr;

    cout << "This program will use different algorithms to solve the 8 tile puzzle." << endl;
    cout << "Enter [1] to use a preset puzzle" << endl;
    cout << "Enter [2] to enter your own puzzle" << endl;
    int pChoice = 0;
    cin >>pChoice;
    while (1) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>:: max(), '\n');
            cout << "You have entered an invalid choice" << endl;
            cin >> pChoice;
        }
        if (!cin.fail())
        break;
    }
    // loop to get user to choose from the following options
    while (pChoice != 1 && pChoice != 2) {
        cin.clear();
        cout << "Invalid choice, please try again!" << endl;
        cin >> pChoice;
    }
    if (pChoice == 1) {
        int depth;
        cout << "Select a difficulty: [1] Easy ----- [2] Medium ----- [3] Hard" << endl;
        cin >> depth;
        while (1) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>:: max(), '\n');
            cout << "You have entered an invalid choice" << endl;
            cin >> depth;
        }
        if (!cin.fail())
        break;
    }
    // loop to get user to choose from the following options
    while (depth != 1 && depth != 2 && depth != 3) {
        cin.clear();
        cout << "Invalid choice, please try again!" << endl;
        cin >> depth;
    }
        matrix = defaultPuzzle(depth);


    }
    else if (pChoice == 2) {
        cout << "Enter the puzzle you would like the program to solve." << endl;
    // user input will fill in the puzzle
     for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> matrix[i][j];
            }
        }

    }
    // Node nodeStart(nullptr, matrix, 0,0,0);
    // cout << "Puzzle beginning" << endl;
    // nodeStart.PrintPuzzle();
    
        //Choice between algorithms
    cout << "Select which algorithm to run" << endl;
    cout << "1. Uniform Cost Search" << endl;
    cout << "2. A-Star with the misplaced tile heuristic" << endl;
    cout << "3. A-Star with the Manhattan Distance Heuristic" << endl;
    cin >> choice;
    // prevents the user from selecting an incorrect option and breaking the program ';
    while (1) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>:: max(), '\n');
            cout << "You have entered an invalid choice" << endl;
            cin >> choice;
        }
        if (!cin.fail())
        break;
    }
    // loop to get user to choose from the following options
    while (choice != 1 && choice != 2 && choice != 3) {
        cin.clear();
        cout << "Invalid choice, please try again!" << endl;
        cin >> choice;
    }

    // starts timing
    clock_t start;
    start = clock();
    // Uniform cost search
    if (choice == 1) {
        cout << "You have chosen Uniform cost search!" << endl;
        cout << "------------------------------------" << endl;
        // Run UCS function
        solution = uniformCostSearch(matrix);


    }
    if (choice == 2) {
        cout << "You have chose A-Star with the misplaced tile heuristic" << endl;
        // for (int i = 0; i < 3; i++) {
        //     for (int j = 0; j < 3; j++) {
        //         cin >> matrix[i][j];
        //     }
        // }
        // Run A* function with misplaced tile heuristic
        solution = Astar(matrix, 1);

    }
    if (choice == 3) {
        cout << "You have chosen A-Star with the Manhattan Distance heuristic" << endl;
        // Run A* with manhattan distance heuristic
        solution = Astar(matrix, 2);
    }
    // End timer
    clock_t end;
    end = clock();
    // Make time in MS more readable
    double time = double(end - start) / CLOCKS_PER_SEC * 1000.0;

    // output Time and solution depth
    cout << "Time taken to find solution: " << time << " ms" << endl;
    cout << "Solution Depth: " << solution -> depth << endl;
    return 0;

}