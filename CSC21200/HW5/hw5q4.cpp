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
		btNode<Item>* curr = tree.getNode(); // Set a pointer to the root node;
		btNode<Item>* newNode = new btNode<Item>(entry); // Create a node with entry.
		bool done = false; // Boolean determining if the node has been inserted.

		while(!done){ // While the node has not been inserted.

			if(curr->getData() >= entry){  // If entry is less than the current node.
				if(curr->getLeft() == NULL){ // If the left node is empty.
					curr->setLeft(newNode); // Add the new node with the entry.
					done = true;	// Node has been added .. done = true.
				}
				else if(curr->getLeft() != NULL){ //If there is a left node.
					curr = curr->getLeft();	// Keep going left.
				}
			}

			if(curr->getData() <= entry){ // If entry is greater than the current node.
				if(curr->getRight() == NULL){ // If the right node is empty.
					curr->setRight(newNode); // Add the newNode.
					done = true;	// Node has been added, set done = true.
				}
				else if(curr->getRight() != NULL){ // If there is a right node already.
					curr = curr->getRight(); // Keep going left.
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
		btNode<Item> deleteMe;
		if(!tree.hasLeft()){
			deleteMe = tree.getNode();
			transplant(tree.getNode(),tree.getRight());
			delete deleteMe;
		}
		else{
			if(tree.getRight() == NULL){
				deleteMe = tree.Node();
				tree.setRoot(tree.getLeft());
				delete deleteMe;
			}
			else if(tree.getRight() != NULL){
				btNode<Item>* curr = tree.getNode();
				while(!curr->isLeaf()){
					curr = curr->getRight();
				}
				delete curr;
			}
		}
	}

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