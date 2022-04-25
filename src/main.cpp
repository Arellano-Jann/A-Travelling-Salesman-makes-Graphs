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
    if (file) file.close();

    std::ofstream outfile;
    outfile.open("travelling_sailor.txt");

    std::vector<std::string> cities = graph.getLabels(); // used to get a vector of cities so life will be easier
    int num_cities = cities.size();

    int currentCheapest = INT_MAX;
    std::vector<int> smallestPath = {0,0,0,0,0};


    std::vector<std::string> allPermutations;
    std::string cityListByNum = "01234";
    do{
        allPermutations.push_back(cityListByNum);
    } while (std::next_permutation(cityListByNum.begin(), cityListByNum.end()));


    // for (int i = 0; i < allPermutations.size(); i++){
    //     std::vector<int> path = {0,0,0,0,0};
    //     std::vector<int> currentPath = {0,0,0,0,0};
    //     std::vector<int> currentPermutation = allPermutations[i];
    //     for (int j = 0; j < currentPermutation.size(); j++){
    //         std::string city = cities[currentPermutation[j]];
    //         std::vector<std::string> neighbors = graph.getNeighbors(city);
    //         for (int k = 0; k < neighbors.size(); k++){
    //             std::string neighbor = neighbors[k];
    //             int weight = graph.getEdgeWeight(city, neighbor);
    //             int index = std::find(cities.begin(), cities.end(), neighbor) - cities.begin();
    //             currentPath[index] = weight;
    //         }
    //     }
    //     for (int j = 0; j < currentPath.size(); j++){
    //         path[j] += currentPath[j];
    //     }
    //     if (path[0] < smallestPath[0]){
    //         smallestPath = path;
    //         currentCheapest = i;
    //     }
    // }


    // for (int first = 0; 
    //         first < graph.getNumVertices(); first++){
    //     for (int second = first; 
    //             second < graph.getNumVertices(); second++){
    //         for (int third = second; 
    //                 third < graph.getNumVertices(); third++){
    //             for (int fourth = third; 
    //                     fourth < graph.getNumVertices(); fourth++){
    //                 for (int fifth = fourth; 
    //                         fifth < graph.getNumVertices(); fifth++){  
                        
                        
    for (int i = 0; i < allPermutations.size(); i++){
        int first = allPermutations[i][0] - '0';
        int second = allPermutations[i][1] - '0';
        int third = allPermutations[i][2] - '0';
        int fourth = allPermutations[i][3] - '0';
        int fifth = allPermutations[i][4] - '0';

                        int currentPermutation = graph.getEdgeWeight(cities[first], cities[second]) + graph.getEdgeWeight(cities[second], cities[third]) + graph.getEdgeWeight(cities[third], cities[fourth]) + graph.getEdgeWeight(cities[fourth], cities[fifth]) + graph.getEdgeWeight(cities[fifth], cities[first]);

                        outfile << cities[first] << " -> " << cities[second] << " -> " << cities[third] << " -> " << cities[fourth] << " -> " << cities[fifth] <<  " -> " << cities[first] << " | Total Gallons of Dinosaur Blood: " << currentPermutation/mpg << " Miles: " << currentPermutation << std::endl;

                        // bool isValid = first != second && first != third && first != fourth && first != fifth && second != third && second != fourth && second != fifth && third != fourth && third != fifth && fourth != fifth;

                        // if (currentPermutation < currentCheapest && isValid){
                        if (currentPermutation < currentCheapest){
                            currentCheapest = currentPermutation;
                            smallestPath = {first, second, third, fourth, fifth};
                        }
                        
    }

    //                 }
    //             }
    //         }
    //     }
    // }

    outfile << "40 MPG CHEAPEST PRICE!!! : " << cities[smallestPath[0]] << " -> " << cities[smallestPath[1]] << " -> " << cities[smallestPath[2]] << " -> " << cities[smallestPath[3]] << " -> " << cities[smallestPath[4]] <<  " -> " << cities[smallestPath[0]] << " | Total Gallons of Dinosaur Blood: " << currentCheapest/mpg << " Miles: " << currentCheapest << std::endl;

    std::cout << "40 MPG CHEAPEST PRICE!!! : " << cities[smallestPath[0]] << " -> " << cities[smallestPath[1]] << " -> " << cities[smallestPath[2]] << " -> " << cities[smallestPath[3]] << " -> " << cities[smallestPath[4]] <<  " -> " << cities[smallestPath[0]] << " | Total Gallons of Dinosaur Blood: " << currentCheapest/mpg << " Miles: " << currentCheapest << std::endl;
    std::cout << "The above info is found at the bottom of travelling_sailor.txt" << std::endl;

    graph.depthFirstTraversal(cities[0], [](auto i) mutable { std::cout << i << " "; });
    graph.breadthFirstTraversal(cities[0], [](auto i) mutable { std::cout << i << " "; });


    // Prints
    // graph.printAdjecencyMatrix();
    // std::cout << "Graph size: " << graph.getNumVertices() << std::endl;
    // std::cout << "Graph edges: " << graph.getNumEdges() << std::endl;
    // for (int i = 0; i < graph.getLabels().size(); i++){
    //     std::cout << graph.getLabels()[i] << std::endl;
    // }

    return 0;
}