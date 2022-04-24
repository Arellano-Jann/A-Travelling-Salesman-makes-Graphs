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
        graph.add(city2, city1, distance);
    }


    // Prints
    graph.printAdjecencyMatrix();
    std::cout << "Graph size: " << graph.getNumVertices() << std::endl;
    std::cout << "Graph edges: " << graph.getNumEdges() << std::endl;
    for (int i = 0; i < graph.getLabels().size(); i++){
        std::cout << graph.getLabels()[i] << std::endl;
    }

    return 0;
}