#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <utility>

void reconstructAndMarkPath(std::vector<std::vector<std::pair<int, int>>>& parent, std::vector<std::vector<int>>& grid, int x, int y);
void printGrid(const std::vector<std::vector<int>>& grid);
bool isValid(int x, int y, int rows, int cols, const std::vector<std::vector<int>>& grid);

#endif