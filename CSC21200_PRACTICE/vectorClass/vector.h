#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <cstdlib>
#include <cstdio>
#include <cassert>
using namespace std;

template <class Item>
class vector{

public:
const static size_t DEF_CAPACITY = 8;

// CONSTRUCTOR
vector(){
capacity = DEF_CAPACITY;
size = 0;
data = new Item[capacity];
}

// DECONSTRUCTOR
~vector(){
    delete data;
}
// COPY CONSTRUCTOR
vector(const vector& source){
    size = source.size;
    capacity = source.capacity;
    Item* newData = new Item[capacity];
    for (size_t i = 0; i < size; i++){
        newData[i] = source.data[i];
    }
    data = newData;
}

// MODIFICATION MEMBER FUNCTIONS
void push_back(Item entry){
    if(size == capacity){
        capacity*=2;
        Item* newData = new Item[capacity];
        for (size_t i = 0; i < size; i++){
            newData[i] = data[i];
        }
        newData[size] = entry;
        size++;
        delete data;
        data = newData;
        return;
    }
    data[size] = entry;
    size++;
}

void pop_back(){
    if(size != 0){
    Item* newData = new Item[capacity];
    size--;
    for(size_t i = 0; i < size; i++){
        newData[i] = data[i];
    }
    delete data;
    data = newData;
    }
    
}

void clear(){
    delete data;
    capacity = DEF_CAPACITY;
    data = new Item[capacity];
}

// CONSTANT MEMBER FUNCTIONS
size_t get_size() const{
    return size;
}

size_t get_capacity() const{
    return capacity;
}

Item front() const{
    if(size != 0){
        return data[0];
    }
    return Item();
}

Item back() const{
    if(size != 0){
        return data[size-1];
    }
    return Item();
}

Item operator[](size_t index){
    if(size != 0){
        return data[index];
    }
}

private:
Item* data;
size_t capacity;
size_t size;

};

#endif