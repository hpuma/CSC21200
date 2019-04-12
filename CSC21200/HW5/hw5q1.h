#ifndef __BTNODE_H__
#define __BTNODE_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 5 header file

// Try not to change this file

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <iomanip>

using namespace std;

template <class Item>
class btNode
{
public:
    // CONSTRUCTOR
    btNode(
        const Item& initData = Item( ),
        btNode* initLeft = NULL,
        btNode* initRight = NULL,
        btNode* initParent = NULL
    )
    { 
        data  = initData; 
        left  = initLeft; 
        right = initRight;
        parent = initParent;
    }

    // MODIFICATION MEMBER FUNCTIONS
    Item& getData() {return data;}
    btNode* getLeft() {return left;}
    btNode* getRight() {return right;}
    btNode* getParent() {return parent;}

    void setData(const Item& newData) {data = newData;}
    void setLeft(btNode* newLeft) {left = newLeft;}
    void setRight(btNode* newRight) {right = newRight;}
    void setParent(btNode* newParent) {parent = newParent;}

    // CONST MEMBER FUNCTIONS
    const Item& getData() const {return data;}
    const btNode* getLeft() const {return left;}
    const btNode* getRight() const {return right;}
    const btNode* getParent() const {return parent;}
    bool isLeaf() const {return (left == NULL) && (right == NULL);}
private:
    Item data;
    btNode *left;
    btNode *right;
    btNode *parent;
};

// NON-MEMBER FUNCTIONS for the btNode<Item>:
template <class Process, class Item>
void inorder(Process f, btNode<Item>* nodePtr); 

template <class Process, class Item>
void preorder(Process f, btNode<Item>* nodePtr);

template <class Process, class Item>
void postorder(Process f, btNode<Item>* nodePtr); 

template <class Item, class SizeType>
void print(btNode<Item>* nodePtr, SizeType depth);

template <class Item>
void clearTree(btNode<Item>*& rootPtr);

template <class Item>
btNode<Item>* copyTree(const btNode<Item>* rootPtr);

template <class Item>
size_t treeSize(const btNode<Item>* nodePtr);

#include "hw5q1.cpp"
#endif