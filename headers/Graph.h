#pragma once
/**
 * Adjacency list-based graph implementation
 * T refers to the type of the unique labels
 */
#define GRAPH_H

#include "GraphInterface.h"
// #include "GraphNode.h"
#include <climits> // INT_MAX
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>

template <typename T>
class Graph : public GraphInterface<T>{
private:
    std::vector<T> labels; // holds all the keys/labels
    // std::vector<std::vector<GraphNode<T>>> adjacency_list; // the "values" for our pseudo-map
    std::vector<std::vector<int>> adjacencyMatrix; // holds edge weight

    int vertexCount = 0;
    int edgeCount = 0;
protected:
    int getLabelIndex(T label) const; // get index of label in labels
    // int getSublistIndex(T major_label, T minor_label) const; // get index of node in major_label's adjacency sublist

    void depthTraversalHelper(T label, void visit(T&), bool* seen_arr, std::stack<T>& label_stack);
    void breadthTraversalHelper(T label, void visit(T&), bool* seen_arr, std::queue<T>& label_queue);
public:
    int getNumVertices() const override;
    int getNumEdges() const override;

    bool add(T startLabel, T endLabel, int edgeWeight) override;
    bool remove(T startLabel, T endLabel) override;

    int getEdgeWeight(T startLabel, T endLabel) override;

    void depthFirstTraversal(T startLabel, void visit(T&)) override; // layer search
    void breadthFirstTraversal(T startLabel, void visit(T&)) override; // deep search

    // some print functions
    void printAdjecencyMatrix() const;
    std::vector<T> getLabels() const;
};

#include "../src/Graph.cpp"
