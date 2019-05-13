#ifndef __GRAPHL_CPP__
#define __GRAPHL_CPP__
#include "hw6q2.h"

//CONSTRUCTOR
template<class Item>
graphL<Item>::graphL(){
	capacity = DEF_CAP;
	list = new node<graphData>*[capacity]; // Make an array with node<graphData> pointers.
		//SET MATRIX
		for (size_t i = 0; i < capacity; i++){ // Make each pointer in the array point to NULL.
			list[i] = NULL;
		}
	label = new Item[capacity]; // Make an array to hold the vertices.
	count = 0; // There are no edges so far.
}

//COPY CONSTRUCTOR .. NT
template<class Item>
graphL<Item>::graphL(const graphL<Item>& source){
	// Copy over private variables values from source.
	capacity = source.capacity;
	count = source.count;
	label = new Item[capacity];

	list = new node<graphData>*[capacity]; // Initialize Array for list.
	for (size_t i = 0; i < count; i++){ // Iterate through the source list.
		if(source.list[i] != NULL){ // If there is an edge for this label.
			node<graphData>* newHead = NULL;
			node<graphData>* tail = NULL;
			node<graphData>* sourcePtr = source.list[i]; // Copy of source head.
			list_copy(sourcePtr,newHead,tail);
			list[i] = newHead;
		}
		else{
			continue; // If there isn't an edge for this label aka vertice then move on.
		}
	}
}

//MODIFICATION MEMBER FUNCTIONS
// Make sure there is room to add another vertice.
template<class Item>
void graphL<Item>::addVertex(const Item& inLabel){
	if(count < capacity){ 
		label[count] = inLabel;	
		count++;
	}
}

// Make sure the vertices index exist in the label array.
template<class Item>
void graphL<Item>::addEdge(size_t source, size_t target, int weight){
	if((source < count ) && (target < count) && (weight > 0)){ 
	// Make a node containing the vertex it connects to and the weight of this edge we're making.
	graphData newData(target,weight);
	node<graphData>* newNode = new node<graphData>(newData);

		// If this vertice doesn't have any edges yet, then make this the first edge.
		if(list[source] == NULL){
			list[source] = newNode;
		}
		else{
			// If this vertice already has an edge.
			node<graphData>*curr = list[source]; // Point to the first edge.
			node<graphData>*prev = curr; // Make a previous pointer.
			if(curr->data().getV() == target){ // When the first node has the value of target, then an edge already exists, then change it's weight and leave the function.
					curr->data().setW(weight);
					return;
				}
			while(curr->link() != NULL){ // When the edge doesn't exist yet. Go to the very last node.
				curr = curr->link();	
			}
			curr->set_link(newNode); // Add the new new node/edge.
		}
	}
}

// Make sure the vertices index exist in the label array.
template<class Item>
void graphL<Item>::removeEdge(size_t source, size_t target){
	if((source < count ) && (target < count)){ 
		if(list[source] == NULL){ // When the vertice doesn't have an edge, then leave the function.
			return;
		}
		if(list[source]->data().getV() == target){ // If the edge already exists at the first node, then change it's weight and exit the function.
			list_head_remove(list[source]);
			return;
		}
		node<graphData>* curr = list[source];
		while(curr->link() != NULL){
			if(curr->data().getV() == target){ // If we find the edge, then remove the node and leave the function.
				list_remove(curr);
				return;
			}
			curr = curr->link();
		}	
	}
}

//CONST MEMBER FUNCTIONS
template<class Item>
void graphL<Item>::print() const{
	for (size_t j = 0; j < count; j++){// Print label first.
		node<graphData>* curr = list[j];
		cout<<label[j]<<"->";
		while(curr!= NULL){ // Iterate throughout the entire linked list.
			cout<<curr->data().getV()<<"|"<<curr->data().getW(); // Print out the Vertex | Weight : This is an edge.
			if(curr->link() != NULL){ // As long as we're not the last node, print out ->
				cout<<"->";
			}
			curr = curr->link();
		}
		cout<<"\n"; // After we printed out the entire list of edges.
	}
}

// Return the number of labels.
template<class Item>
size_t graphL<Item>::numVertices() const{
	return count;
}

template<class Item>
size_t graphL<Item>::numEdges() const{
	size_t edgeCount = 0;
	for(size_t i = 0 ; i < count; i++){
		node<graphData>* curr = list[i]; // Point to the first index of the list.
		if(curr == NULL){ // If the index doesn't point to a node.
			if(i != count-1){ // If this index isn't the last index, go on to the next pointer in the list array.
				continue;
			}	
		}
		else{
			while(curr != NULL){ // Let's iterate through the entire linked list, and keep track of the number of edges.
				edgeCount++;
				curr = curr->link();
			}
		}
	}
	return edgeCount;
}

// Make sure the index of the label array exists, this means that the vertices exist.
template<class Item>
bool graphL<Item>::isEdge(size_t source, size_t target) const{
	if(count > 0){
	node<graphData> *curr = list[source]; 
		while(curr != NULL){ // Iterate through the entire linked list.
			if(curr->data().getV() == target){ // If we found an edge, then return true.
				return true;
			}
			curr = curr->link();
		}	
	return false; // We iterated throughout the entire linked list, the edge connected to the target hasn't been found.
	}
}

// Make sure the vertice has any edges.
template<class Item>
node<Item>* graphL<Item>::neighbors(size_t vertex) const{
	node<Item>* newHead = NULL; // Head of Linked list of neighbors.

	if(list[vertex] != NULL){
		node<graphData>* startNode = list[vertex]; // Pointer that points to the source pointer.

		newHead = new node<Item>(label[startNode->data().getV()]); // Make the first neighbor.
		node<Item>* nodeBuild = newHead; // Make a pointer to points to that neighbor, this node will do the building.
		startNode = startNode->link(); // Move over the source pointer.

		// In this loop we will build, set link, then move to the next node.
		while(startNode != NULL){
			node<Item>* newNode = new node<Item>(label[startNode->data().getV()]); // Build the node.
			nodeBuild->set_link(newNode); // Set the link to that new node.

			nodeBuild = nodeBuild->link(); // move to that newly created link.
			startNode = startNode->link(); // move to the next neighbor node. 
		}	
	}
	return newHead;
}

#endif