#ifndef DFS_H
#define DFS_H

#include "directions.h"
#include <vector>

bool dfs(std::vector<std::vector<int>>& grid, int x, int y, std::vector<std::vector<bool>>& visited);
bool dfsPathfinding(std::vector<std::vector<int>>& grid);

#endif