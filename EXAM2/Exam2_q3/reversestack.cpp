#include "stack.h"
#include<iostream>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;

template <class Item>
void insert_at_bottom(stack<Item>& s1,Item x){ 
 
    if(s1.size() == 0){
		s1.push(x); 
	}
    else{   
        Item a = s1.top(); 
        s1.pop(); 
        insert_at_bottom(s1,x); 
        s1.push(a); 
    } 
} 
  
template <class Item>
void reverseStack(stack<Item>& s1) 
{ 
    if(s1.size() > 0){ 
    	Item x = s1.top(); 
        s1.pop(); 
        reverseStack(s1);
        insert_at_bottom(s1,x); 
    } 
} 
  

using namespace std;
int main(){
	stack<int> hello;
	hello.push(1);
	hello.push(2);
	hello.push(3);
	hello.push(4);
	hello.push(5);

	reverseStack(hello);
	while(!hello.empty()){
		cout<<hello.top()<<endl;
		hello.pop();
	}
	return 0;
}

