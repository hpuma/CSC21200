#ifndef N_CHILD_NODE_H
#define N_CHILD_NODE_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

template<class Item>
class nChild{
public:
	const size_t DEF_CAP=30;
	// CONSTRUCTOR
	nChild(const Item& initData=Item()){
		children = new nChild<Item>*[DEF_CAP]; // Make Dyanimic array with pointers to nChild<Item> node.
		capacity = DEF_CAP;
		data = initData;
		count = 0;
		for(size_t i = 0; i < capacity; i++){ // Set all the nChild<Item> pointers to NULL.
			children[i] = NULL;
		}
	}
	// CONSTANT MEMBER FUNCTIONS.
	Item getData() const{ return data;} // Get the value of the node
	nChild<Item>** getChildren() const{ return children;} // Returns array containing pointers to children.
	bool isEmpty() const{ return (count == 0);} // Checks whether or not the array of children are empty.
	size_t size() const{ return count;}  // Returns the number of chuldren that this node has.

	// MODIFICATION MEMBER FUNCTIONS.
	void setData(Item newData){data = newData;} // Changes the data of this node.
	void addChild(nChild<Item>* newChild){ // Adds a node to the list of this node's children.
		children[count] = newChild;
		count++;
	}
	nChild<Item>* getChild(size_t i){ // Gets the children at a specific position in the array of children.
		if((i >= 0) && (i < count)){
			return children[i];
		}
		return NULL;
	}

	private:
	Item data;
	nChild<Item>** children;
	size_t capacity;
	size_t count;

};
#endif