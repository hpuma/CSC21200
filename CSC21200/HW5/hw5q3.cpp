#ifndef __BT_CLASS_DA_CPP__
#define __BT_CLASS_DA_CPP__
#include "hw5q3.h"


//CONSTRUCTOR
template<class Item> 
binaryTreeDA<Item>::binaryTreeDA(){
    capacity = DEF_CAP;
    tree  = new Item[capacity];
    count = 0;
    curr  = tree;
}
//COPY CONSTRUCTOR
template<class Item> 
binaryTreeDA<Item>::binaryTreeDA(const binaryTreeDA& source){
    if(source.size() < DEF_CAP){
        capacity = DEF_CAP;
        count = source.size();
        size_t sourceSize = source.size();
        Item newData = new Item[capacity];
       for(size_t i = 0 ; i < sourceSize ; i++){
           newData[i] = 
       }

        
    }


}
// DESTRUCTOR
template<class Item>
binaryTreeDA<Item>::~binaryTreeDA(){
delete []tree;
}



template<class Item>
void binaryTreeDA<Item>::createFirstNode(const binaryTreeDA& source){

}


template<class Item>
void binaryTreeDA<Item>::shiftToRoot(){

}

template<class Item>
void binaryTreeDA<Item>::shiftUp(){

}

template<class Item>
void binaryTreeDA<Item>::shiftLeft(){

}

template<class Item>
void binaryTreeDA<Item>::shiftRight(){

}

template<class Item>
void binaryTreeDA<Item>::shiftInd(const size_t& ind){
    if((size() > 0) && (size() < ind)){
        curr = ind;
    }
}

template<class Item>
void binaryTreeDA<Item>::change(const Item& newEntry){

}

template<class Item>
void binaryTreeDA<Item>::addLeft(const Item& entry){

}

template<class Item>
void binaryTreeDA<Item>::addRight(const Item& entry){

}


template<class Item>
void binaryTreeDA<Item>::removeLeft(){

}


template<class Item>
void binaryTreeDA<Item>::removeRight(){

}
// CONSTANT MEMBER FUNCTIONS
template<class Item> 
size_t binaryTreeDA<Item>::size() const{
    return size;
}

template<class Item> 
Item binaryTreeDA<Item>::retrieve() const {
    if(size() < 0){
        return NULL;
    }
    return Item[curr];
}

template<class Item> 
bool binaryTreeDA<Item>::hasParent() const{

}

template<class Item> 
bool binaryTreeDA<Item>::hasLeft() const{

}

template<class Item> 
bool binaryTreeDA<Item>::hasRight() const{
    
}



#endif
