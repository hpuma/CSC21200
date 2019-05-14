#ifndef __GRAPHM_CPP__
#define __GRAPHM_CPP__
#include "hw6q1.h"

//CONSTRUCTOR
template <class Item>
graphM<Item>::graphM(){
    capacity = DEF_CAP;
    // NOTE label Array contains the vertexs.
    label = new Item[capacity](); // Initialize an array with default values of the type ... Default value for any type.. or only for int?
    // NOTE: matrix  Array contains the intersection of vertexs, basically which two vertex connect.
    matrix = new int*[capacity]; // Columns of matrix.
    for (size_t i = 0; i < capacity; i++){ // Rows of matrix.
        matrix[i] = new int[capacity]();
    } 
    //NOTE: count keeps track of the number of vertices.
    count = 0; 
}

//COPY CONSTRUCTOR
template <class Item>
graphM<Item>::graphM(const graphM<Item>& source){
    //COPY PRIVATE MEMBER VARIABLES
    capacity = source.capacity;
    count = source.count;
    matrix = new int*[capacity];

    // Iterate throughout the entire matrix. 
    for (size_t i = 0; i < capacity; i++){
        matrix[i] = new int[capacity](); // Make a new array for each element.
        for(size_t j = 0; j < count;  j++){ // After the array is added, copy over the contents from the source.
            matrix[i][j] = source.matrix[i][j];
        }
    }
    // Make a new dynamic array for label
    label = new Item[capacity];
    for (size_t k = 0; k < capacity; k++){
        label[k] = source.label[k]; // Copy over the contents from the source label array.
    }   
}
//DECONSTRUCTOR?? ... DOESN'T MATTER IN THIS CASE 

//MODIFICATION MEMBER FUNCTIONS
template <class Item>
void graphM<Item>::addVertex(const Item& inLabel){
    if(count < capacity){ // Make sure there is room to add vertex.
    label[count] = inLabel;
    count++;
    }    
}

// Make sure there is at least 1 vertex.
// Make sure the target and vertex values are in the matrix.
// Make sure the weight is NOT a negative number.
template <class Item>
void graphM<Item>::addEdge(size_t source, size_t target, int weight){
    if((count > 0) && (source < capacity) && (target < capacity) && (weight > 0)){
    	matrix[source][target] = weight;
    }   
}

// Make sure there is at least 1 vertex.
// Make sure the target and vertex values are in the matrix.
template <class Item>
void graphM<Item>::removeEdge(size_t source, size_t target){
    if((count > 0) && (source < capacity) && (target < capacity)){
    	matrix[source][target] = 0;
    }    
}

//CONSTANT MEMBER FUNCTIONS
template <class Item>
void graphM<Item>::print() const{
    if(count > 0){
        // HORIZONTAL LABELS
        cout<<setw(2)<<""; // Used to add spacing before the first label.
    	for (size_t i = 0; i < count; i++){
        	cout<<label[i];
        	cout<<setw(1)<<""; // Add one space after each label.
    	}
    	cout<<"\n";
   		for (size_t j = 0; j < count; j++ ){
        	cout<<label[j];// Print vertical label.
        	cout<<setw(1)<<""; // Add space after vertical label.
        	for (size_t k = 0; k < count; k++){// Print out the matrix. 1 == edge, 0 = no edge.
            	cout<<matrix[j][k];
            	cout<<setw(1)<<"";
        		}
        	cout<<"\n";
    	}
   	}
}

// Basically return the number of labels which is the number of vertices.
template <class Item>
size_t graphM<Item>::numVertices() const{
    return count;
}

template <class Item>
size_t graphM<Item>::numEdges() const{
    size_t edgesCount = 0; 
    // Iterate vertically. We stop at count because that is where the vertices exist!
    for(size_t i = 0; i < count; i++){
        for(size_t j = 0; j < count; j++){ // Iterate horizontaly.
            if(matrix[i][j] != 0){
                edgesCount++;
            }
        }
    }
    return edgesCount;
}

template <class Item>
bool graphM<Item>::isEdge(size_t source, size_t target) const{
    // Check the array at the intersection. Return whether or not there is a weight in the interesction.
    return (matrix[source][target] > 0);
}

template <class Item>
Item* graphM<Item>::neighbors(size_t vertex) const{
    if(count > 0){
    	Item* myNeighbors = new Item[count](); // Make an array to store the possible neighbors.
    	size_t neighCount= 0;
        	for(size_t i = 0; i < count; i++){ // Iterate through matrix.
            	if(matrix[vertex][i] > 0){ // 
                	myNeighbors[neighCount] = label[i]; // Add the label to the array of neighbors.
                	neighCount++;
            	}
        	}
    // Take our array and resize it nicely ... functon resize is given in the header file.
    myNeighbors = resize(myNeighbors,neighCount); // NOTE: can't return resize(myNeighbors,neighCount); because you can't return template types.
    return myNeighbors;
    } 
}
#endif
