#ifndef __HW4Q2_H__
#define __HW4Q2_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 4 header file

// Try not to change this file

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

template <class Item>
class PriorityQueue {
    public:
        const size_t DEF_CAP = 30;

        PriorityQueue();
        PriorityQueue(const PriorityQueue<Item>& source);
        ~PriorityQueue();

        void push(const Item& entry);
        void pop();
        void operator=(const PriorityQueue<Item>& source);

        size_t size() const;
        bool empty() const;
        Item front() const;

    private:
        Item* data;
        size_t first;
        size_t last;
        size_t used;
        size_t capacity;
        size_t nextIndex(size_t i) const {return (i+1)%capacity;}
        size_t prevIndex(size_t i) const{ return (i+1); }
};

#include "hw4q3.cpp"
#endif