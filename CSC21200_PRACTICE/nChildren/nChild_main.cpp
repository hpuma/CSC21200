#include <iostream>
#include "nChild.h"
using namespace std;

    template <class Item>
    void printChildren(nChild<Item>* parent,size_t count){
        nChild<Item>** children = parent->getChildren();
        cout<<"Children of "<<parent->getData()<<"\n";
        for(size_t i = 0; i < count; i++){
            cout<<children[i]->getData()<<"\n";
        }
    }


int main(){
    nChild<int> *root = new nChild<int>(10);
    nChild<int> *newNode = NULL;

    newNode =  new nChild<int>(2);
    root->addChild(newNode);
    newNode =  new nChild<int>(34);
    root->addChild(newNode);
    newNode =  new nChild<int>(56);
    root->addChild(newNode);
    newNode =  new nChild<int>(100);
    root->addChild(newNode);
    
    // test children list.
    printChildren(root,root->size());

    newNode =  new nChild<int>(77);
    root->getChild(0)->addChild(newNode);
    newNode =  new nChild<int>(88);
    root->getChild(0)->addChild(newNode);
    newNode =  new nChild<int>(1);
    root->getChild(2)->addChild(newNode);
    newNode =  new nChild<int>(7);
    root->getChild(3)->addChild(newNode);
    newNode =  new nChild<int>(8);
    root->getChild(3)->addChild(newNode);
    newNode =  new nChild<int>(79);
    root->getChild(3)->addChild(newNode);

    return 0;
}
    

