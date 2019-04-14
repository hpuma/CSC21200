#ifndef __BT_CLASS_CPP__
#define __BT_CLASS_CPP__
#include "hw5q2.h"

//CONSTRUCTOR
template<class Item>
binaryTree<Item>::binaryTree(){
    root = NULL;
    curr = NULL;
    count = 0;
}

//COPY CONSTRUCTOR
template<class Item>
binaryTree<Item>::binaryTree(const binaryTree& source){
    root = copyTree(source.root);
    count = source.size();
    curr = root;
}

//DESTRUCTOR
template<class Item>
binaryTree<Item>::~binaryTree(){
    clearTree(root);
    count = 0;
    curr = root;
}

template<class Item>
void binaryTree<Item>::createFirstNode(const Item& entry){
    if(size() == 0){
        root = new btNode<Item>(entry);
        curr = root;
        count++;
    }
}

template<class Item>
void binaryTree<Item>::shiftToRoot(){
    if(size() > 0){
        curr = root;
    }

}

template<class Item>
void binaryTree<Item>::shiftUp(){
    if(hasParent()){
        curr = curr->getParent();
    }
}

template<class Item>
void binaryTree<Item>::shiftLeft(){
    if(hasLeft()){
        curr = curr->getLeft();
    }
}

template<class Item>
void binaryTree<Item>::shiftRight(){
    if(hasRight()){
        curr = curr->getRight();
    }
}

template<class Item>
void binaryTree<Item>::change(const Item& newEntry){
    if(size() > 0){
        curr->setData(newEntry);
    }
}

template<class Item>
void binaryTree<Item>::addLeft(const Item& entry){
    if((size() > 0) && (!hasLeft())){
        btNode<Item>* newLeft(entry);
        newLeft->setParent(curr);
        curr->setLeft(newLeft);
        count++;
    }
}

template<class Item>
void binaryTree<Item>::addRight(const Item& entry){
    if((size() > 0) && (!hasRight())){
        btNode<Item>* newRight(entry);
        newRight->setParent(curr);
        curr->setRight(newRight);
        count++;
    }
}

template<class Item>
void binaryTree<Item>::removeLeft(){
    /*NOTE: You must take into consideration if the left node is a leaf. In this case
    we are not required to check if it is a leaf*/
    if((size() > 0) && (hasLeft())){
        btNode<Item>* deleteMe = curr->getLeft();
        delete deleteMe;
        curr->setLeft(NULL);
        count--;
    }
}

template<class Item>
void binaryTree<Item>::removeRight(){
    /*NOTE: You must take into consideration if the right node is a leaf. In this case
    we are not required to check if it is a leaf*/
    if((size() > 0) && (hasRight())){
        btNode<Item>* deleteMe = curr->getRight();
        delete deleteMe;
        curr->setRight(NULL);
        count--;
    }
}
template<class Item>
void binaryTree<Item>::setRoot(btNode<Item>* newRoot){

    if(size() > 0){
        btNode<Item>* oldRoot = root; // Pointer to old root.
        newRoot->setLeft(oldRoot->getLeft()); // New Root inherits the left node from the old root.
        newRoot->setRight(oldRoot->getRight()); // New Root inherits the right node from the old root.
        count = treeSize(oldRoot);  // Also, the tree size count from the old root.

        root = newRoot; // Set the root pointer to the new root.
        delete oldRoot; // Delete the node that "oldRoot" is pointing at, which is the old binary tree root.
    }
}

template<class Item>
btNode<Item>* binaryTree<Item>::getNode(){
    if(size() > 0){
        return curr;
    }
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
    return ((size() > 0) && (curr != root)); //As long as you are not the root, you have a parent. MUST TEST.
    
}
template<class Item>
bool binaryTree<Item>::hasLeft() const{
    return (curr->getLeft() != NULL);
}

template<class Item> 
bool binaryTree<Item>::hasRight() const{
    return(curr->getRight() != NULL);
}

#endif