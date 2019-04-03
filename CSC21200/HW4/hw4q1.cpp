#ifndef __HW4Q1_CPP__
#define __HW4Q1_CPP__
#include "hw4q1.h"

// WILL ADD COMMENTS
template<class Item>
 Stack<Item>::Stack(){
     capacity = DEF_CAP;
     data = new Item[capacity];
     used = 0;
 }

template <class Item>
 Stack<Item>::Stack(const Stack& source){
     capacity = source.capacity;
     used = source.used;
     Item* newData = new Item[capacity];
     for (size_t i = 0; i < used; i++){
         newData[i] = source.data[i];
     }
     data = newData;
 }

template <class Item>
 Stack<Item>::~Stack(){
     delete []data;
 }

template <class Item>
void Stack<Item>::push(const Item& entry){
    if(used < capacity){
        data[used] = entry;
        used++;
    }
}

template <class Item>
void Stack<Item>::pop(){
    if(used != 0){
        used--;
    }
}

template <class Item>
void Stack<Item>::operator=(const Stack<Item>& source){
    used = source.used;
    capacity = source.capacity;
    Item* newData = new Item[capacity];
    for(size_t i = 0 ; i < used; i++){
        newData[i] = source.data[i];
    }
    data = newData;

}

template <class Item>
size_t Stack<Item>::size() const{
    return used;
}

template <class Item>
bool Stack<Item>::empty() const{
    return used == 0;
}

template <class Item>
Item Stack<Item>::top() const{
    return data[used -1];
}








#endif