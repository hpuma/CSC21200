#ifndef __BT_CLASS_CPP__
#define __BT_CLASS_CPP__
#include "hw5q2.h"

template<class Item>
binaryTree<Item>::binaryTree(){

}

template<class Item>
binaryTree<Item>::binaryTree(const binaryTree& source){

}
template<class Item>
binaryTree<Item>::~binaryTree(){

}
template<class Item>
void binaryTree<Item>::createFirstNode(const Item& entry){

}
template<class Item>
void binaryTree<Item>::shiftToRoot(){

}

template<class Item>
void binaryTree<Item>::shiftUp(){

}

template<class Item>
void binaryTree<Item>::shiftLeft(){

}

template<class Item>
void binaryTree<Item>::shiftRight(){

}

template<class Item>
void binaryTree<Item>::change(const Item& entrys){

}

template<class Item>
void binaryTree<Item>::addLeft(const Item& entry){

}

template<class Item>
void binaryTree<Item>::addRight(const Item& entry){

}

template<class Item>
void binaryTree<Item>::removeLeft(){

}

template<class Item>
void binaryTree<Item>::removeRight(){

}
template<class Item>
void binaryTree<Item>::setRoot(btNode<Item>* newRoot){

}

template<class Item>
btNode<Item>* binaryTree<Item>::getNode(){
    
}

template<class Item>
size_t binaryTree<Item>::size() const{
return count;
}

template<class Item>
Item binaryTree<Item>::retrieve() const{
return curr->getData();
}

template <class Item> 
bool binaryTree<Item>::hasParent() const{
    
}
template<class Item>
bool binaryTree<Item>::hasLeft() const{
    
}

template<class Item> 
bool binaryTree<Item>::hasRight() const{

}




#endif