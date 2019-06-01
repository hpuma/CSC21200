#include <iostream> 
#include <vector>
#include "hset.h"
#include "ivertex.h"
using namespace std;


int main(){
    // hset works with well with pointers.
    // hset<char>* dummy1 = new hset<char>();
    // cout<<"BEFORE\n\n";
    // dummy1->printData();
    // dummy1->set_v1('a');
    // dummy1->set_v1_color(3);
    // dummy1->set_v2('b');
    // dummy1->set_v2_color(2);
    // dummy1->set_w(22);
    //  cout<<"AFTER\n\n";
    // dummy1->printData();
    // cout<<"TEST_GET\n\n";
    // cout<<dummy1->get_w()<<'\n';
    // cout<<dummy1->get_v1()<<'\n';
    // cout<<dummy1->get_v2()<<'\n';
    // cout<<dummy1->get_color_v1()<<'\n';
    // cout<<dummy1->get_color_v2()<<'\n';

    ivertex<char> myVertex;
    myVertex.set_color(1);
    cout<<myVertex.get_color()<<endl;
    myVertex.set_vertex('c');
    cout<<myVertex.get_vertex()<<endl;
    vector<char> neigh = {'s','d','f','a'};
    myVertex.set_neighbors(neigh);
    



    
    return 0; 
}