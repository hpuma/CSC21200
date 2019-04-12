#ifndef __BST_H__
#define __BST_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 5 header file

// Try not to change this file

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "hw5q2.h"

using namespace std;

template <class Item>
class BST
{
public:
    // CONSTRUCTOR
    BST();

    // MODIFICATION MEMBER FUNCTIONS
    void insert(const Item& entry);
    void remove(const Item& target);
    void transplant(btNode<Item>*& u, btNode<Item>*& v);

    btNode<Item>* minimum();
    btNode<Item>* maximum();

    btNode<Item>* search(const Item& target);

    size_t getCt() const {return count;}
    binaryTree<Item> getTree() const {return tree;}
    
private:
    binaryTree<Item> tree;
    size_t count;
};

#include "hw5q4.cpp"
#endif