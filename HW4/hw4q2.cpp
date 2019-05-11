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

Item* newData = new Item[source.capacity];
    for(size_t i = 0; i < source.used; i++){
        newData[i] = source.data[i];
    }
data = newData;

}

template <class Item>
Queue<Item>::~Queue(){
delete []data;
}

template <class Item>
void Queue<Item>::push(const Item& entry){
    if(!(used > capacity)){
        last = nextIndex(last);
        data[last] = entry;
        ++used;   
    }

}
template <class Item>
void Queue<Item>::pop(){
    if(!(empty())){
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

    Item* newData = new Item[source.capacity];
    for(size_t i = 0; i < source.used; i++){
        newData[i] = source.data[i];
    }
    data = newData;
}

template <class Item>
size_t Queue<Item>::size() const{
    return used;
}
template <class Item>
bool Queue<Item>::empty() const{
    return (used == 0);
}

template <class Item>
Item Queue<Item>::front() const{
    if(!(empty())){
        return data[first];
    }
    return Item();
}
#endif