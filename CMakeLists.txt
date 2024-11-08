cmake_minimum_required(VERSION 3.10)
project(Pathfinder)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the algorithms and utils source files
add_executable(Pathfinder
    main.cpp
    algorithms/bfs.cpp
    algorithms/dfs.cpp
    algorithms/dijkstra.cpp
    algorithms/astar.cpp
    algorithms/bellman_ford.cpp
    algorithms/floyd_warshall.cpp
    algorithms/directions.cpp
    algorithms/utils.cpp
)

# Include directories
target_include_directories(Pathfinder PUBLIC algorithms .)