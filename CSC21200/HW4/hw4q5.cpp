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
	if(!(q2.empty())){
		q1.push(q2.front());
		q2.pop();
		q2.push(entry);
		used = q1.size()+ q2.size();
	}
	else{
		q2.push(entry);
		used = q1.size() + q2.size();
	}
}

template <class Item>
void Queue2Stack<Item>::pop(){
	if(!(q2.empty())){
		q2.pop();
		used--;
		size_t tempSize = q1.size();
		for(size_t i = 0 ;  i < tempSize ; i++ ){
			q2.push(q1.front());
			q1.pop();
		}
		size_t secondStack  = q2.size() - 1;
		for(size_t j = 0 ; j < secondStack; j++){
			q1.push(q2.front());
			q2.pop();
		}
	}
			
}

template <class Item>
size_t Queue2Stack<Item>::size() const{
	return used;
}

template <class Item>
bool Queue2Stack<Item>::empty() const{
	return ((q1.empty()) && (q2.empty()));
}

template <class Item>
Item Queue2Stack<Item>::top() const{
	return q2.front();
}
#endif

