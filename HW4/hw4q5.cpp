#include "hw4q5.h"
#ifndef __HW4Q4_CPP__
#define __HW4Q4_CPP__
//q2 holds the top of the stack ... 
template <class Item>
Queue2Stack<Item>::Queue2Stack(){
	used = 0;
}

template <class Item>
void Queue2Stack<Item>::push(const Item& entry){
	while(!q1.empty()){
		q2.push(q1.front());
		q1.pop();
	}
	q1.push(entry);
	while(!q2.empty()){
		q1.push(q2.front());
		q2.pop();
	}
	used++;
}
template <class Item>
void Queue2Stack<Item>::pop(){
	q1.pop();
	used--;			
}

template <class Item>
size_t Queue2Stack<Item>::size() const{
	return used;
}

template <class Item>
bool Queue2Stack<Item>::empty() const{
	return (q1.empty());
}

template <class Item>
Item Queue2Stack<Item>::top() const{
	return (q1.front());
}
#endif

