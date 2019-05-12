#ifndef __BAG_H__
#define __BAG_H__

#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

class bag{
size_t DEF_CAP = 30;
public: 
typedef int bagdt;

//CONSTRUCTOR
bag();
//COPY CONSTRUCTOR
bag(const bag& source);

// DESTRUCTOR
~bag();

// MODIFICATION MEMBERS
size_t erase(const bagdt& item);
bool eraseOne(const bagdt& item);
void insert(const bagdt& item);


// CONSTANT MEMBER FUNCTIONS
size_t count(const bagdt& target) const;
size_t get_capacity() const;
size_t get_size() const;
bool find(const bagdt& target) const;
bool isEmpty() const;


private:
bagdt *data;
size_t size;
size_t capacity;
};

#endif