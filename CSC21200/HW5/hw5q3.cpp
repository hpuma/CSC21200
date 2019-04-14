#ifndef __BT_CLASS_DA_CPP__
#define __BT_CLASS_DA_CPP__
#include "hw5q3.h"


//CONSTRUCTOR
template<class Item> 
binaryTreeDA<Item>::binaryTreeDA(){
    capacity = DEF_CAP;
    tree  = new Item[capacity];
    count = 0;
    curr  = 0;
}
//COPY CONSTRUCTOR
template<class Item> 
binaryTreeDA<Item>::binaryTreeDA(const binaryTreeDA& source){
    if(source.size() < DEF_CAP){
        capacity = DEF_CAP;
        count = source.size();
        Item* newData = new Item[capacity]; // New array for our binary tree.

        size_t sourceSize = source.size(); //Stores the size value of the source's array.
        for(size_t i = 0 ; i < sourceSize ; i++){
            source.shiftInd(i); // Change the curr value to the source's Tree.
            newData[i] = source.retrieve(); 
        }
        tree = newData; // Sets our tree array to the copied array from the source.
    }
}
// DESTRUCTOR
template<class Item>
binaryTreeDA<Item>::~binaryTreeDA(){
delete []tree;
}



template<class Item>
void binaryTreeDA<Item>::createFirstNode(const Item& entry){
    //Might need cheking for preconditions.
    if(size()  == 0 ){
        tree[0] = entry;
        count = 1;
        curr = 0;
    }
}


template<class Item>
void binaryTreeDA<Item>::shiftToRoot(){
    if(size() > 0){
        curr = 0;
    }
}

template<class Item>
void binaryTreeDA<Item>::shiftUp(){
    if(hasParent()){
        curr = floor((curr-1)/2); // Formula for the index of the parent node;
    }

}

template<class Item>
void binaryTreeDA<Item>::shiftLeft(){
    if(hasLeft()){
        curr = (2*curr) + 1; //Based on the defintions on the Slides.
    }

}

template<class Item>
void binaryTreeDA<Item>::shiftRight(){
    if(hasRight()){
        curr = (2*curr) + 1; //Based on the defintions on the Slides.
    }
}

template<class Item>
void binaryTreeDA<Item>::shiftInd(const size_t& ind){
    if((size() > 0) && (ind > size())){ //Swap < operator... if tests dont pass? 
        curr = ind;
    }
}

template<class Item>
void binaryTreeDA<Item>::change(const Item& newEntry){
    if(size() > 0){
        tree[curr] = newEntry;
    }
}

template<class Item>
void binaryTreeDA<Item>::addLeft(const Item& entry){
    if((size() > 0 ) && !(hasLeft())){
        size_t leftIndex = (2*curr) + 1; // Get the index of where the left node is supposed to be.
        tree[leftIndex] = entry;
        count++
    }
}

template<class Item>
void binaryTreeDA<Item>::addRight(const Item& entry){
     if((size() > 0 ) && !(hasRight())){
        size_t rightIndex = (2*curr) + 2; // get the index of where the right node is supposed to be.
        tree[rightIndex] = entry;
        count++
    }
}


template<class Item>
void binaryTreeDA<Item>::removeLeft(){
    if((size() > 0) && (hasLeft())){
        size_t leftInd = (2*curr) + 1;
        tree[leftInd] = Item();
        count--;
    }
}


template<class Item>
void binaryTreeDA<Item>::removeRight(){
    if((size() > 0) && (hasRight())){
        size_t rightInd = (2*curr) + 2;
        tree[rightInd] = Item();
        count--;
    }
}
// CONSTANT MEMBER FUNCTIONS
template<class Item> 
size_t binaryTreeDA<Item>::size() const{
    return count;
}

template<class Item> 
Item binaryTreeDA<Item>::retrieve() const {
    if(size() < 0){
        return NULL;
    }
    return tree[curr];
}

template<class Item> 
bool binaryTreeDA<Item>::hasParent() const{
    size_t parentInd = floor((curr-1)/2); // Store's the index of where the parent is supposed to be
    return ((size() > 0) && (tree[parentInd] != Item()))
}

template<class Item> 
bool binaryTreeDA<Item>::hasLeft() const{
    size_t leftInd = (2*curr) + 1; //stores's the left index
    return ((size() > 0) && (tree[leftInd] != Item()));
}

template<class Item> 
bool binaryTreeDA<Item>::hasRight() const{
    size_t rightCheck = (2*curr) + 2;
    return ((size() > 0) && (tree[rightCheck] != Item()));
    
}



#endif
