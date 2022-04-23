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
    std::vector<std::vector<int>> adjacency_matrix; // holds edge weight

    int vertex_count = 0;
    int edge_count = 0;
protected:
    int getLabelIndex(T label) const; //get index of label in label list, -1 if not present
    // int getSublistIndex(T major_label, T minor_label) const; // get index of node in major_label's adjacency sublist

    void depthTraversalHelper(T label, void visit(T&), bool* seen_arr, std::stack<T>& label_stack);
    void breadthTraversalHelper(T label, void visit(T&), bool* seen_arr, std::queue<T>& label_queue);
public:
    int getNumVertices() const override;
    int getNumEdges() const override;

    bool add(T start_label, T end_label, int edge_weight) override;
    bool remove(T start_label, T end_label) override;

    int getEdgeWeight(T start_label, T end_label) override;

    void depthFirstTraversal(T start_label, void visit(T&)) override;
    void breadthFirstTraversal(T start_label, void visit(T&)) override;

    // not normally available as part of the graph ADT but extremely helpful
    void printAdjacencyList() const;
    std::vector<T> getLabels() const;
};

#include "../src/Graph.cpp"
