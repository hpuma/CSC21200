#include "hist.h"
#include "node.h"
#include<iostream>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
// Function that takes an array and turns it into a linked list.
node<int>* array_to_list(int inputArray[],size_t arraySize){
	if(arraySize == 0){
		return NULL;
	}
	node<int>* head = new node<int>(inputArray[0]);
	node<int>* builder = head;
	node<int>* sentinel = NULL;
	for(size_t i = 1; i < arraySize; i++){
		sentinel = new node<int>(inputArray[i]);
		builder->set_link(sentinel);
		builder = builder->link();
	}
	return head;
}


node<hist>* histogram(node<int>* head){
	if(head == NULL){ // When the head pointer is pointing to NULL.
		cout<<"HEAD IS NULL\n";
		return NULL;
	}
	size_t arraySize = list_length(head); // Get the length of the current linked list.
	int* nodeValue = new int[arraySize]; // Make a new array that is the size of the linked list
	node<int>* ptr = head; // Set a pointer to the head of the linked list.
	// Adding everything  from the linked list to the array.
	for(size_t i = 0; i < arraySize; i++){
		nodeValue[i] = ptr->data();
		ptr = ptr->link();
	}
	// Sorting the array. All the duplicates will be right next to each other.
	for(size_t j = 0; j < arraySize; j++){
		for(size_t k = j+1; k < arraySize; k++){
			if(nodeValue[k] < nodeValue[j]){
				int temp = nodeValue[j];
				nodeValue[j] = nodeValue[k];
				nodeValue[k] = temp;
			}
 		}
	}
	hist headVal(nodeValue[0]); // Makes a hist item that contains the first value of the array.
	node<hist>* histHead = new node<hist>(headVal); // Set the node<hist> head pointer to a new node containing headVal.
	node<hist>* builder = histHead; // Set a builder pointer to the head of the linked list.
	node<hist>* sentinel  = NULL; // Making a dummy node that will be used to make a new node.
	// We begin at 1 because we already took the first value of the array already.
	for(size_t l = 1; l < arraySize; l++){
		if(nodeValue[l] != nodeValue[l-1]){ // When the current value doesn't equal the previous value.
			hist histMake(nodeValue[l]); // Make a hist of the uniq value, the count is already set to 1.
			sentinel = new node<hist>(histMake); // Make a node containing the hist item from above.
			builder->set_link(sentinel); // Make the "builder" pointer set the link to the dummy node "sentinel".
			builder = builder->link(); // A new node ahead has been created, lets go to it.
		}
		else{ // When the current value equals the previous value.
			builder->data().increaseCt(); // The value has repeated itself... increment the value within the linked list
		}
	}
	return histHead; // Return the head of the list.
}


int main(){
	int myArr[] = {1,5,2,6,2,2,5,1,5,1};
	size_t myArrSize = 10;
	node<int>* head = array_to_list(myArr,myArrSize);
	node<hist>* histHead = histogram(head);
	print_list(histHead);
	return 0;
}


