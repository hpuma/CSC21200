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
	if(tree.size() == 0 ){// When the tree is emptry.
		tree.createFirstNode(entry); // The tree adds the entry as its root node.
	}
	else{
		tree.shiftToRoot(); // Move the tree pointer to the root.
		bool done = false; // Boolean determining if the node has been inserted.
		while(!done){ // While the node has not been inserted.

			if(tree.retrieve() >= entry){  // If entry is less than the current node.
				if(!tree.hasLeft()){ // If the left node is empty.
					tree.addLeft(entry); // Add the new node with the entry.
					done = true;	// Node has been added .. done = true.
				}
				else if(tree.hasLeft()){ //If there is a left node.
					tree.shiftLeft();	// Keep going left.
				}
			}

			if(tree.retrieve() <= entry){ // If entry is greater than the current node.
				if(!tree.hasRight()){ // If the right node is empty.
					tree.addRight(entry); // Add the newNode.
					done = true;	// Node has been added, set done = true.
				}
				else if(tree.hasRight()){ // If there is a right node already.
					tree.shiftRight(); // Keep going left.
				}
			}
		}
	}
	count++; // Node will always be added
}
// On Bottom of page 555
template <class Item>
void BST<Item>::remove(const Item& target){
	tree.shiftToRoot();
	if(tree.retrieve() == NULL){
		return;
	}
	
	if(tree.retrieve() > target){
		tree.shiftLeft();
		remove(target);
	}
	if(tree.retrieve() < target){
		tree.shiftRight();
		remove(target);
	}

	if(tree.retrieve() == target){
		if(!tree.hasLeft()){
			transplant(tree.getNode(),tree.getRight());
			delete tree.getNode();
		}
		else{
			if(tree.getRight() == NULL){
				tree.setRoot(tree.getLeft());
				delete tree.getNode();
			}
			else if(tree.getRight() != NULL){
				
				while(!(!tree.hasLeft() && !tree.hasRight())){
					tree.shiftRight();
				}
				delete tree.getNode();
			}
		}
	}
}
//TEST SCRIPT REEEEEEEEEEEEEEEEEEEe
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
	while(tree.hasLeft()){
		tree.shiftLeft();
	}
	return tree.getNode();
}

template <class Item>
btNode<Item>* BST<Item>::maximum(){
	tree.shiftToRoot();
	while(tree.hasRight()){
		tree.shiftRight();
	}
	return tree.getNode();
}
//BOOK PAGE 555
template <class Item>
btNode<Item>*  BST<Item>::search(const Item& target){
	tree.shiftToRoot();
	while(!(!tree.hasLeft() && !tree.hasRight())){
		if((tree.getNode() != NULL) && (tree.retrieve() == target)){
			return tree.getNode();
		}
		if(target < tree.retrieve()){
			tree.shiftLeft();
		}
		else{
			tree.shiftRight();
		}
	}
	return NULL;
}
#endif