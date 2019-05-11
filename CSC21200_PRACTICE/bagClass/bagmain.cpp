#include<iostream> 
#include"bag.h"
using namespace std;

int main(int argc,char*argv[]){
typedef int mytype;
    // Testing second constructor.
    size_t testSize = 10;
    mytype testAr[] = {1,2,2,2,2,2,3,4,5,6};
    bag test(testAr,testSize);

    // Testing getSize member variable.
    cout<<test.get_size()<<endl;

    // Testing the count function.
    size_t lookFor = 2;
    cout<<"The count of "<<lookFor<<" is "<<test.count(lookFor)<<endl;

    // Testing print function.
    test.print();

    // Testing erase.
    cout<<"I erased "<<test.erase(lookFor)<<"\t"<<lookFor<<"s!"<<endl;
    test.print();

    // Testing eraseOne.
    size_t eraseThis = 6;
    cout<<"I want to erase "<<eraseThis<<" Did I? "<<test.eraseOne(eraseThis)<<endl;
    test.print();

    // Testing insert.
    size_t luckyNum = 7;
    cout<<"Let me add a lucky number\n";
    test.insert(luckyNum);
    test.print();

    // Testing the += operator.
    size_t luckySize = 7;
    mytype luckyNums[] = {7,7,7,7,7,7,7};
    bag test2(luckyNums,luckySize);

    cout<<"\n\nLet's add more lucky numbers\nBEFORE:"<<endl;
    test.print();

    test+=test2;

    cout<<"After:\n";
    test.print();
    
    
    // Testing the [] operator.
    cout<<"Let me acces the first element"<<endl;
    cout<<test[0]<<endl;

    cout<<"\nSUCCESS!\n";
    return 0;
}