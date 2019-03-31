#include <iostream>
#include "hw4q5.h"
using namespace std;


int main(){
Queue2Stack<int>test;
test.push(1);
test.push(2);
test.push(3);
test.push(4);
test.pop();
cout<<test.top()<<endl;
cout<<test.size()<<endl;
cout<<test.empty()<<endl;


    return 0;
}