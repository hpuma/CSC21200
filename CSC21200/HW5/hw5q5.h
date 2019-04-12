#ifndef __HEAP_H__
#define __HEAP_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 5 header file

// Try not to change this file

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cmath>

using namespace std;

template <class Item>
class Heap
{
public:
    const size_t DEF_CAP = 30;
    // CONSTRUCTOR
    Heap();

    size_t getCount() {return count;}

    // MODIFICATION MEMBER FUNCTIONS
    void insert(const Item& entry) {
		data[count] = INT_MIN;
		count++;
		increaseKey(count-1, entry);
	}
    void increaseKey(size_t i, const Item& entry);
    Item removeMax();

    void maxHeapify(const size_t& i);
    void buildMaxHeap();
    Item* heapsort();

    Item minimum();
    Item maximum();
    
private:
    Item* data;
    size_t count;
    size_t capacity;

    size_t parent(size_t i) {return floor(i/2);}
    size_t left  (size_t i) {return 2*i+1;}
    size_t right (size_t i) {return 2*i+2;}
};

template <class Item>
void swap(Item& x, Item& y) {
	Item temp = x;
	x = y;
	y = temp;
}

#endif