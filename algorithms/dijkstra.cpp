#include "dijkstra.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

int dijkstraPathfinding(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (grid[0][0] == 9 || grid[rows - 1][cols - 1] == 9) {
        cout << "No paths available.\n";
        return -1;
    }

    vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
    distance[0][0] = 0;

    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        auto [currentDist, cell] = pq.top();
        pq.pop();
        int x = cell.first;
        int y = cell.second;

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

            if (isValid(nx, ny, rows, cols, grid)) {
                int newDist = currentDist + 1;

                if (newDist < distance[nx][ny]) {
                    distance[nx][ny] = newDist;
                    parent[nx][ny] = {x, y};
                    pq.push({newDist, {nx, ny}});
                }
            }
        }
    }

    cout << "No path available" << endl;
    return -1; // No path found
}