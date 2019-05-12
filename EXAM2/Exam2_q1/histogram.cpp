#include "hist.h"
#include "node.h"
#include<iostream>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;

node<hist>* histogram(node<int>* head){

node<hist>* newHead;
node<hist>* histCurr = newHead;

node<hist>* addHist;
node<int>* curr = head;
node<int>* traverse;

	while(curr->link() != NULL){
		
		hist newData(curr->data());
		addHist = new node<hist>(newData);
		traverse = curr->link();

		while(traverse->link() != NULL){
			if(traverse->data() == addHist->data().getData()){
				addHist->data().increaseCt();
			}
			traverse = traverse->link();
		}
		if(newHead == NULL){
			newHead = addHist;
			histCurr = newHead;
		}
		else{
			histCurr->set_link(addHist);
			histCurr = histCurr->link();
		}

		curr = curr->link();
	}
	return newHead;
}


int main(){
	node<int> node1(0);
	node<int>* head = &node1;
	node<int>* curr = head;
	for(int i = 1 ; i < 5; i++){
		node<int>* newNode = new node<int>(i);
		curr->set_link(newNode);
		curr = curr->link();
	}
	
	print_list(head);
	node<hist>* histHead = histogram(head);
	print_list(histHead);

	return 0;
}


