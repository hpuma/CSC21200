#include "hw3.h"
void insertHead(Node*& head, Node*& entry){
Node* newEntry = new Node(entry->getData(),head);
head = newEntry;
}
void insertTail(Node*& head, Node*& entry){
    
    Node* prev;
    Node* curr = head;
    while(curr->getLink() != NULL){ 
        prev = curr;
        curr = curr->getLink();
    }
    Node* newData = new Node(entry->getData(),prev);
    prev = newData;
    delete curr;
}

void insertInd (Node*& head, Node*& entry, size_t pos){
    Node* curr = head;
    size_t count = 0 ;
    while ((curr->getLink() != NULL) && (count != pos)){
        curr = curr->getLink();
        count++;
    }
    if (count == pos){
        Node* newEntry  = new Node(entry->getData(),curr);
        curr = newEntry;
    }
}
void insert(Node*  prev, Node*  entry){

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