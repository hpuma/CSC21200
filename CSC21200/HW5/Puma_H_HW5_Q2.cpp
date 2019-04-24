#ifndef __BT_CLASS_CPP__
#define __BT_CLASS_CPP__
#include "hw5q2.h"

//CONSTRUCTOR
template<class Item>
binaryTree<Item>::binaryTree(){
    root = NULL; // Root pointer doesnt's point to anything.
    curr = root; // Curr pointer points to the same thing that the root pointer is pointing to.
    count = 0; // The Tree is currently empty, so set the count to 0.
}
//COPY CONSTRUCTOR
template<class Item>
binaryTree<Item>::binaryTree(const binaryTree& source){
    root = copyTree(source.root); // Use the function from the btNode toolkit.
    count = source.size(); // use the get function to get the size from the source binary tree.
    curr = root; // Set the current pointer to the root of the tree.
}
//DESTRUCTOR
template<class Item>
binaryTree<Item>::~binaryTree(){
    clearTree(root);
    count = 0;
    curr = NULL;
}

template<class Item>
void binaryTree<Item>::createFirstNode(const Item& entry){
    if(size() == 0){ // Make sure that the tree is empty if you are going to insert the very first node.
        root = new btNode<Item>(entry); // Make the root point to a node that contains entry.
        curr = root; // Make the current pointer point to the root since this is the first entry.
        count++;
    }
}

template<class Item>
void binaryTree<Item>::shiftToRoot(){
    if(size() > 0){ // Make sure that the tree isn't empty.
        curr = root; // Set the current pointer to the root.
    }
}

template<class Item>
void binaryTree<Item>::shiftUp(){
    if(hasParent()){
        curr = curr->getParent(); // Move the current pointer to the parent of the current node.
    }
}

template<class Item>
void binaryTree<Item>::shiftLeft(){
    if(hasLeft()){
        curr = curr->getLeft(); // Move the current pointer to the left child of the current node.
    }
}

template<class Item>
void binaryTree<Item>::shiftRight(){
    if(hasRight()){
        curr = curr->getRight(); // Move the current pointer to the right child of the current node.
    }
}

template<class Item>
void binaryTree<Item>::change(const Item& newEntry){
    if(size() > 0){
        curr->setData(newEntry); // Change the entry of the current node that we're pointing to with the curr pointer.
    }
}

template<class Item>
void binaryTree<Item>::addLeft(const Item& entry){
    if((size() > 0) && (!hasLeft())){ // Make sure the tree is not empty AND that there isn't a left node already.
        btNode<Item>* newLeft = new btNode<Item>(entry); // Allocate a new node with the entrys.
        newLeft->setParent(curr); // Make sure that the new node sets the current node as its parent
        curr->setLeft(newLeft); // Set the new Node as the left child of the current node.
        count++;
    }
}

template<class Item>
void binaryTree<Item>::addRight(const Item& entry){
    if((size() > 0) && (!hasRight())){
        btNode<Item>* newRight = new btNode<Item>(entry);
        newRight->setParent(curr);
        curr->setRight(newRight);
        count++;
    }
}

template<class Item>
void binaryTree<Item>::removeLeft(){
    /*NOTE: You must take into consideration if the left node is a leaf. In this case
    we are not required to check if it is a leaf*/
    if((size() > 0 && hasLeft()) &&(curr->getLeft()->isLeaf())){
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
    if((size() > 0 && hasRight()) && ( curr->getRight()->isLeaf())){
        btNode<Item>* deleteMe = curr->getRight();
        delete deleteMe;
        curr->setRight(NULL);
        count--;
    }
}
template<class Item>
void binaryTree<Item>::setRoot(btNode<Item>* newRoot){

    if(size() > 0){
        btNode<Item>* oldRoot = root; // Pointer to the old root.
        btNode<Item>* leftChild = NULL; // Set the left child to NULL, we are not sure if it exists yet
        btNode<Item>* rightChild = NULL; // Set the right child to NULL, we are not sure if it exists yet.
        
        if(oldRoot->getLeft() != NULL){ // If the left child exists.
            leftChild = oldRoot->getLeft(); // Set the left child pointer to the left child.
            leftChild->setParent(newRoot); // Set the left child parent to the new root.
        }
        if(oldRoot->getRight() != NULL){ // If the right child exists.
            rightChild = oldRoot->getRight(); // Set the left child pointer to the right child.
            rightChild->setParent(newRoot); // Set the right child parent to the new root.
        }

        newRoot->setLeft(leftChild); // New Root inherits the left node from the old root.
        newRoot->setRight(rightChild); // New Root inherits the right node from the old root.
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
    return (curr->getData());
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