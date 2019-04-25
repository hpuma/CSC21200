#ifndef __HEAP_CPP__
#define __HEAP_CPP__
#include "hw5q5.h"
// NOTE ... the root index
template<class Item>
Heap<Item>::Heap(){
	capacity = DEF_CAP;
	data = new Item[capacity];
	count = 0;
}

template<class Item>
void Heap<Item>::increaseKey(size_t i, const Item& entry){
	assert(getCount() > 0); // Make sure that the tree is not empty.

	if(entry > data[i]){ // Make sure that the entry is greater than the current key.
		data[i] = entry; // Change the key to entry
		maxHeapify(i); // Restore the Max heap property.	
	}
}

template<class Item>
Item Heap<Item>::removeMax(){
	assert(getCount() > 0); //Make sure the heap is not empty.
	Item maxItem = data[0]; // Store the root value.
	data[0] = data[getCount()-1]; // Move the last item in the dynamic array data to the head.
	count--;
	maxHeapify(0); // Restore the maxHeap property from the root again.
	return maxItem; // Return the value that was stored at the root of the tree.
}

template<class Item>
void Heap<Item>::maxHeapify(const size_t& i){
	size_t largest = i;

	if (left(i) <= getCount() && data[left(i)] > data[i]){
		largest = left(i);
	}
	else{
		largest = i;  
	}
	if(right(i) <= getCount() && data[right(i)] > data[i]){
		largest = right(i); 
	}
	if(largest != i){ 
		swap(data[i],data[largest]); 
		maxHeapify(largest);
	}

}

template<class Item>
void Heap<Item>::buildMaxHeap(){
	size_t index = getCount();

	for (size_t i = getCount()-1; i >= 1; i--){
		swap(data[0],data[i]);
		index--;
		maxHeapify(0);
	}
}

template<class Item>
Item* Heap<Item>::heapsort(){
	Item* newHeap = new Heap<Item>();

	for (size_t i = 0 ; i < getCount(); i++){
		newHeap->insert(data[i]);
	}

	newHeap->buildMaxHeap();

	size_t index = getCount();
	while (index > 1){
		index--;
		Item temp = data[0];
		newHeap[0] = newHeap[index];
		newHeap[index] = temp;
		newHeap.maxHeapify(index);
	}
	return newHeap;

}
//NOTE: STILL MUST TAKE INTO ACCOUNT IF IT'S NOT A FULL TREE??
template<class Item>
Item Heap<Item>::minimum(){
	assert(count > 0);
	Item minimumVal = INT_MAX; // Used to compare for min value.
	size_t newDepth = 0; // The depth - 1, we want to iterate up to the nodes in this depth.
	size_t numNodes = 0; // The amount of nodes we are going to iterate through
	if(count > 1){ // When the COUNT is not 1. COUNT 1 is a special case.
		newDepth = floor(log2(count)) - 1;
	}
	for (size_t i = 0 ; i <= newDepth; i++){ // Computes the amount of Nodes we are going to iterate through.
		numNodes+=pow(2,i);
	}
	for (size_t j = 0 ; j < numNodes ; j++){ // Iterates rough the tree and its children.
		
		if(data[left(j)] == NULL){ //If the left child is Empty, then stop because the tree is NOT complete.
			 break;
		}

		if(data[j] < minimumVal){ // Compare the current node.
			minimumVal = data[j];
		}
		if (data[left(j)] < minimumVal){ //Compare left child data.
			minimumVal = data[left(j)];
		}
		if(data[right(j)] < minimumVal){// Compare the right child data.
			minimumVal = data[right(j)];
		}
	}
	return minimumVal;
}
// The root is always the highest value in a max heap.
template<class Item>
Item Heap<Item>::maximum(){
    assert(count > 0);
    return data[0];
}

#endif