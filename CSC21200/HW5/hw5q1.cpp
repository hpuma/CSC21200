#ifndef __BTNODE_CPP__
#define __BTNODE_CPP__
#include "hw5q1.h"

template <class Process, class Item>
void btNode<Process, Item>::inorder(Process f, btNode<Item>* nodePtr){

} 

template <class Process, class Item>
void btNode<Process, Item>::preorder(Process f, btNode<Item>* nodePtr){

}

template <class Process, class Item>
void btNode<Process, Item>::postorder(Process f, btNode<Item>* nodePtr){

}

template <class Item, class SizeType>
void btNode<Item, SizeType>::print(btNode<Item>* nodePtr, SizeType depth){

}

template <class Item>
void btNode<Item>::clearTree(btNode<Item>*& rootPtr){

}

template <class Item>
btNode<Item>* btNode<Item>::copyTree(const btNode<Item>* rootPtr){
    
}

template <class Item>
size_t btNode<Item>::treeSize(const btNode<Item>* nodePtr){

}

#endif