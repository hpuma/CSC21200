#include <iostream> 
#include "hset.h"
using namespace std;


int main(){
    // hset works with pointers as well.
    hset<char,char,int>* dummy1 = new hset<char,char,int>('a','b',21);
    cout<<dummy1->get_v1()<<endl;
    cout<<dummy1->get_v2()<<endl;
    cout<<dummy1->get_w()<<endl;

    cout<<"Print Function\n";
    dummy1->print();

    dummy1->set_v1('c');
    dummy1->set_v2('d');
    dummy1->set_w(22);
    cout<<"Changed Values\n";
    dummy1->print();

    return 0; 
}