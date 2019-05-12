// FILE: stack.h
// TEMPLATE CLASS PROVIDED: stack<Item>
//
// TEMPLATE PARAMETER, TYPEDEFS and MEMBER CONSTANTS for the stack<Item> class:
//   The template parameter, Item, is the data type of the items in the stack,
//   also defined as stack<Item>::value_type. It may be any of the C++ built-in
//   types (int, char, etc.), or a class with a default constructor, a copy
//   constructor, and an assignment operator. The definition
//   stack<Item>::size_type is the data type of any variable that keeps track of
//   how many items are in a stack. The static const CAPACITY is the
//   maximum capacity of a stack for this first stack implementation.
// NOTE:
//   Many compilers require the use of the new keyword typename before using
//   the expressions stack<Item>::value_type and stack<Item>::size_type.
//   Otherwise the compiler doesn't have enough information to realize that it
//   is the name of a data type.
//
// CONSTRUCTOR for the stack<Item> template class:
//   stack( )
//     Postcondition: The stack has been initialized as an empty stack.
//
// MODIFICATION MEMBER FUNCTIONS for the stack<Item> class:
//   void push(const Item& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been pushed onto the stack.
//
//   void pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The top item of the stack has been removed.
//
// CONSTANT MEMBER FUNCTIONS for the stack<Item> class:
//   bool empty( ) const
//     Postcondition: Return value is true if the stack is empty.
//
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the stack.
//
//   Item top( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is the top item of the stack (but the
//     stack is unchanged. This differs slightly from the STL stack (where
//     the top function returns a reference to the item on top of the stack).
//
//  VALUE SEMANTICS for the stack<Item> class:
//     Assignments and the copy constructor may be used with stack<Item> 
//     objects.

#ifndef __STACK_H__
#define __STACK_H__
#include <cstdlib> // Provides size_t
#include <cassert> // Provides assert

template <class Item>
class stack
{
public:
    // TYPEDEFS AND MEMBER CONSTANT -- See Appendix E if this fails to compile.
    typedef std::size_t size_type;
    typedef Item value_type;
    static const size_type CAPACITY = 30;
    // CONSTRUCTOR
    stack( ) { used = 0; }
    // MODIFICATION MEMBER FUNCTIONS
    void push(const Item& entry);
    void pop( );
    // CONSTANT MEMBER FUNCTIONS
    bool empty( ) const { return (used == 0); }
    size_type size( ) const { return used; }
    Item top( ) const;
private:
    Item data[CAPACITY];        // Partially filled array 
    size_type used;             // How much of array is being used
};

template <class Item>
void stack<Item>::push(const Item& entry)
// Library facilities used: cassert
{
    assert(size( ) < CAPACITY);
    data[used] = entry;
    ++used;
}

template <class Item>
void stack<Item>::pop( )
// Library facilities used: cassert
{
    assert(!empty( ));
    --used;
}

template <class Item>
Item stack<Item>::top( ) const
// Library facilities used: cassert
{
    assert(!empty( ));
    return data[used-1];
}
#endif
