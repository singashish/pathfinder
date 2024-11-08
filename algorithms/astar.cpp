#include "astar.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); // Manhattan distance
}

int aStarPathfinding(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (grid[0][0] == 9 || grid[rows - 1][cols - 1] == 9) {
        cout << "No path available" << endl;
        return -1;
    }

    vector<vector<int>> gScore(rows, vector<int>(cols, INT_MAX));
    gScore[0][0] = 0;

    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        auto [fScore, cell] = pq.top();
        pq.pop();
        int x = cell.first;
        int y = cell.second;

        if (grid[x][y] != 1) { // Mark as visited but avoid marking final path twice
            grid[x][y] = -1; // Mark as visited with '.'
            printGrid(grid);
        }

        if (x == rows - 1 && y == cols - 1) {
            reconstructAndMarkPath(parent, grid, x, y);
            return gScore[x][y];
        }

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (isValid(nx, ny, rows, cols, grid) && grid[nx][ny] == 0) {
                int tentativeGScore = gScore[x][y] + 1;
                if (tentativeGScore < gScore[nx][ny]) {
                    gScore[nx][ny] = tentativeGScore;
                    int hScore = heuristic(nx, ny, rows - 1, cols - 1);
                    parent[nx][ny] = {x, y};
                    pq.push({tentativeGScore + hScore, {nx, ny}});
                }
            }
        }
    }

    cout << "No path available" << endl;
    return -1; // No path found
}