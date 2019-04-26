#ifndef __GRAPHL_CPP__
#define __GRAPHL_CPP__
#include "hw6q2.h"

//CONSTRUCTOR
template<class Item>
graphL<Item>::graphL(){
}

//COPY CONSTRUCTOR
template<class Item>
graphL<Item>::graphL(const graphL<Item>& source){

}

//MODODIFICATION MEMBER FUNCTIONS
template<class Item>
void graphL<Item>::addVertex(const Item& inLabel){

}

template<class Item>
void graphL<Item>::addEdge(size_t source, size_t target, int weight){

}

template<class Item>
void graphL<Item>::removeEdge(size_t source, size_t target){

}

//CONST MEMBER FUNCTIONS
template<class Item>
void graphL<Item>::print() const{

}

template<class Item>
size_t graphL<Item>::numVertices() const{

}

template<class Item>
size_t graphL<Item>::numEdges() const{

}

template<class Item>
bool graphL<Item>::isEdge(size_t source, size_t target) const{

}

template<class Item>
node<Item>* graphL<Item>::neighbors(size_t vertex) const{

}

#endif