#include "bellman_ford.h"
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> bellmanFord(int vertices, int start, const vector<Edge>& edges) {
    vector<int> distance(vertices, INT_MAX);
    distance[start] = 0;

    for (int i = 0; i < vertices - 1; ++i) {
        for (const auto& edge : edges) {
            if (distance[edge.from] != INT_MAX && distance[edge.from] + edge.weight < distance[edge.to]) {
                distance[edge.to] = distance[edge.from] + edge.weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        if (distance[edge.from] != INT_MAX && distance[edge.from] + edge.weight < distance[edge.to]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return {};
        }
    }

    return distance;
}