#include "hw4q2.h"
#ifndef __HW4Q2_H__
#define __HW4Q2_H__
template<class Item>
Queue<Item>::Queue(){
    data = new Item[DEF_CAP];
    capacity = DEF_CAP;
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


    }


}
template<class Item>
void Queue<Item>::pop(){
    if(!empty()){
        first++;
    }
    
}


template<class Item>
void Queue<Item>::operator=(const Queue<Item>& source){

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
    return null;
    

}
#endif
