#ifndef __BST_CPP__
#define __BST_CPP__
#include "hw5q4.h"


template <class Item>
BST<Item>::BST(){
	count = 0;
}

template <class Item>
void BST<Item>::insert(const Item& entry){
	if(tree.size() == 0 ){
		tree.createFirstNode(entry);
	}
	else{
		tree.shiftToRoot();
		btNode<Item>* newNode = new btNode<Item>(entry);
		btNode<Item>* prevNode;
		while(tree.getNode() != NULL){
			prevNode = tree.getNode();
			if(tree.retrieve() < entry){
				tree.shiftLeft();
			}
			else{
				tree.shiftRight();
			}	
		}
		newNode->setParent(prevNode);
		if(tree.getNode() == NULL){
			tree.createFirstNode(entry);
		}
		else if(entry < prevNode->getData()){
			prevNode->setLeft(newNode);
		}
		else{
			prevNode->setRight(newNode);
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
return NULL;
}

template <class Item>
btNode<Item>* BST<Item>::maximum(){
return NULL;
}
template <class Item>
btNode<Item>*  BST<Item>::search(const Item& target){
	if((tree.getNode() != NULL) && (tree.retrieve() == target)){
		return (tree.getNode());
	}
	if(target < tree.retrieve()){
		tree.shiftLeft();
		return search(target);
	}
	else{
		tree.shiftRight();
		return search(target);
	}
}


#endif