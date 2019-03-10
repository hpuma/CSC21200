#include "hw3.h"


void insertHead(Node*& head, Node*& entry){
entry->setLink(head->getLink());
head->setLink(entry);
}
void insertTail(Node*& head, Node*& entry){
    Node* curr = head;
    while(curr->getLink() != NULL){ 
        curr = curr->getLink();
    }
    curr->setLink(entry);
    entry->setLink(NULL);
}

void insertInd(Node*& head, Node*& entry, size_t pos){
    Node *curr = head;
    size_t count = 0;
    while(curr->getLink()!=NULL && count != pos){
        curr = curr->getLink();
        count++;
    }
    if(count == pos){
        entry->setLink(curr->getLink());
        curr->setLink(entry);
    }
}

void insert(Node*  prev, Node*  entry){
entry->setLink(prev->getLink());
prev->setLink(entry);
}

void insertHead(Node*& head, const Node::nodeDatatype& entry){
    Node* newNode = new Node(entry,head->getLink());
    head->setLink(newNode);
}


















void removeHead(Node* head){
	Node* curr = head; //When you make a pointer... you make an object that contains the address of the item you're pointing at
	head = curr ->getLink();
	delete curr; //delete the node where the curr is pointing at... delete is a keyword
}
void removeTail(Node* head){
	Node* curr = head;
	Node* prev; // keeps track of the previous head

	while(curr -> getLink() != NULL){ //looks through the list until it encounters null
		prev = curr;
		curr = curr ->getLink();
	}
	remove(prev);
}

void remove(Node* prev){
	Node* curr;
	curr = prev ->getLink();
	prev -> setLink(curr->getLink());
	delete curr;
}