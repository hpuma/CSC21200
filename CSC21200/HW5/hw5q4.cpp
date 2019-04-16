#ifndef __BST_CPP__
#define __BST_CPP__
#include "hw5q4.h"


template <class Item>
BST<Item>::BST(){
	count = 0;
}
//FROM BOOK, PAGE 553
template <class Item>
void BST<Item>::insert(const Item& entry){
	if(tree.size() == 0 ){
		tree.createFirstNode(entry);
	}
	else{
		tree.shiftToRoot();
		btNode<Item>* curr = tree.getNode();
		btNode<Item>* newNode = new btNode<Item>(entry);
		bool done = false;

		while(!done){
			if(curr->getData() >= entry){
				if(curr->getLeft() == NULL){
					curr->setLeft(newNode);
					done = true;
				}
				else if(curr->getLeft() != NULL){
					curr = curr->getLeft();
				}
			}
			if(curr->getData() <= entry){
				if(curr->getRight() == NULL){
					curr->setRight(newNode);
					done = true;
				}
				else if(curr->getRight() != NULL){
					curr = curr->getRight();
				}
			}
			
		}
	}
	count++;
}

template <class Item>
void BST<Item>::remove(const Item& target){

}

template <class Item>
void BST<Item>::transplant(btNode<Item>*& u, btNode<Item>*& v){
	if(u->getParent() == NULL){
		tree.setRoot(v);
	}
	else if(u == u->getParent()->getLeft()){
		u->getParent()->setLeft(v);
	}
	else{
		u->getParent()->setRight(v);
	}
	if(v != NULL){
		v->setParent(u->getParent());
	}
}


template <class Item>
btNode<Item>* BST<Item>::minimum(){
	tree.shiftToRoot();
	btNode<Item>* curr = tree.getNode();

	while(!curr->isLeaf()){
		curr = curr->getLeft();
	}
	return curr;
}

template <class Item>
btNode<Item>* BST<Item>::maximum(){
	tree.shiftToRoot();
	btNode<Item>* curr = tree.getNode();

	while(!curr->isLeaf()){
		curr = curr->getRight();
	}
	return curr;
}
//BOOK PAGE 555
template <class Item>
btNode<Item>*  BST<Item>::search(const Item& target){
	tree.shiftToRoot();
	btNode<Item>* curr = tree.getNode();
	while(!curr->isLeaf()){
		if((curr != NULL) && (curr->getData() == target)){
			return (curr);
		}
		if(target < curr->getData()){
			curr = curr->getLeft();
		}
		else{
			curr = curr->getRight();
		}
	}
	return NULL;
}


#endif