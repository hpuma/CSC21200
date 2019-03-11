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

void insertInd (Node*& head, Node*& entry, size_t pos){
    Node* curr = head;
    size_t count = 1;
    while ((curr->getLink() != NULL) && (count != pos)){
        curr = curr->getLink();
        count++;
    }
    insert(curr,entry); 
}
void insert(Node*  prev, Node*  entry){
    entry->setLink(prev->getLink());
    prev->setLink(entry);
}


//functions with given data only 
void insertHead(Node*& head, const Node::nodeDatatype& entry){
    Node* newEntry = new Node(entry,head->getLink());
    head->setLink(newEntry);
}
void insertTail(Node*& head, const Node::nodeDatatype& entry){
    Node* curr = head;
    while(curr->getLink() != NULL){
        curr = curr->getLink();
    }
    Node* newEntry = new Node(entry,NULL);
    curr->setLink(newEntry);
}
void insertInd(Node*& head, const Node::nodeDatatype& entry,size_t pos){
    Node* curr = head;
    Node* prev = curr;
    size_t count = 1;
    while((curr->getLink() != NULL)&&(count != pos)){
        prev = curr;
        curr = curr->getLink();
        count++;
    }
    if(count == pos){
        Node* newEntry = new Node(entry,curr->getLink());
        curr->setLink(newEntry);
    }

}

void insert(Node* prev, const Node::nodeDatatype& entry){
    Node* newEntry = new Node(entry, prev->getLink());
    prev->setLink(newEntry);
}

//isCycle is OMMITED FOR NOW
// bool isCycle(Node* head);

// When the list is empty, the head MUST point at NULL.
bool isEmpty(Node* head){
return (head->getLink() == NULL);
}

// Checks if an index exists in a list
bool isValid(Node *head, size_t pos){
    Node* curr = head;
    size_t count = 0;
    while(curr->getLink() !=NULL){
        curr = curr->getLink();
        count++;
        if(count == pos){return true;}
    }
    return false; // If we have iterated throughout the entire list and we have not found the index pos.
}

// Returns the length of the linked list ... NEED TO VERIFY
size_t length(Node* head){
    Node* curr = head;
    size_t count = 1;
    while(curr->getLink() != NULL){
        curr = curr->getLink();
        count++;
    }
    return count;
}

// Checks if a current node exists at a certain position
Node* listLocate(Node* head, size_t position){
    Node* curr = head;
    size_t index = 0;
    while (curr->getLink() !=NULL){
        curr = curr->getLink();
        index++;
        if(index == position){return curr;}
    }
    return NULL; // the position has not been found ... then return NULL.
}
// listLocate version 2, with const pointer 
const Node* listLocate(const Node* head, size_t pos){
    // We dereferenced the pointer, made a copy, and took its link, MUST START at 1
    Node headCopy =(*head);
    Node* curr = headCopy.getLink();
    size_t index = 1;

    while (curr->getLink() !=NULL){
        curr = curr->getLink();
        index++;
        if(index == pos){return curr;}
    }
    return NULL; // the position has not been found ... then return NULL.
}


// CURRENTLY
Node* listSearch(Node* head, const Node::nodeDatatype& target){
return NULL;
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
void removeInd   (Node*& head, size_t pos){}
void remove(Node* prev){
	Node* curr;
	curr = prev ->getLink();
	prev -> setLink(curr->getLink());
	delete curr;
}
void removeAll   (Node*& head){}
void removeFromTo(Node*& head, size_t from, size_t to){}
void removeHeadTo(Node*& head, size_t to){}
void removeToTail(Node*& head, size_t from){}

void reverse(Node*& head){}

void print(Node* head){}

void swap(Node*& head, size_t pos){}
void swap(Node*& head, size_t posI, size_t posJ){}