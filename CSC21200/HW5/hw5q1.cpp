#ifndef __BTNODE_CPP_
#define __BTNODE_CPP_
#include "hw5q1.h"

/*Left Child: Parent Node: Right Child*/
template<class Process, class Item>
void inorder(Process f, btNode<Item>* nodePtr){ 
    if(nodePtr == NULL){
        return;
    }
        inorder(f,nodePtr->getLeft());
        f(nodePtr->getData());
        inorder(f,nodePtr->getRight());
}

/*Parent Node: Left Child : Right Child */
template<class Process, class Item>
void preorder(Process f, btNode<Item>* nodePtr){
    if(nodePtr == NULL){ 
        return;
    }  
    f(nodePtr->getData());
    preorder(f,nodePtr->getLeft());
    preorder(f,nodePtr->getRight()); 
}

/*Left Child: Right Child : Parent Node */
template<class Process, class Item> 
void postorder(Process f, btNode<Item>* nodePtr){
    if(nodePtr == NULL){ 
        return;
    }  
    postOrder(f,nodePtr->getLeft());
    postOrder(f,nodePtr->getRight());
    f(nodePtr->getData());    
}

template<class Item, class SizeType> 
void print(btNode<Item>* nodePtr, SizeType depth){
    if(nodePtr == NULL){ 
        return;
    } 
     cout<<setw(4*depth)<<"";
     if(nodePtr == NULL){
        cout<<"Empty\n";
     }  
     else if(nodePtr->isLeaf()){
        cout<<nodePtr->getData()<<"LEAF\n";
     }  
     else{
        cout<<nodePtr->getData()<<"\n";
        print(nodePtr->getLeft(), depth+1);
        print(nodePtr->getRight(), depth+1);   
     } 
    
}

template<class Item> 
void clearTree(btNode<Item>*& rootPtr){
    if(rootPtr == NULL){ 
        return;
    }  
    btNode<Item>* leftChild = rootPtr->getLeft();
    btNode<Item>* rightChild = rootPtr->getRight();
    clearTree(leftChild);
    clearTree(rightChild);
    delete rootPtr;
    rootPtr = NULL;
}

template<class Item> 
btNode<Item>* copyTree(const btNode<Item>* rootPtr){
    if(rootPtr == NULL){
        return NULL;
    }
    btNode<Item>* leftCopy = copyTree(rootPtr->getLeft());
    btNode<Item>* rightCopy = copyTree(rootPtr->getRight()); 
    return new btNode<Item>(rootPtr->getData(),leftCopy, rightCopy);
    }

template<class Item> 
size_t treeSize(const btNode<Item>* nodePtr){
    size_t count = 1;
    if (nodePtr->getLeft() != NULL){
        count +=treeSize(nodePtr->getLeft());
    }
    if(nodePtr->getRight() != NULL){
        count +=treeSize(nodePtr->getRight());
    }
    return count; 
}

#endif