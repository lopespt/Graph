cmake_minimum_required (VERSION 2.8)

# projectname is the same as the main-executable
project(graphs)

add_definitions('-g')
add_definitions('-Wall')
add_definitions('-std=c++11')

add_library(Graph  node.cpp edge.cpp graph.cpp)
add_executable(Grafos main.cpp)
target_link_libraries(Grafos Graph)

