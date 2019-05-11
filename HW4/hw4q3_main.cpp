#include<iostream>
#include "hw4q3.h"
using namespace std;

int main(){
    PriorityQueue<int> test;
    test.push(3);
    test.push(2);
    test.push(1);


    cout<<test.front()<<endl;

    test.pop();
    cout<<test.front()<<endl;
    test.pop();
    cout<<test.front()<<endl;
    
    test.push(1);
    cout <<test.front()<<endl;

    test.push(2);
    cout <<test.front()<<endl;


    return 0;
}