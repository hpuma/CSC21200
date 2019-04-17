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
	if(count > 0){
		if(entry > data[i]){
			data[i] = entry;
			maxHeapify(i);	
		}
	}
}

template<class Item>
Item Heap<Item>::removeMax(){
	if(count > 0){
		Item maxItem = data[0];
		data[0] = data[count-1];
		count--;
		maxHeapify(0);
		return maxItem;
	}
	return Item();

}

template<class Item>
void Heap<Item>::maxHeapify(const size_t& i){
	size_t largest = i;
	if (left(i) <= count && data[left(i)] > data[i]){
		largest = left(i);
	}
	else{
		largest = i; // 1 
	}
	if(right(i) <= count && data[right(i)] > data[i]){
		largest = right(i); // 1 
	}
	if(largest != i){ // 1 
		swap(data[i],data[largest]); // 1
		maxHeapify(largest);
	}

}


template<class Item>
void Heap<Item>::buildMaxHeap(){
	size_t index = getCount();
	for (int i = count-1; i >= 1; i--){
		swap(data[0],data[i]);
		index--;
		maxHeapify(0);
	}
}

template<class Item>
Item* Heap<Item>::heapsort(){
	Item* newHeap = new Heap<Item>();
	for (size_t i = 0 ; i < getCount();i++){
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

template<class Item>
Item Heap<Item>::minimum(){
	return data[count-2];
}

template<class Item>
Item Heap<Item>::maximum(){
    if(count > 0){
    	return data[0];
    }
    return Item();
}




#endif