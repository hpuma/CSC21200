#include<iostream> 
#include "hw4q1.h"
using namespace std;

int main(){
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    cout<<myStack.top()<<endl;
    return 0;
}