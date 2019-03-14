#include "hw3.h"

//
void insertHead(Node*& head, Node*& entry){
    entry->setLink(head);
    head = entry;
}
//
void insertTail(Node*& head, Node*& entry){
    Node *curr = head;
    if(head != NULL){
        while(curr->getLink() != NULL){ 
            curr = curr->getLink();
        }
        entry->setLink(NULL);
        curr->setLink(entry);
    }
    if(head == NULL){
        entry->setLink(NULL);
        head = entry;
    }    
}
//
void insertInd (Node*& head, Node*& entry, size_t pos){
    Node* curr = head;
    size_t index = 1;
    if(head != NULL){
        while ((curr != NULL) && (index != pos)){
            curr = curr->getLink();
            index++;
        }
        insert(curr,entry); 
    }

    if(head == NULL){
        head = entry;
    }
}
//
void insert(Node*  prev, Node*  entry){
    entry->setLink(prev->getLink());
    prev->setLink(entry);
}
//
void insertHead(Node*& head, const Node::nodeDatatype& entry){
    Node* newEntry = new Node(entry);
    if(head != NULL){
    newEntry->setLink(head);
    }
    head = newEntry;
}
//
void insertTail(Node*& head, const Node::nodeDatatype& entry){
    Node* newEntry = new Node(entry);
    if(head != NULL){
        Node* curr = head;
        while(curr->getLink() != NULL){
            curr = curr->getLink();
        }
        curr->setLink(newEntry);
    }
    if(head == NULL){
        head = newEntry;
    }
}
//
void insertInd(Node*& head, const Node::nodeDatatype& entry,size_t pos){

    if(head != NULL){
        Node* curr = head;
        size_t index = 1;

        while((curr != NULL)&&(index != pos)){
            curr = curr->getLink();
            index++;
        }

        if(index == pos){
            insert(curr,entry);
        }     
    }

    if(head == NULL){
        Node* newEntry = new Node(entry);
        head = newEntry;
    }
    
}
//
void insert(Node* prev, const Node::nodeDatatype& entry){
    Node* newEntry = new Node(entry, prev->getLink());
    prev->setLink(newEntry);
}
//
bool isCycle(Node* head){

    if(head->getLink() == NULL){return false;}
        Node* start = head;
        Node* curr = head;

    while(curr != NULL){
        if(curr = start){return true;}
            curr = curr->getLink();
    }

    if(curr == NULL){return true;}
 }

//
bool isEmpty(Node* head){
return (head == NULL);
}

//
bool isValid(Node* head, size_t pos){
     Node* curr = head;
    size_t index = 0;

    if((head == NULL)){return false;}

    if((head->getLink() == NULL) && (pos == 0)){return true;}
    
    while((curr->getLink() != NULL) && (index != pos)){
        curr = curr->getLink();
        index++;
    }

    if(index == pos){return true;}

    if(index != pos){return false;}
    
}

//
size_t length(Node* head){
    if(head == NULL){return 0;}
    Node* curr = head;
    size_t index = 1;

    while(curr->getLink() != NULL){
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
void removeHead(Node*& head){
    Node* freeMe;
    freeMe =  head;
    head = head->getLink();
    delete freeMe;
}
//
void removeTail(Node*& head){

    if(head->getLink() == NULL){removeHead(head);} // THIS TOOK ME VERY LONG TO FIGURE OUT ... but it was worth it, I learned something new.
    else{
        Node* curr = head;
        Node* prev;

        while(curr->getLink()!= NULL){
            prev = curr;
            curr = curr->getLink();
        }
        prev->setLink(NULL);
        delete curr;
    }
}
//
void removeInd(Node*& head, size_t pos){
    if(head->getLink() == NULL){removeHead(head);}

    if(head != NULL){
        Node* curr = head;
        Node* prev;
        size_t index = 0; 
            while(curr->getLink() != NULL){
                prev = curr;
                curr = curr->getLink();
            }
            prev->setLink(curr->getLink());
            delete curr;
        }
    }

void remove(Node* prev){
    Node* curr = prev ->getLink(); 
    prev->setLink(curr->getLink()); 
    delete curr; 
}
//
void removeAll(Node*& head){
    Node* curr = head->getLink();
    Node* freeMe; 
    while(curr != NULL){ 
        freeMe = curr; 
        delete freeMe; 
        curr = curr->getLink();     
    }   
    head = NULL;
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

    if((pos == 0)&&(head->getLink()!= NULL)){
        N1 = head;
        N2 = head->getLink();
        N1->setLink(N2->getLink());
        N2->setLink(N1);
        head = N2;
    }

    if((pos >=1) && (head->getLink()!= NULL)){
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
void swap(Node*& head, size_t posI, size_t posJ){
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

