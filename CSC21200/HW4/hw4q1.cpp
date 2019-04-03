
#ifndef __HW4Q1_CPP__
#define __HW4Q1_CPP__
#include "hw4q1.h"


  Stack();
template <class Item>
 Stack<Item>::Stack(const Stack& source){
     capacity = source.capacity;
     used = source.used;
     data = new Item[source.capacity];
     for (size_t i = 0; i < used; i++){
         data[i] = source.data[i];
     }
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
    data = new item[capacity];
    for(size_t i = 0 ; i < used; i++){
        data[i] = 
    }

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