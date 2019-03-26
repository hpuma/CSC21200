#include "hw4q2.h"
#ifndef __HW4Q2_H__
#define __HW4Q2_H__
template<class Item>
Queue<Item>::Queue(){
    capacity = DEF_CAP;
    data = new Item[DEF_CAP];
    first = 0;
    last = 0;
    used = 0;
    
}

template<class Item>
Queue<Item>::Queue(const Queue<Item>& source){
data = source.data;
first = source.first;
last = source.last;
used = source.used;
capacity = source.capacity;
}

template<class Item>
Queue<Item>::~Queue(){
    delete data;
}

template<class Item>
void Queue<Item>::push(const Item& entry){
    if(!(used > capacity)){
        data[nextIndex(last)] = entry;
        last = nextIndex(last;)
        used++;
    }

}
template<class Item>
void Queue<Item>::pop(){
    if(!empty()){
        first = nextIndex(first);
        used--;
    }
}

template<class Item>
void Queue<Item>::operator=(const Queue<Item>& source){
    data = new Item[source.capacity];
    capacity = source.capacity
    used = source.used;
    first = source.first;
    last = source.last;
    for(size_t i = first; i <=last; i++){
        data[i] = source.data[i];
    }
}

template<class Item>
size_t Queue<Item>::size() const{
    return used;
}
template<class Item>
bool Queue<Item>::empty() const{
    return (used == 0);

}
template<class Item>
Item Queue<Item>::front() const{
    if(!empty()){
        return data[first];
    }
    return NULL;
}
#endif
