#include <iostream>
#include <vector>
#include "algorithms.h"

using namespace std;

int main() {
    vector<vector<int>> grid0 = {
        {0, 0, 0, 9, 0, 0, 9, 0, 0, 0},
        {9, 9, 0, 9, 0, 9, 9, 9, 9, 0},
        {0, 0, 0, 0, 0, 0, 0, 9, 0, 0},
        {0, 9, 9, 9, 9, 9, 0, 9, 9, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 9, 0, 9, 9, 9, 9, 9, 0, 9},
        {0, 9, 0, 0, 0, 0, 0, 9, 0, 0},
        {0, 9, 9, 9, 9, 9, 0, 9, 9, 0},
        {0, 0, 0, 0, 0, 9, 0, 0, 0, 0},
        {9, 9, 9, 9, 0, 9, 9, 9, 9, 0}
    };

    vector<vector<int>> grid = {
        {0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9},
        {9, 0, 9, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 9, 0, 9, 9, 9, 0, 9},
        {9, 0, 9, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9, 0, 9, 0, 0, 0, 9},
        {9, 0, 9, 9, 9, 9, 9, 0, 9, 0, 9, 9, 9, 9, 9, 0, 9, 0, 9, 9, 9},
        {9, 0, 9, 0, 0, 0, 9, 0, 9, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 9},
        {9, 0, 9, 0, 9, 0, 9, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 9},
        {9, 0, 0, 0, 9, 0, 9, 0, 9, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9},
        {9, 9, 9, 9, 9, 0, 9, 0, 9, 0, 9, 9, 9, 0, 9, 0, 9, 9, 9, 9, 9},
        {9, 0, 0, 0, 0, 0, 9, 0, 9, 0, 0, 0, 9, 0, 9, 0, 0, 0, 0, 0, 9},
        {9, 0, 9, 9, 9, 9, 9, 0, 9, 9, 9, 0, 9, 0, 9, 9, 9, 9, 9, 0, 9},
        {9, 0, 0, 0, 0, 0, 9, 0, 9, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 9},
        {9, 9, 9, 9, 9, 0, 9, 0, 9, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 0, 0, 0, 0, 0, 9, 0, 9, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
        {9, 0, 9, 9, 9, 9, 9, 0, 9, 0, 9, 0, 9, 9, 9, 9, 9, 9, 9, 0, 9},
        {9, 0, 9, 0, 0, 0, 0, 0, 9, 0, 9, 0, 9, 0, 0, 0, 0, 0, 9, 0, 9},
        {9, 0, 9, 0, 9, 9, 9, 9, 9, 0, 9, 0, 9, 0, 9, 9, 9, 0, 9, 0, 9},
        {9, 0, 9, 0, 0, 0, 9, 0, 0, 0, 9, 0, 9, 0, 9, 0, 0, 0, 0, 0, 9},
        {9, 0, 9, 9, 9, 0, 9, 0, 9, 9, 9, 0, 9, 0, 9, 9, 9, 9, 9, 9, 9},
        {9, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0}
    };


    std::vector<std::vector<int>> grid1(10, std::vector<int>(10, 0));

    // Clearing the window first
    #ifdef _WIN32
        system("chcp 65001 && cls");  // Windows
    #else
        system("clear");  // Linux/Mac
    #endif

    cout << "Select a pathfinding algorithm:\n";
    cout << "1. Breadth-First Search (BFS)\n";
    cout << "2. Depth-First Search (DFS)\n";
    cout << "3. Dijkstra's Algorithm\n";
    cout << "4. A* Algorithm\n";
    cout << "5. Bellman-Ford Algorithm\n";
    cout << "6. Floyd-Warshall Algorithm\n";
    cout << "Enter your choice (1-6): ";
    int choice;
    cin >> choice;

    int result = -1;
    switch (choice) {
        case 1:
            result = bfsPathfinding(grid);
            cout << "\nDistance using BFS: " << result << endl;
            break;
        case 2:
            result = dfsPathfinding(grid);
            cout << "\nDistance using DFS: " << result << endl;
            break;
        case 3:
            result = dijkstraPathfinding(grid);
            cout << "\nDistance using Dijkstra's Algorithm: " << result << endl;
            break;
        case 4:
            result = aStarPathfinding(grid);
            cout << "\nDistance using A* Algorithm: " << result << endl;
            break;
        case 5:
            //result = bellmanFord(grid);
            cout << "\nDistance using Bellman-Ford Algorithm: " << result << endl;
            break;
        case 6:
            floydWarshall(grid);
            cout << "\nDistance using Floyd-Warshall Algorithm (all pairs):" << endl;
            // printGrid(grid);
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    return 0;
}