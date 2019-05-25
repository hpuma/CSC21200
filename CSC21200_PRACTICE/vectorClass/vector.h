#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

template <class Item>
class vector{

public:
const size_t DEF_CAPACITY = 8;
// CONSTRUCTOR
vector(){
size_t capacity = DEF_CAPACITY;
size_t size = 0;
Item* data = new Item[capacity];
}
// COPY CONSTRUCTOR
vector(const vector& source){

}

// MODIFICATION MEMBER FUNCTIONS
void push_back(const Item& entry){

}
void pop_back(){

}
void clear(){

}

// CONSTANT MEMBER FUNCTIONS
size_t size() const{

}

size_t capacity() const{

}
Item peek() const{

}

private:
Item* data;
size_t capacity;
size_t size;

};

#endif