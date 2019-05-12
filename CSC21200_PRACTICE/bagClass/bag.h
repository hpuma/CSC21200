#ifndef  __BAG_H__
#define  __BAG_H__
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;


class bag{

public:

typedef int bagdt; // Datatype of the bag
static const size_t capacity = 20;
// CONSTRUCTORS.
bag();
bag(bagdt addAr[],const size_t arSize);

// MODIFICATION MEMBER FUNCTIONS.
size_t erase(const bagdt& target); // Remove all the contents that is target.
bool eraseOne(const bagdt& target); // Remove one from the bags.
void insert(const bagdt& addNew); // Add one item.


// CONSTANT MEMBER FUNCTIONS.
size_t count(const bagdt& target) const; // Get the number of occurences within the bag.
size_t get_size() const; // Get the size of the bag.
size_t get_capacity() const;
void print() const; // Print out the contents of the bag.

int operator[](const size_t& i) const{
assert((size > 0) && (i < size) && (i >= 0));
return data[i];
}

void operator=(const bag& source){
assert(source.get_size() < capacity);
    size = source.get_size();

    for (size_t i = 0; i < size; i++){
        data[i] = source[i];
    }
}

void operator+=(const bag& addEnd){
assert((addEnd.get_size() + size) < capacity); // Make sure there is enough room to add a smaller bag.
    size_t addSize = addEnd.get_size();
    size_t i = 0;
    while (i < addSize){ // Iterating through the bag, we're going to add.
        data[size] = addEnd[i];
        size++;
        i++; // Move on to the next element of the input bag.
    }   
}

private:
bagdt data[capacity]; // Array containing the items of the bag.
size_t size; // How many elemnts have been used in this bag.
};

bag operator+(const bag& b1,const bag& b2); // The union of bags.
bag operator-(const bag& b1, const bag& b2);// Subtract the bags.


#include "bag.cpp"
#endif 