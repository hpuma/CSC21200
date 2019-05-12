#ifndef __STACKTOPRIORITY_H__
#define __STACKTOPRIORITY_H__
#include "stack.h"
#include <iostream>   // Provides ostream
#include <cstdlib>    // Provides size_t
template<class Item> 
class stacktopriority{
	public:
	stacktopriority();
	stacktopriority(const stacktopriority<Item>& source);

	void push(const Item& entry);
	void pop();
	size_t size() const;
	bool empty () const;
	Item front() const;

	private:
	stack<Item> s1;
	stack<item> s2;
	size_t used;
};

template<class Item>
stacktopriority<Item>::stacktopriority(){
		used = 0;
	}


template<class Item>
stacktopriority<Item>::stacktopriority(const stacktopriority<Item>& source){ // might get errors not sure 
	used = source.size();
	while(!source.empty()){
		s1.push(source.front())
		source.pop();
	}
}

template<class Item>
void push(const Item& entry){
	if(entry<s1.top()){
	Item temp = s1.top();
	s1.pop();
	s1.push(entry);
	s2.push(temp);
	used++;
	}
	else{
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(entry);
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
		used++;
	}
}

template<class Item>
void stacktopriority<Item>::pop(){
s1.pop();
used--;
}


template<class Item>
size_t stacktopriority<Item>::size() const{
	return used;
}

template<class Item>
bool stacktopriority<Item>::empty() const{
return (used == 0);
}

template<class Item>
Item stacktopriority<Item>::front() const{
	return (s1.top());
}





#endif