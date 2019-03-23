#include "hw4q2.h"
template<class Item>
Queue<Item>::Queue(){
    data = new Item[DEF_CAP];
    first = 0;
    last = 0;
    used = 0;
    capacity = DEF_CAP;
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

}

template<class Item>
void Queue<Item>::push(const Item& entry){

}
template<class Item>
void Queue<Item>::pop(){
}

template<class Item>
void Queue<Item>::operator=(const Queue<Item>& source){

}

template<class Item>
size_t Queue<Item>::size() const{

}
template<class Item>
bool Queue<Item>::empty() const{

}
template<class Item>
Item Queue<Item>::front() const{

}

