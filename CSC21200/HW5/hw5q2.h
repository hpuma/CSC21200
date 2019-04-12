// FILE: btClass.h
// TEMPLATE CLASS PROVIDED: binaryTree<Item> (a binary tree where each node has
//   an item) The template parameter, Item, is the data type of the items in the
//   tree's nodes. It may be any of the C++ built-in types (int, char, etc.),
//   or a class with a default constructor, a copy constructor and an assignment
//   operator.
//
// NOTE: Each non-empty tree always has a "current node."  The location of
// the current node is controlled by three member functions: shiftUp,
// shiftToRoot, shiftLeft, and shiftRight.
//
// CONSTRUCTOR for the binaryTree<Item> template class:
//   binaryTree( )  
//     Postcondition: The binary tree has been initialized as an empty tree
//     (with no nodes).
//
// MODIFICATION MEMBER FUNCTIONS for the binaryTree<Item> template class:
//   void createFirstNode(const Item& entry)
//     Precondition: size( ) is zero.
//     Postcondition: The tree now has one node (a root node), containing the
//     specified entry. This new root node is the "current node."
//
//   void shiftToRoot( )
//     Precondition: size( ) > 0.
//     Postcondition: The "current node" is now the root of the tree.
//
//   void shiftUp( )
//     Precondition: hasParent( ) returns true.
//     Postcondition: The "current node" has been shifted up to the parent of
//     the old current node.
//
//   void shiftLeft( )
//     Precondition: hasLeft( ) returns true.
//     Postcondition: The "current node" been shifted down to the left child
//     of the original current node.
//
//   void shiftRight( )
//     Precondition: hasRight( ) returns true.
//     Postcondition: The "current node" been shifted down to the right child
//     of the original current node.
//
//   void change(const Item& new_entry)
//     Precondition: size( ) > 0.
//     Postcondition: The data at the "current node" has been changed to the
//     new entry.
//
//   void addLeft(const Item& entry)
//     Precondition: size( ) > 0, and hasLeft( ) returns false.
//     Postcondition: A left child has been added to the "current node,"
//     with the given entry.
//
//   void addRight(const Item& entry)
//     Precondition: size( ) > 0, and hasRight( ) returns false.
//     Postcondition: A right child has been added to the "current node,"
//     with the given entry.
//
//   void removeLeft( )
//     Precondition: size( ) > 0, hasLeft( ) returns true, and getLeft( )->isLeaf( ) return true.
//     Postcondition: A left child has been removed from the "current node."
//
//   void removeRight( )
//     Precondition: size( ) > 0, hasRight( ) returns true, and getRight( )->isLeaf( ) return true.
//     Postcondition: A right child has been removed from the "current node."
//
//   void setRoot(btNode<Item>* newRoot)
//     Precondition: size( ) > 0.
//     Postcondition: The root has been set to newRoot.
//
//   btNode<Item>* getNode( )
//     Precondition: size( ) > 0.
//     Postcondition: The return value is the btNode from the "current node."
//
// CONSTANT MEMBER FUNCTIONS for the binaryTree<Item> template class:
//   size_t size( ) const
//     Postcondition: The return value is the number of nodes in the tree.
//
//   Item retrieve( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is the data from the "current node."
//
//   bool hasParent( ) const
//     Postcondition: Returns true if size( ) > 0, and the "current node"
//     has a parent.
//
//   bool hasLeft( ) const
//     Postcondition: Returns true if size( ) > 0, and the "current node"
//     has a left child.
//
//   bool hasRight( ) const
//     Postcondition: Returns true if size( ) > 0, and the "current node"
//     has a right child.
//
// VALUE SEMANTICS for the binaryTree<Item> template class:
//   Assignments and the copy constructor may be used with binaryTree objects.
//
// DYNAMIC MEMORY USAGE by the binaryTree<Item> template class:
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc:
//   createFirstNode, addLeft, addRight, the copy constructor, and the 
//   assignment operator.

#ifndef __BT_CLASS_H__
#define __BT_CLASS_H__

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides size_t
#include "hw5q1.h"    // Provides btNode<Item> template class

using namespace std;

template <class Item>
class binaryTree
{
public:
    // CONSTRUCTORS and DESTRUCTOR
    binaryTree( );
    binaryTree(const binaryTree& source);
    ~binaryTree( );
    // MODIFICATION MEMBER FUNCTIONS
    void createFirstNode(const Item& entry);
    void shiftToRoot( );
    void shiftUp( );
    void shiftLeft( );
    void shiftRight( );
    void change(const Item& newEntry);
    void addLeft(const Item& entry);
    void addRight(const Item& entry);
    void removeLeft( );
    void removeRight( );
    void setRoot( btNode<Item>* newRoot );
    btNode<Item>* getNode( );
    // CONSTANT MEMBER FUNCTIONS
    size_t size( ) const;
    Item retrieve( ) const;
    bool hasParent( ) const;
    bool hasLeft( ) const;
    bool hasRight( ) const;    
private:
    btNode<Item>* root;
    btNode<Item>* curr;
    size_t count;
};

#include "hw5q2.cpp" 
#endif 