#include "hw4q3.h"
#ifndef __HW4Q2_CPP__
#define __HW4Q2_CPP__

template <class Item>
 PriorityQueue<Item>::PriorityQueue(){
     capacity = DEF_CAP;
     data = new Item[DEF_CAP];
     first = 0;
     last = capacity-1;
     used = 0;
 }

template <class Item>
PriorityQueue<Item>::PriorityQueue(const PriorityQueue<Item>& source){
capacity = source.capacity;
first = source.first;
last = source.last;
used = source.used;

Item* newData = new Item[source.capacity];
    for(size_t i = 0; i < source.used; i++){
        newData[i] = source.data[i];
    }
data = newData;
}

template <class Item>
PriorityQueue<Item>::~PriorityQueue(){
delete []data;
}

template <class Item>
void PriorityQueue<Item>::push(const Item& entry){
    if(!(used > capacity)){
        last = nextIndex(last);
        data[last] = entry;
        used++;   
    } 
    Item temp;
    if(data[last] < data[first]){
        temp = data[first];
        data[first] = data[last];
        data[last] = temp;
    }

}


template <class Item>
void PriorityQueue<Item>::pop(){
    Item temp;
    if(data[last] < data[nextIndex(first)]){
        temp = data[nextIndex(first)];
        data[nextIndex(first)] = data[last];
        data[last] = temp;
    }

  if(!(empty())){
        first = nextIndex(first);
        used--;
    }
}
template <class Item>
void PriorityQueue<Item>::operator=(const PriorityQueue<Item>& source){
    capacity = source.capacity;
    first = source.first;
    last = source.last;
    used = source.used;

    Item* newData = new Item[source.capacity];
    for(size_t i = 0; i < source.used; i++){
        newData[i] = source.data[i];
    }
    data = newData;
}

template <class Item>
size_t PriorityQueue<Item>::size() const{
    return used;
}

template <class Item>
bool PriorityQueue<Item>::empty() const{
    return (used == 0);
}
template <class Item>
Item PriorityQueue<Item>::front() const{
    if(used != 0){
        return data[first];
    }
    return Item();
}


#endif