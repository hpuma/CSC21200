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
     data = new Item[source.capacity];
     first = source.first;
     last = source.last;
     used = source.used;
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
        for (size_t i = first ; i < last; i++){
           if(data[i] < data[first]){
               temp = data[first];
               data[first] = data[i];
               data[i] = temp;
           }
        }

}

template <class Item>
void PriorityQueue<Item>::pop(){
  if(!(empty())){
        first = nextIndex(first);
        used--;
    }
}
template <class Item>
void PriorityQueue<Item>::operator=(const PriorityQueue<Item>& source){

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