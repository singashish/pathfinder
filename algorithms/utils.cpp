#include "utils.h"
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <thread>

using namespace std;

void reconstructAndMarkPath(vector<vector<pair<int, int>>>& parent, vector<vector<int>>& grid, int x, int y) {
    while (x != -1 && y != -1) {
        grid[x][y] = 1;  // Mark path with 'P'
        printGrid(grid);
        int prev_x = parent[x][y].first;
        int prev_y = parent[x][y].second;
        x = prev_x;
        y = prev_y;
    }
}

void printGrid(const vector<vector<int>>& grid) {
    // Clear terminal (Linux/Mac). Use "cls" for Windows.
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear");  // Linux/Mac
    #endif

    int rows = grid.size(), cols = grid[0].size();
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (i == 0 && j == 0)
                cout << "💲";
            else if (i == grid.size()-1 && j == grid[0].size()-1)
                cout << "❌";
            else if (grid[i][j] == 9)
                cout << "🧱";  // Blocked cell
            else if (grid[i][j] == -1)
                cout << " ▪";  // Visited cell
            else if (grid[i][j] == 0)
                cout << "  ";  // Unvisited path
            else if (grid[i][j] == 1) {
                // Check for path continuation in different directions
                bool down = isValid(i+1, j, rows, cols, grid) && grid[i+1][j] == 1;
                bool up = isValid(i-1, j, rows, cols, grid) && grid[i-1][j] == 1;
                bool right = isValid(i, j+1, rows, cols, grid) && grid[i][j+1] == 1;
                bool left = isValid(i, j-1, rows, cols, grid) && grid[i][j-1] == 1;

                // Determine which symbol to display based on connections
                if (up && down && !left && !right)
                    cout << " │"; // Vertical line
                else if (!up && !down && left && right)
                    cout << "──"; // Horizontal line
                else if (down && right && !up && !left)
                    cout << " ┌"; // Top-left corner
                else if (down && left && !up && !right)
                    cout << "─┐"; // Top-right corner
                else if (up && right && !down && !left)
                    cout << " └"; // Bottom-left corner
                else if (up && left && !down && !right)
                    cout << "─┘"; // Bottom-right corner
                else if (down)
                    cout << " ↑"; // Down arrow
                else if (up)
                    cout << " ↓"; // Up arrow
                else if (right)
                    cout << " ←"; // Right arrow
                else if (left)
                    cout << " →"; // Left arrow
            }
        }
        cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(60));  // Frame delay
}

bool isValid(int x, int y, int rows, int cols, const vector<vector<int>>& grid) {
    return x >= 0 && y >= 0 && x < rows && y < cols && grid[x][y] != 9;
}