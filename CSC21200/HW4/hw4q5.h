#ifndef __HW4Q4_H__
#define __HW4Q4_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 4 header file

// Try not to change this file

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "hw4q2.h"

using namespace std;

template <class Item>
class Queue2Stack {
    public:
        Queue2Stack();

        void push(const Item& entry);
        void pop();

        size_t size() const;
        bool empty() const;
        Item top() const;

    private:
        Queue<Item> q1;
        Queue<Item> q2;
        size_t used;
};

#include "hw4q5.cpp"
#endif