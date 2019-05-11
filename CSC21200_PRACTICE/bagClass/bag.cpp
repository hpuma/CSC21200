#ifndef __BAG_CPP__
#define __BAG_CPP__
#include"bag.h"
using namespace std;

size_t CAPACITY = 20;
// CONSTRUCTORS
bag::bag(){
size = 0;
}

bag::bag(bagdt addAr[], const size_t arSize){
assert(arSize < capacity); // Make sure that the bag you're trying to copy can fit into my bag.
    size = arSize; // Inherit the bag size.
    size_t i = 0; // Transfering everything over to my data array aka bag.
    while (i < size){
        data[i] = addAr[i];
        i++; 
    }
}

// MODIFICATION MEMBER FUNCTIONS.
size_t bag::erase(const bagdt& target){
    assert(size > 0);
    size_t i = 0; /// Used for iterating through the data array... you can also used for-loop.
    size_t erased = 0; // Keeps track of the amount of items that are target that were erased.
    while (i < size){
        if (data[i] == target){ // When we have found the target.
            data[i] = data[size-1]; // Overwrite the target element with the last element, then shrink the array.
            erased++; // One more target item erased.
            size--; // Shrinking the array.
        }
        else{ // When the target has not been found ... keep iterating.
            i++; 
        }
    }
return erased; // Return the number of 'target' items erased.
}

// We can only erase ONE target item if it exists. We return a boolean item if we erase a 'target' item.
bool bag::eraseOne(const bagdt& target){
assert(size > 0);
    size_t i = 0; // Used for iterating through the data array.
    while (i < size){
        if(data[i] == target){ // When the 'target' item has been found.
            data[i] = data[size-1]; // Overwrite the element of the target with the last element.
            size--; // Shrink the data array.
            return true; // Return true, because we have deleted a 'target' item.
        }
        i++;
    }
return false; // We have iterated throughout the entire data array ... a 'target' item has not been found.
}

void bag::insert(const bagdt& addNew){
assert(size < capacity); // Make sure there is enough room to add a new item to the data array.
    data[size] = addNew; // Add the new item to the back of the data array.
    size++; // Increment the counter.
}

// CONSTANT MEMBER FUNCTIONS.
// Return the size of the bag.
size_t bag::get_size() const{
return size;
}

// Return the number of items in the bag that == 'target'.
size_t bag::count(const bagdt& target) const{
assert(size > 0);
    size_t count = 0; // Initialize the counter for the number of target items found.
    size_t i = 0;
    while (i < size){
        if (data[i] == target){ // An item == 'target'
            count++; // If the item in the bag == 'target', then increment the count of the 'target'
        }
        i++;
    }
return count;
}

// Iterate throughout the entire data array aka bag ... and print out its contents.
void bag::print() const{
    assert(size > 0);
    size_t i = 0;
    while(i < size ){
        std::cout<<data[i];
        i++;
    }
    std::cout<<std::endl<<"Size: "<<size<<std::endl;
}

// OPERATORS
bag operator+(const bag& b1,const bag& b2){ 
assert((b1.get_size() + b2.get_size()) < CAPACITY); // Make sure there is enough room to make a bag that can fit both input bags.

    size_t b1Size = b1.get_size();
    size_t b2Size = b2.get_size();

    size_t newSize = b1Size + b2Size;
    int newData[newSize];
    for (size_t i = 0; i < b1Size; i++){
        newData[i] = b1[i];
    }
    for(size_t j = 0 ; j < b2Size;j++){
        newData[j] = b2[j];
    }
    bag newBag(newData,newSize);
    return newBag;
}

bag operator-(const bag& b1, const bag& b2){
assert(b1.get_size() > b2.get_size()); // Make sure the first bag is larger than the smaller bag for subtraction.
    size_t b1Size = b1.get_size();
    size_t b2Size = b2.get_size();
    size_t count = 0;
    bool not_in_bag = true;

    int newSize = b1Size - b2Size;
    int newData[newSize];

    for(size_t i = 0; i < b1Size; i++){
        not_in_bag = true;
        for (size_t j = 0; j < b2Size; j++){
            if(b2[j] == b1[i]){
                not_in_bag = false;
                break;
            }
        }
        if(not_in_bag){
            newData[i] = b1[i];
            count++;
        }
    }
    bag newBag(newData,newSize);
    return newBag;
}
#endif // END OF MACROGAURD