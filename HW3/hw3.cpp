#include "hw3.h"
// E: 3/14/19 6:55 AM
//
void insertHead(Node*& head, Node*& entry){
    entry->setLink(head); // Links the entry node to the head node.
    head = entry; // Sets the head pointer to the entry node, the entry node is the new head.
}
//
void insertTail(Node*& head, Node*& entry){
    Node *curr = head;
    if(head != NULL){ // When the list is NOT empty.
        while(curr->getLink() != NULL){ // Iteration.
            curr = curr->getLink();
        }
        entry->setLink(NULL);   // After we finish iterating, we set the entry node to NULL
        curr->setLink(entry);   // The tail node points to the entry node, the entry node is now the tail node.
    }
    if(head == NULL){   // When the head pointer is not pointing to anything.
        entry->setLink(NULL); // Set the entry link to NULL.
        head = entry;   // The entry node become the head.
    }    
}
//
void insertInd (Node*& head, Node*& entry, size_t pos){
    Node* curr = head;
    size_t index = 1; // Set the index to 1 so that we dont have to keep track of previous
    if(head != NULL){
        while ((curr != NULL) && (index != pos)){
            curr = curr->getLink();
            index++;
        }
        insert(curr,entry); // Apply the insert function... stops iterating before pos and inserts.
    }

    if(head == NULL){ // If the head pointer is not pointing to a node, then the entry node becomes the head node.
        head = entry;
    }
}
//
void insert(Node*  prev, Node*  entry){ // Inserts a node based on the previous node given.
    entry->setLink(prev->getLink()); // Sets the entry node before the position node.
    prev->setLink(entry);   // Links the previous node to the entry node, the entry node is now the position node.
}
//
void insertHead(Node*& head, const Node::nodeDatatype& entry){
    Node* newEntry = new Node(entry); // Creates a node with the data given by the user.
    if(head != NULL){   // If a head already exists, then the new node links to it.
    newEntry->setLink(head);
    }
    head = newEntry; // The new entry node is now the head node.
}
//
void insertTail(Node*& head, const Node::nodeDatatype& entry){
    Node* newEntry = new Node(entry); // Create a node with the data given by the user. BY DEFAULT: IT LINKS TO NULL.
    if(head != NULL){   // If the list is not empty, then iterate to the tail node.
        Node* curr = head;
        while(curr->getLink() != NULL){
            curr = curr->getLink();
        }
        curr->setLink(newEntry);    // Link the tail node to the new node. The new node is now the tail node.
    }
    if(head == NULL){   // If there is no head node, then make the new node the head node.
        head = newEntry;
    }
}
//
void insertInd(Node*& head, const Node::nodeDatatype& entry,size_t pos){

    if(head != NULL){ // When the linked list is not empty.
        Node* curr = head; // Prepare for iteratig.
        size_t index = 1; 

        while((curr != NULL)&&(index != pos)){
            curr = curr->getLink();
            index++;
        }

        if(index == pos){ // If we stop at the index, then insert the new node.
            insert(curr,entry);
        }     
    }

    if(head == NULL){ // If the list is empty, then make a new node with the given data and make it the head node.
        Node* newEntry = new Node(entry);
        head = newEntry;
    }
    
}
//
void insert(Node* prev, const Node::nodeDatatype& entry){ // We must know the node before the insert node... Inserts a node with the data given by the user
    Node* newEntry = new Node(entry, prev->getLink());
    prev->setLink(newEntry);
}
//
bool isCycle(Node* head){

    if(head->getLink() == NULL){return false;} // If there is only one node ... then it is not a cycle.
        Node* start = head; // A reference point for checking for a cycle.
        Node* curr = head;  // Used for iteration.

    while(curr != NULL){ // Begin iteration.
        if(curr = start){return true;} // If we find ourselves at the beginning again, then we are in a cycle so return true;
            curr = curr->getLink();
    }

    if(curr == NULL){return true;} // If we end the iteration and we are at NULL, then we are NOT in a cycle so return false;
 }

//
bool isEmpty(Node* head){ // Return if the head is pointing to NULL or NOT. Then we know our list is valid. Every list needs a head.
return (head == NULL);
}

//
bool isValid(Node* head, size_t pos){
     Node* curr = head;
    size_t index = 0;

    if((head == NULL)){return false;} // If the head pointer is pointing to null then there is no way for a list to contain a node in pos.

    if((head->getLink() == NULL) && (pos == 0)){return true;} // If we only have one node at position 0, and we are interested in that node, then it is valid so return true;
    
    while((curr->getLink() != NULL) && (index != pos)){ // If none of the above cases are true, then begin iteration.
        curr = curr->getLink();
        index++;
    }

    if(index == pos){return true;} // If we meet with the desired position, then it is valid so return true;

    if(index != pos){return false;} // If we have completed the cycle and we haven't met the position, then return false;
    
}

//
size_t length(Node* head){
    if(head == NULL){return 0;} // If the head pointer is pointing at null then the list length is 0.
    Node* curr = head;
    size_t index = 1; // Length begins at 1 if the list is not empty.

    while(curr->getLink() != NULL){ // Iteration that keeps track of the length.
        curr = curr->getLink();
        index++;
    }
return index;
}


Node* listLocate(Node* head, size_t position){
    Node* curr = head;
    size_t index = 0;
    while (curr->getLink() != NULL){
        curr = curr->getLink();
        index++;
        if(index == position){return curr;}
    }
return NULL; 
}

const Node* listLocate(const Node* head, size_t pos){

    Node headCopy =(*head);
    Node* curr = headCopy.getLink();
    size_t index = 1;

    while (curr->getLink() !=NULL){
        curr = curr->getLink();
        index++;
        if(index == pos){return curr;}
    }
return NULL; 
}


 
Node* listSearch(Node* head, const Node::nodeDatatype& target){
    Node* curr = head;
    while(curr->getLink() != NULL){
        if(curr->getData() == target){return curr;}
            curr = curr->getLink();
    }
return NULL; 
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
//
void removeHead(Node*& head){ // Begin at the head.
    Node* freeMe;
    freeMe =  head; // Set a temporary pointer to the head.
    head = head->getLink(); // Move one node after the head. The new head is the neighboring node.
    delete freeMe;  // Delete the head that is stored in the temporary pointer.
}
//
void removeTail(Node*& head){

    if(head->getLink() == NULL){removeHead(head);} // THIS TOOK ME VERY LONG TO FIGURE OUT ... but it was worth it, I learned something new. Remove the head if there is only one node!
    else{
        Node* curr = head;
        Node* prev;

        while(curr->getLink()!= NULL){ // Iteration, while keeping track of the node before
            prev = curr;
            curr = curr->getLink();
        }
        prev->setLink(NULL); // Isolate the tail node by breaking off the link bewteen the node tail and the node before it.
        delete curr; // Delete the tail node.
    }
}
//
void removeInd(Node*& head, size_t pos){
    if(head->getLink() == NULL){removeHead(head);} // Check if there is only one node in the linked list. If there is, then delete this node.

    if(head != NULL){ // If the list is not empty, then begin iterating.
        Node* curr = head;
        Node* prev;
        size_t index = 0; 
            while(curr->getLink() != NULL){ // Iterate, and keep track of the node before.
                prev = curr;
                curr = curr->getLink();
            }
            prev->setLink(curr->getLink()); // Now that we are at the prevoious node before the deletion node, then link the previous node to one node after the deletion node.
            delete curr; // Delete the deletion node.
        }
    }

void remove(Node* prev){
    Node* curr = prev ->getLink(); // Set this node to the deletion node.
    prev->setLink(curr->getLink()); // Set the node before the deletion node one after.
    delete curr; // Delete the deletion node.
}
//
void removeAll(Node*& head){
    Node* curr = head->getLink(); // Start one node after the head node.
    Node* freeMe; 
    while(curr != NULL){ // Begin iterating.
        freeMe = curr; // Set a pointer to the current node we're at.
        delete freeMe; // Delete the node.
        curr = curr->getLink(); // Go on to the next node. 
    }   
    head = NULL; // Reset the head pointer to NULL.
}

void removeFromTo(Node*& head, size_t from, size_t to){
    Node* curr = head;
    Node* entryStore;
    Node* freeMe;
    size_t index = 0, 
    from1 = from -1;
        while((curr != NULL)&&(index <= to)){ 
            if(index == from1){
                entryStore = curr; 
            }
            if (index > from ){ 
            freeMe = curr;
            curr = curr->getLink();
            delete freeMe;
            }
            index++;
        }
    entryStore->setLink(curr); 
}

void removeHeadTo(Node*& head, size_t to){
    Node* curr = head;
    Node* freeMe;
    size_t index = 0;
    while ((curr != NULL)&&(index <= to)){ 
        freeMe = curr;
        curr = curr->getLink();
        delete freeMe;
        index++;
    }
}

void removeToTail(Node*& head, size_t from){
    Node* curr = head;
    Node* freeMe; 
    size_t index = 0;
    while(curr != NULL){
        if(index > from){ 
            freeMe = curr; 
            curr = curr->getLink();
            delete freeMe; 
        }
        else{
        curr = curr->getLink();
        }
        index++;
    }
}
//
void reverse(Node*& head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* next = curr->getLink();
        curr->setLink(prev);
        prev = curr;
        curr = next;
    }
    head = prev;
}

void print(Node* head){
    Node* curr = head;
    while(curr != NULL){
        cout<<curr->getData()<<"\t-->";
        curr = curr->getLink();
    }
    cout<<" NULL\n";
}

//
void swap(Node*& head, size_t pos){
    size_t pos1,pos2, index = 0; 
    Node *N1, *N2; 
    Node* prev;

    if((pos == 0)&&(head->getLink()!= NULL)){ // When we only want to swap to items right next to each other.
        N1 = head; // The first node is the head node.
        N2 = head->getLink(); // The second node is linking to the node after the first node.
        N1->setLink(N2->getLink()); // The first node is linking to the node after the second node.
        N2->setLink(N1); // The second node is linking to the first node.
        head = N2;  // The second node is now the head node.
    }

    if((pos >=1) && (head->getLink()!= NULL)){ // If we want to swap nodes that are one node from each other.
    Node* curr = head; 
    pos1 = pos-1, pos2 = pos +1;

    while(index <= pos2){
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
}

//
void swap(Node*& head, size_t posI, size_t posJ){ // Swap nodes that are a certain amount nodes away from each other.
    Node* curr = head; 
    Node  *P1, *P2, *P3, *N1,*N2;
    size_t index = 0, pos1, pos2, pos3, pos4;

    if((head->getLink()!= NULL) &&(posI == 0)){
        swap(head,0);
    }

    if((head->getLink()!= NULL)&&(posI >=1)){
        pos1 = posI - 1;

        while(index <= posJ){
            if(index == pos1){ P1 = curr;}
            if(index == posI){ N1 = curr; }
            if(index == posJ){ N2 = curr;}

            curr = curr->getLink();
            index++;
        }
        N1->setLink(N2->getLink());
        N2->setLink(N1);
        P1->setLink(N2); 
    }
}

