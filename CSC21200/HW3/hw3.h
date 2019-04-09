#ifndef __NODE_H__
#define __NODE_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 3 header file

// Try not to change this file

#include <iostream>
#include <cstdlib>
#include <cassert>


using namespace std;

class Node {
    public:
        typedef int nodeDatatype;

        Node(const nodeDatatype& initData = nodeDatatype(),Node* initLink = NULL){
                data = initData; link = initLink;}

        void setData(const nodeDatatype& new_data) {data = new_data;}
        void setLink(Node* new_link)               {link = new_link;}

        nodeDatatype getData() const {return data;}

        const Node*  getLink() const {return link;}
              Node*  getLink()       {return link;}

    private:
        nodeDatatype data;
        Node* link;
};

void insertHead(Node*& head, Node*& entry);//
void insertTail(Node*& head, Node*& entry);//
void insertInd (Node*& head, Node*& entry, size_t pos);//
void insert    (Node*  prev, Node*  entry);//

void insertHead(Node*& head, const Node::nodeDatatype& entry);//
void insertTail(Node*& head, const Node::nodeDatatype& entry);//
void insertInd (Node*& head, const Node::nodeDatatype& entry, size_t pos);//
void insert    (Node*  prev, const Node::nodeDatatype& entry);//

bool isCycle(Node* head); // OMIT FOR NOW
bool isEmpty(Node* head); //
bool isValid(Node* head, size_t pos);//

size_t length(Node* head);// 

Node* listLocate      (Node* head, size_t position);//
const Node* listLocate(const Node* head, size_t pos);//

Node* listSearch      (Node* head, const Node::nodeDatatype& target); // CURRENTY
const Node* listSearch(const Node* head, const Node::nodeDatatype& target);

void removeHead  (Node*& head);//
void removeTail  (Node*& head);//
void removeInd   (Node*& head, size_t pos);
void remove      (Node*  prev);//
void removeAll   (Node*& head);
void removeFromTo(Node*& head, size_t from, size_t to);
void removeHeadTo(Node*& head, size_t to);
void removeToTail(Node*& head, size_t from);

void reverse(Node*& head);

void print(Node* head);

void swap(Node*& head, size_t pos);
void swap(Node*& head, size_t posI, size_t posJ);


#endif