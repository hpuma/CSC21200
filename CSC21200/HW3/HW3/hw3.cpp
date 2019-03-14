#include "hw3.h"
//
void insertHead(Node*& head, Node*& entry){
    if(head == NULL){
        head = entry;
    }
    else{
        entry->setLink(head);
        head = entry;
    }
}
//
void insertTail(Node*& head, Node*& entry){
    Node *curr = head;
    if(head == NULL){
    head = entry;
    }
    else{
        while(curr->getLink() != NULL){ 
            curr = curr->getLink();
        }
        curr->setLink(entry);
    }   
}
//
void insertInd (Node*& head, Node*& entry, size_t pos){
    Node* curr = head;
    size_t index = 1;
    if(head == NULL){
        head = entry;
    }
    else{
        while ((curr != NULL) && (index != pos)){
            curr = curr->getLink();
            index++;
        }
        insert(curr,entry); 
    }
}
//
void insert(Node*  prev, Node*  entry){
    entry->setLink(prev->getLink());
    prev->setLink(entry);
}


//functions with given data only //
void insertHead(Node*& head, const Node::nodeDatatype& entry){
    if(head == NULL){
        Node* newEntry = new Node(entry);
        head = newEntry;
    }
    else{
        Node* newEntry = new Node(entry,head); 
        head = newEntry; 
    }
    
}
//
void insertTail(Node*& head, const Node::nodeDatatype& entry){
    Node* curr = head;
    Node newEntry(entry,NULL);
    Node* newEntry_p = &newEntry;
    while(curr->getLink() != NULL){
        curr = curr->getLink();
    }
curr->setLink(newEntry_p);

}
//
void insertInd(Node*& head, const Node::nodeDatatype& entry,size_t pos){
    if(head == NULL){
        Node* newEntry = new Node(entry,NULL);
        head = newEntry;
    }
    else{
        Node* curr = head;
        size_t index = 1;

        while((curr->getLink() != NULL)&&(index != pos)){
            curr = curr->getLink();
            index++;
        }
        if(index == pos-1){
            Node* newEntry = new Node(entry,curr->getLink());
            curr->setLink(newEntry);
        }
    }
}
//
void insert(Node* prev, const Node::nodeDatatype& entry){
    Node* newEntry = new Node(entry, prev->getLink());
    prev->setLink(newEntry);
}

//isCycle is OMMITED FOR NOW 

 bool isCycle(Node* head){
     return true;
 }

// When the list is empty, the head MUST point at NULL.
bool isEmpty(Node* head){
return (head->getLink() == NULL);
}

// Checks if an index exists in a list
bool isValid(Node* head, size_t pos){
    Node* curr = head;
    size_t index = 0;
    while(curr->getLink() !=NULL){
        curr = curr->getLink();
        index++;
        if(index == pos){return true;}
    }
    return false; // If we have iterated throughout the entire list and we have not found the index pos.
}

// Returns the length of the linked list ... NEED TO VERIFY
size_t length(Node* head){
    Node* curr = head;
    size_t index = 1;
    while(curr->getLink() != NULL){
        curr = curr->getLink();
        index++;
    }
    return index;
}

// Checks if a current node exists at a certain position
Node* listLocate(Node* head, size_t position){
    Node* curr = head;
    size_t index = 0;
    while (curr->getLink() != NULL){
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


// Searches the list for a specific data 
Node* listSearch(Node* head, const Node::nodeDatatype& target){
Node* curr = head;
while(curr->getLink() != NULL){
    if(curr->getData() == target){return curr;}
    curr = curr->getLink();
}
return NULL; // when the list does not find the target data
}
// listSearch 2.0
const Node* listSearch(const Node* head, const Node::nodeDatatype& target){
    const Node* curr = head;
    while(curr->getLink() != NULL){
        if(curr->getData() == target){return curr;}
        curr = curr->getLink();
    }
    return NULL;
}



void removeHead(Node*& head){
	Node* removeHead = head;
    head = removeHead->getLink();
    delete removeHead;
}
void removeTail(Node*& head){
	Node* curr = head;
	while(curr -> getLink() != NULL){ //looks through the list until it encounters null
		curr = curr ->getLink();
	}
	delete curr;
}
void removeInd(Node*& head, size_t pos){
    assert(pos != 0); // This function will work on anything besides the head because there is no way of getting the previous node before the HEAD!
    Node* curr = head;
    Node* prev;
    size_t index = 0; // Used to keep track of the index we are currently in
    while(curr->getLink() != NULL){
        if(index == pos){ 
            remove(prev);
            break;
        }
        prev = curr;
        curr = curr->getLink();
        index++;
    }
}
//You must know the node before the one you want to delete.


void remove(Node* prev){
    Node* curr = prev ->getLink(); // You set curr to the node you want to delete
    prev -> setLink(curr->getLink()); // Set prev to the node that the delete node is looking at
	delete curr; // This deleted the node marked for deletion.
}
void removeAll(Node*& head){
    Node* curr = head;
    Node* freeMe; // Temp storage for deleted node
    while(curr != NULL){ // Goes through the entire loop and deletes each node
        freeMe = curr; // Store the node marked for deletion
        curr = curr->getLink(); // Move on t the next node
        delete freeMe; //  Delete the node marked for deletion.
        //NOTE: delete is faster than free()
    }
}
void removeFromTo(Node*& head, size_t from, size_t to){
Node* curr = head;
Node* entryStore;
Node* freeMe;
size_t index = 0, 
from1 = from -1; // from1 : the index of the node that is before the first deleted node
while((curr != NULL)&&(index <= to)){ // .. NOT SURE IF DELETION IS INCLUSIVE OR NOT 
    if(index == from1){
        entryStore = curr; // Store the previous node that is being delete... this will be used to link the right most node after everything has been deleted.
        curr = curr->getLink();
    }
    if (index > from ){ // reponsible for deleting the NODES 
        freeMe = curr;
        curr = curr->getLink();
        delete freeMe;
    }
    index++;
}
entryStore->setLink(curr); // Links the left most node to the right most node;
}

void removeHeadTo(Node*& head, size_t to){
    Node* curr = head;
    Node* freeMe;
    size_t index = 0;
    while ((curr != NULL)&&(index <= to)){ // Only iterate up to the to position... that's what we care about being deleted 
        freeMe = curr;
        curr = curr->getLink();
        delete freeMe;
        index++;
    }
}
void removeToTail(Node*& head, size_t from){
    Node* curr = head;
    Node* freeMe; // used to store the node we're deleting 
    size_t index = 0;
    while(curr != NULL){
        if(index > from){ // onced we are greater than from .. we start deleting nodes 
            freeMe = curr; // set deleted node to free me
            curr = curr->getLink(); // move on to next node first!
            delete freeMe; // delete the node
        }
        else{
        curr = curr->getLink();
        }
        index++;
    }
}

//reverses the entire list
void reverse(Node*& head){}

// prints out the entire linked list
void print(Node* head){
    Node* curr = head;
    while(curr != NULL){
        cout<<curr->getData()<<"|\t";
        curr = curr->getLink();
    }
}

// fixed
void swap(Node*& head, size_t pos){
    Node* curr = head; // as always 
    Node *N1, *N2; // Points to the nodes that must be swapped.
    Node* prev; // STORES NODE BEFORE FIRST NODE "N1"

    size_t pos1 = pos-1, pos2 = pos +1, index = 0; 
    // pos1 : index of node before first the first swapped "prev"
    //pos: index of first node being swapped "N1"
    // pos2 : index of second node being swapped "N2"

    while(index <= pos2){
        // Conditions on setting up prev, N1, and N2
        if(index == pos1){ prev = curr;}
        if(index == pos) {  N1 = curr; }
        if(index == pos2){ N2 = curr;  }
        curr = curr->getLink();
        index++;
    }
    N1->setLink(N2->getLink());
    N2->setLink(N1);
    prev->setLink(N2);
}

//MUST TEST
void swap(Node*& head, size_t posI, size_t posJ){
    Node* curr = head; 
    Node  *P1, *P2, *P3, *P4, *N1,*N2;
    size_t index = 0, 
    pos1 = posI - 1, 
    pos2 = posI + 1,
    pos3 = posJ - 1,
    pos4 = posJ + 1;    

    while(index < pos4){
        if(index == pos1){ P1 = curr;}
        if(index == posI){ N1 = curr;}
        if(index == pos2){ P2 = curr;}
        if(index = pos3){ P3 = curr;}
        if(index = posJ){ N2 = curr;}
        if(index = pos4){ P4 = curr;}
        curr = curr->getLink();
        index++;
    }
    N1->setLink(P4);  
    P3->setLink(N1);

    N2->setLink(P2);
    P1->setLink(N2);


}