#include "dfs.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool dfs(vector<vector<int>>& grid, int x, int y, vector<vector<pair<int, int>>>& parent) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (grid[0][0] == 9 || grid[rows - 1][cols - 1] == 9) {
        cout << "No path available" << endl;
        return false;
    }

    if (x == rows - 1 && y == cols - 1) {
        return true;  // Reached destination
    }

    if (grid[x][y] != 1) { // Mark as visited but avoid marking final path twice
        grid[x][y] = -1; // Mark as visited with '.'
        printGrid(grid);
    }

    for (auto [dx, dy] : directions) {
        int nx = x + dx;
        int ny = y + dy;

        if (isValid(nx, ny, rows, cols, grid) && grid[nx][ny] != -1) {
            if (dfs(grid, nx, ny, parent)) {
                parent[nx][ny] = {x, y};
                return true;
            }
        }
    }

    cout << "No path available" << endl;
    return false;  // No path found from this cell
}

bool dfsPathfinding(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));

    if (dfs(grid, 0, 0, parent)) {
        reconstructAndMarkPath(parent, grid, rows - 1, cols - 1);
        return true;
    }
    return false;
}