#include <iostream> 
#include <vector>
#include "hset.h"
#include "ivertex.h"
using namespace std;
// TESTING HEADERS.

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


    // iVERTEX TEST1 - - - - - - - - - -

    // size_t num = 9;
    // ivertex<char> myVertex(num);
    // myVertex.printInfo();
    // myVertex.changeVertex(2,'A');
    // myVertex.changeColor(2,3);
    // myVertex.printInfo();

    // END TEST1 - - - - - - - - - - -
    
    // IVERTEX TEST2

    // ivertex<char> myVertex;
    // for(size_t i = 65; i < 71; i++){ // Making 9 iVertex.
    //     myVertex.addVertex((char)i);
    //     myVertex.addColor(1);
    //     myVertex.addNeighborhood();
    // }
    // myVertex.printInfo();

    // END TEST2 - - - - - - - - - - -

    // IVERTEX TEST3 
        vector<char> vertexList = {'A','B','C'};
        vector<int> vertexColor = {1,1,1};
        vector<vector<char> > neighbors = {{'E'},{'R'},{'D'}};
        ivertex<char> myVertex(vertexList,vertexColor,neighbors);
        myVertex.printInfo();
    // END TEST3


    return 0; 
}