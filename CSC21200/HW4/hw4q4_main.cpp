#include<iostream> 
#include "hw4q4.h"
using namespace std;
int main(){
    Stack2Queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    cout<<myQueue.front()<<endl;
    myQueue.pop();
    cout<<myQueue.front()<<endl;
    return 0;
}