#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include <vector>

struct Edge {
    int from, to, weight;
};

std::vector<int> bellmanFord(int vertices, int start, const std::vector<Edge>& edges);

#endif