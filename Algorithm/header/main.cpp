#include <iostream> 
#include "hset.h"
using namespace std;


int main(){
    // hset works with pointers as well.
    hset<char>* dummy1 = new hset<char>();
    cout<<"BEFORE\n\n";
    dummy1->printData();
    dummy1->set_v1('a');
    dummy1->set_v1_color(3);
    dummy1->set_v2('b');
    dummy1->set_v2_color(2);
    dummy1->set_w(22);
     cout<<"AFTER\n\n";
    dummy1->printData();
    cout<<"TEST_GET\n\n";
    cout<<dummy1->get_w()<<'\n';
    cout<<dummy1->get_v1()<<'\n';
    cout<<dummy1->get_v2()<<'\n';
    cout<<dummy1->get_color_v1()<<'\n';
    cout<<dummy1->get_color_v2()<<'\n';

    
    return 0; 
}