#ifndef __HEAP_CPP__
#define __HEAP_CPP__
#include "hw5q5.h"
/*
NOTE:
1.A Heap is must be a complete tree, meaning that the nodes are strictly added from left to right.
2.The parent node always has a larger value than it's children.
2.LEFT CHILD = A[2i+1], RIGHT CHILD = 2[i+2]
*/
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
	// NOTE: Current Node i = Parent.
	// Set the largest node as the current node by default. This is the index of the element with the largest value.
	size_t largest = i;

	// Make sure that the left childindex is within the array bounds AND check if the left child has its value greater than the parent.
	if (left(i) <= getCount() && data[left(i)] > data[i]){
		largest = left(i); // If the right child has a greater value than the value at the largest index, then set the largest index to the left child index.
	}
	else{
		largest = i;  // Set the largest to the parent.
	}
	// Make sure that the right child index is within the array bounds AND check if the value of the right child is greater than the node at the largest index.
	if(right(i) <= getCount() && data[right(i)] > data[largest]){
		largest = right(i); // If the right child has a greater value than the value at the largest index, then set the largest index to the right child index.
	}
	/* This while loop checks if one of the children nodes have a greater value than the parent. If it doesn't, then largest = i which is the parent.
	This means that there is no swapping required.
	However, if a child has the largest value then the index of that child will be stored in largest
	A swap must occur to apply the Max Heap property.*/
	if(largest != i){ 
		swap(data[i],data[largest]); 
		maxHeapify(largest);
	}
}

template<class Item>
void Heap<Item>::buildMaxHeap(){
	// Apply the max heap property from the bottom to top.
	size_t heapSize = getCount();
	for (size_t i = floor(heapSize/2); i >= 1; i--){
		maxHeapify(i);
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
