#ifndef __GRAPHM_CPP__
#define __GRAPHM_CPP__
#include "hw6q1.h"

//CONSTRUCTOR
template <class Item>
graphM<Item>::graphM(){

}

//COPY CONSTRUCTOR
template <class Item>
graphM<Item>::graphM(const graphM<Item>& source){

}

//MODIFICATION MEMBER FUNCTIONS
template <class Item>
void graphM<Item>::addVertex(const Item& inLabel){

}

template <class Item>
void graphM<Item>::addEdge(size_t source, size_t target, int weight){

}

template <class Item>
void graphM<Item>::removeEdge(size_t source, size_t target){

}
//CONSTANCT MEMBER FUNCTIONS
template <class Item>
void graphM<Item>::print() const{

}

template <class Item>
size_t graphM<Item>::numVertices() const{

}

template <class Item>
size_t graphM<Item>::numEdges() const{

}

template <class Item>
bool graphM<Item>::isEdge(size_t source, size_t target) const{

}

template <class Item>
Item* graphM<Item>::neighbors(size_t vertex) const{

}

#endif