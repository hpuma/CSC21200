#ifndef __GRAPHM_CPP__
#define __GRAPHM_CPP__
#include "hw6q1.h"

//CONSTRUCTOR
template <class Item>
graphM<Item>::graphM(){
    capacity = DEF_CAP;
    label = new Item[capacity](); //? default value.. or only for int?
    matrix = new int*[capacity]; // Rows of the matrix.
    for (size_t i = 0 ; i < capacity; i++){ // Columns of Matrix
        matrix[i] = new int[capacity]();
    } 
    count = 0;
}

//COPY CONSTRUCTOR
template <class Item>
graphM<Item>::graphM(const graphM<Item>& source){
    //COPY PRIVATE MEMBER VARIABLES
    capacity = source.capacity;
    count = source.count;
    matrix = new *int[capacity];

    //Iterate through out the entire matrix. 
    for (size_t i = 0 ; i < capacity; i++){
        matrix[i] = new int[capacity]; // Make a new array for each element.
        for(size_t j = 0 ; j < capacity;  j++){ // After the array is added, copy over the contents from the source.
            matrix[i][j] = source.matrix[i][j];
        }
    }
    // Make a new dynamic array for label
    label = new Item[capacity];
    for (size_t k = 0 ; k < capacity ; k++){
        label[k] = source.label[k]; // Copy over the contents from the source label array.
    }
    
}
//DECONSTRUCTOR??

//MODIFICATION MEMBER FUNCTIONS
template <class Item>
void graphM<Item>::addVertex(const Item& inLabel){
    assert(count < capacity);
    label[count] = inLabel;
    count++;
}

template <class Item>
void graphM<Item>::addEdge(size_t source, size_t target, int weight){
    assert((source < capacity) && (target < capacity) && (count >= 2) && weight > 0);
    matrix[source][target] = weight;
}

template <class Item>
void graphM<Item>::removeEdge(size_t source, size_t target){
    assert(count >= 2);
}
//CONSTANT MEMBER FUNCTIONS
template <class Item>
void graphM<Item>::print() const{
    for(size_t i = 0 ; i < capacity ; i++){
        for(size_t j = 0; j < capacity; j++){
            cout<<matrix[i][j];
        }
        cout<<"\n";
    }
}

template <class Item>
size_t graphM<Item>::numVertices() const{
    return count;
}

template <class Item>
size_t graphM<Item>::numEdges() const{
    assert(count != 0);
    size_t edgesCount = 0;
    for(size_t i = 0 ; i < capacity ; i++){
        for(size_t j = 0; j < capacity; j++){
            if(matrix[i][j] != 0){
                edgesCount++;
            }
        }
    }
    return edgesCount;
}

template <class Item>
bool graphM<Item>::isEdge(size_t source, size_t target) const{
    return (matrix[source][target] != 0);
}

template <class Item>
Item* graphM<Item>::neighbors(size_t vertex) const{

}

#endif