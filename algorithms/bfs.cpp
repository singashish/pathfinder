#include "bfs.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int bfsPathfinding(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (grid[0][0] == 9 || grid[rows - 1][cols - 1] == 9) {
        cout << "Path not available.\n";
        return -1;}

    vector<vector<int>> distance(rows, vector<int>(cols, -1));
    distance[0][0] = 0;

    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (grid[x][y] != 1) { // Mark as visited but avoid marking final path twice
            grid[x][y] = -1; // Mark as visited with '.'
            printGrid(grid);
        }

        if (x == rows - 1 && y == cols - 1) {
            reconstructAndMarkPath(parent, grid, x, y);
            return distance[x][y];
        }

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (isValid(nx, ny, rows, cols, grid) && distance[nx][ny] == -1) {
                distance[nx][ny] = distance[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    cout << "No path available" << endl;
    return -1; // No path found
}

