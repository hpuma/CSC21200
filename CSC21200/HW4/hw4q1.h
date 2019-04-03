#ifndef __HW4Q1_H__
#define __HW4Q1_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 4 header file

// Try not to change this file

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

template <class Item>
class Stack {
    public:
        const size_t DEF_CAP = 30;

        Stack();
        Stack(const Stack& source);
        ~Stack();

        void push(const Item& entry);
        void pop();
        void operator=(const Stack<Item>& source);

        size_t size() const;
        bool empty() const;
        Item top() const;

    private:
        Item* data;
        size_t used;
        size_t capacity;
};

#include "hw4q1.cpp"
#endif