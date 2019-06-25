#include "hist.h"
#include "node.h"
#include<iostream>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
node<int>* array_to_list(int inputArray[],size_t arraySize){
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
	if(head == NULL){ // When we're given a linked list.
		cout<<"HEAD IS NULL\n";
		return NULL;
	}
	size_t arraySize = list_length(head);
	int* nodeValue = new int[arraySize]; // Make a new array the size of the linked list.
	node<int>* ptr = head;
	// Adding everything to the array.
	for(size_t i = 0; i < arraySize; i++){
		nodeValue[i] = ptr->data();
		ptr = ptr->link();
	}
	// Sorting the array.
	for(size_t j = 0; j < arraySize; j++){
		for(size_t k = j+1; k < arraySize; k++){
			if(nodeValue[k] < nodeValue[j]){
				int temp = nodeValue[j];
				nodeValue[j] = nodeValue[k];
				nodeValue[k] = temp;
			}
 		}
	}
	hist headVal(nodeValue[0]);
	node<hist>* histHead = new node<hist>(headVal);
	node<hist>* builder = histHead;
	node<hist>* sentinel  = NULL;

	for(size_t l = 1; l < arraySize; l++){
		if(nodeValue[l] != nodeValue[l-1]){
			hist histMake(nodeValue[l]);
			sentinel = new node<hist>(histMake);
			builder->set_link(sentinel);
			builder = sentinel;
		}
		else{
			builder->data().increaseCt();
		}
	}
	return histHead;
}


int main(){
	int myArr[] = {1,5,2,6,2,2,5,1,5,1};
	size_t myArrSize = 10;
	node<int>* head = array_to_list(myArr,myArrSize);
	node<hist>* histHead = histogram(head);
	print_list(histHead);
	return 0;
}


