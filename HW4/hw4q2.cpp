#include "hw4q2.h"
#ifndef __HW4Q2_CPP__
#define __HW4Q2_CPP__

template <class Item>
Queue<Item>::Queue(){
    capacity = DEF_CAP;
    data = new Item[DEF_CAP];
    used = 0;
    first = 0;
    last = capacity-1;
    
}

template <class Item>
Queue<Item>::Queue(const Queue<Item>& source){
capacity = source.capacity;
first = source.first;
last = source.last;
used = source.used;

Item* newData = new Item[source.capacity]; // Create new dynamic array the same size as the Source dynamic array.
    for(size_t i = 0; i < source.used; i++){ // Add everything from this dynamic array to the new dynamic array.
        newData[i] = source.data[i];
    }
data = newData; // Set the data pointer to the new dynamic array with the new data.

}

template <class Item>
Queue<Item>::~Queue(){
delete []data; // Delete the data pointer.
}

template <class Item>
void Queue<Item>::push(const Item& entry){
    if(!(used > capacity)){ // Check if there is enough space to add another element.
        last = nextIndex(last); // Next index is private function that determines the next index within the array.
        data[last] = entry;
        ++used;   
    }

}
template <class Item>
void Queue<Item>::pop(){
    if(!(empty())){ // Make sure we are not popping an empty stack.
        first = nextIndex(first);
        --used;
    }
}

template <class Item>
void Queue<Item>::operator=(const Queue<Item>& source){
    capacity = source.capacity;
    first = source.first;
    last = source.last;
    used = source.used;

    Item* newData = new Item[source.capacity]; // Allocate new data array.
    for(size_t i = 0; i < source.used; i++){ // Move contents over.
        newData[i] = source.data[i];
    }
    data = newData; // Point to the newly allocated array.
}

template <class Item>
size_t Queue<Item>::size() const{
    return used; // Return the number of used indexes.
}
template <class Item>
bool Queue<Item>::empty() const{
    return (used == 0); // Return whether or not the number of used elements is not 0.
}

template <class Item>
Item Queue<Item>::front() const{
    if(!(empty())){ // Make sure the data array is not empty!
        return data[first];
    }
    return Item(); // Return a garbage Value.
}
#endif