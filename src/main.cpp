#include "../headers/Graph.h"
// #include "../headers/GraphNode.h"

#include <iostream>
#include <fstream>

int main(){
    int mpg = 40;
    Graph<std::string> graph;
    // graph.add("A", "B", mpg);
    // graph.printAdjecencyMatrix();

    std::ifstream file;
    file.open("cities.txt");
    std::string city1;
    std::string city2;
    int distance;
    while (file >> city1 >> city2 >> distance){
        graph.add(city1, city2, distance);
    }
    graph.printAdjecencyMatrix();
    return 0;
}