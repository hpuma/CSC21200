#ifndef __GRAPHM_H__
#define __GRAPHM_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 6 header file

// Try not to change this file

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <iomanip>

using namespace std;

template <class Item>
class graphM
{
public:
    // MEMBER CONSTANTS
    const size_t DEF_CAP = 30;
    // CONSTRUCTOR
    graphM();
    graphM(const graphM<Item>& source);
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
    Item* neighbors(size_t vertex) const;
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
    int** matrix;
    size_t count;
    size_t capacity;
};

template <class Item>
Item* resize(Item* ar, size_t count) {
	Item* newAr = new Item[count];
	for(size_t i = 0; i < count; i++)
		newAr[i] = ar[i];
	return newAr;
}

#include "hw6q1.cpp"
#endif