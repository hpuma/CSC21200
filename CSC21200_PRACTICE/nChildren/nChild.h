#ifndef N_CHILD_NODE_H
#define N_CHILD_NODE_H

#include <iostream>

using namespace std;

template<class Item>
class nChild{
public:
	const size_t DEF_CAP=30;
	// CONSTRUCTOR
	nChild(const Item& initData=Item()){
		children = new nChild<Item>*[DEF_CAP];
		capacity = DEF_CAP;
		data = initData;
		count = 0;
		for(size_t i = 0; i < capacity; i++){
			children[i] = NULL;
		}
	}
	// CONSTANT MEMBER FUNCTIONS.
	Item getData() const{ return data;}
	nChild<Item>** getChildren() const{ return children;} // Returns Array containing pointers to children.
	bool isEmpty() const{ return (count == 0);}
	size_t size() const{ return count;}

	// MODIFICATION MEMBER FUNCTIONS.
	void setData(Item newData){data = newData;}
	void addChild(nChild<Item>* newChild){
		children[count] = newChild;
		count++;
	}
	nChild<Item>* getChild(size_t i){
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