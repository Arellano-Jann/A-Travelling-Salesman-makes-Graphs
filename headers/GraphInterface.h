#pragma once
#define GRAPHINTERFACE_H

template <typename T>
class GraphInterface{
public:
    virtual int getNumVertices() const = 0;
    virtual int getNumEdges() const = 0;

    virtual bool add(T start_label, T end_label, int edge_weight) = 0;
    virtual bool remove(T start_label, T end_label) = 0;

    virtual int getEdgeWeight(T start_label, T end_label) = 0;

    virtual void depthFirstTraversal(T start_label, void visit(T&)) = 0;
    virtual void breadthFirstTraversal(T start_label, void visit(T&)) = 0;
};