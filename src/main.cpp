#include "../headers/Graph.h"
// #include "../headers/GraphNode.h"

#include <iostream>

int main(){
    int mpg = 40;
    Graph<std::string> graph;
    graph.add("A", "B", mpg);
    return 0;
}