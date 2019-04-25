#ifndef __GRAPHL_H__
#define __GRAPHL_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 6 header file

// Try not to change this file

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include "node.h"

using namespace std;

class graphData
{
public:
	graphData() {;}
	graphData(const size_t& inV, const int& inW) {vertex = inV; weight = inW;}
	void setV(const size_t& inV) {vertex = inV;}
	void setW(const int& inW) {weight = inW;}
	size_t getV() const {return vertex;}
	int getW() const {return weight;}
	void operator=(const graphData& entry) {vertex = entry.vertex; weight = entry.vertex;}
	bool operator== (const size_t& target) {return vertex == target;}

private:
	size_t vertex;
	int weight;
};

std::ostream & operator << (std::ostream &out, const graphData& c) 
{ 
    out << '(' << c.getV() << '/' << c.getW() << ')'; 
    return out; 
} 

template <class Item>
class graphL
{
public:
	// MEMBER CONSTANTS
    const size_t DEF_CAP = 30;
    // CONSTRUCTOR
    graphL();
    graphL(const graphL<Item>& source);
    // MODIFICATION MEMBER FUNCTIONS
    void addVertex(const Item& inLabel);
    void addEdge(size_t source, size_t target, int weight);
    void removeEdge(size_t source, size_t target);
    Item& operator [ ] (size_t vertex) 
        { assert(vertex < count);
          return label[vertex]; }
    // CONSTANT MEMBER FUNCTIONS
    void print() const;
    size_t numVertices() const;
    size_t numEdges() const;
    bool isEdge(size_t source, size_t target) const;
    node<Item>* neighbors(size_t vertex) const;
    size_t index(const Item& target) const 
        { for(size_t i = 0; i < count; i++) {
            if(label[i] == target)
                return i; } 
          return count; }
    Item operator[ ] (size_t vertex) const
        { assert(vertex < count);
          return label[vertex]; }
private:
    Item* label;
    node<graphData>** list;
    size_t count;
    size_t capacity;
};

#include "hw6q2.cpp"
#endif