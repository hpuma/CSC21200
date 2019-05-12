#ifndef __BAG_CPP__
#define __BAG_CPP__
#include"bagDynamic.h"

// CONSTRUCTOR
bag::bag(){
    data = new bagdt[capacity];
    size = 0;
}

// DECONSTRUCTOR
bag::bag(const bag& source){
    bagdt *newData;
    size = source.size;
    capacity = source.capacity;
    newData = new bagdt[capacity];
    for(size_t i = 0; i < size; i++){
        newData[i] = source.data[i];
    }
    data = newData;
}
// DESTRUCTOR
bag::~bag(){
    size = 0;
    capacity = 0;
    delete data;
}

size_t bag::erase(const bagdt& item){
    size_t itemsRemoved = 0;
    for(size_t i = 0; i < size; i++){
        if(data[i] == item){
            data[i] = data[size-1];
            size--;
            itemsRemoved++;
        }
    }
    return itemsRemoved;
}
bool bag::eraseOne(const bagdt& item){
     for (size_t i = 0; i < size; i++){
        if(data[i] == item){
            data[i] = data[size-1];
            size--;
            return true;
        }
    }
    return false;
}

void bag::insert(const bagdt& item){


}

// CONSTANT MEMBER FUNCTIONS
size_t bag::count(const bagdt& target) const{
    size_t itemCount = 0;
    for (size_t i = 0; i < size; i++){
        
    }
}

size_t bag::get_capacity() const{
    return capacity;
}
size_t bag::get_size() const{
    return size;
}

bool bag::find(const bagdt& target) const{
    for (size_t i = 0; i < size; i++){
        if(data[i] == target){
            return true;
        }
    }
    return false;
}

bool bag::isEmpty() const{
    return (size == 0);
}




#endif



