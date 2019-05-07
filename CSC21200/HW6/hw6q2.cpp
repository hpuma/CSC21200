#ifndef __GRAPHL_CPP__
#define __GRAPHL_CPP__
#include "hw6q2.h"

//CONSTRUCTOR
template<class Item>
graphL<Item>::graphL(){
	capacity = DEF_CAP;
	list = new node<graphData>*[capacity];
	//SET MATRIX
	for (size_t i = 0; i < capacity; i++){
		list[i] = NULL;
	}
	label = new Item[capacity];
	count = 0;
}

//COPY CONSTRUCTOR
template<class Item>
graphL<Item>::graphL(const graphL<Item>& source){

}

//MODODIFICATION MEMBER FUNCTIONS
template<class Item>
void graphL<Item>::addVertex(const Item& inLabel){
	label[count] = inLabel;	
	count++;
}

template<class Item>
void graphL<Item>::addEdge(size_t source, size_t target, int weight){
	graphData newData(target,weight);
	node<graphData>* newNode = new node<graphData>(newData);
	if(list[source] == NULL){
		list[source] = newNode;
	}
	else{
		node<graphData>*& curr = list[source];
		while(curr->link() != NULL){
			if(curr->data().getV() == target){
			curr->data().setW(weight);
			}
			else{
				curr = curr->link();
			}	
		}
		if(curr->link() == NULL){
			curr->set_link(newNode);
		}	
	}

}

template<class Item>
void graphL<Item>::removeEdge(size_t source, size_t target){
	if(count == 0){
		return;
	}
	node<graphData>* curr = list[source];
	node<graphData>* prev = curr;
	while((curr->data().getV() != target) && (curr != NULL)){
		prev = curr;
		curr = curr->link();
	}
	list_remove(prev);
}

//CONST MEMBER FUNCTIONS
template<class Item>
void graphL<Item>::print() const{
	for (size_t i = 0; i < count; i++){
		node<graphData>* curr = list[i];
		while(curr->link()!= NULL){
		cout<<label[i]<<"->"<<curr->data().getV();
		}
		cout<<"\n";
	}
}

template<class Item>
size_t graphL<Item>::numVertices() const{
	return count;
}

template<class Item>
size_t graphL<Item>::numEdges() const{
	size_t edgeCount = 0;
	for (size_t i = 0; i < count; i++){
		node<graphData>* curr = list[i];
		while(curr!= NULL){
			edgeCount++;
			curr = curr->link();
		}
	}
	return edgeCount;
}

template<class Item>
bool graphL<Item>::isEdge(size_t source, size_t target) const{
	if(count > 0){
	node<graphData> *curr = list[source];
		while(curr != NULL){
			if((curr->data() == target)){
				return true;
			}
			curr = curr->link();
		}	
	return false;
	}
	
}

template<class Item>
node<Item>* graphL<Item>::neighbors(size_t vertex) const{

}

#endif