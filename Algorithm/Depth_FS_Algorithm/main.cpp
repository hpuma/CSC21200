#include <iostream>
#include "hw6q1.h"
#include "hset.h"
using namespace std;
// FUNCTIONS TO BUILD THE GRAPH

// makeGraph, creates an empty matrix with specified labels

// build: The graph to build on.
// beginLetter: Build graph from what letter? 
// endLetter: Build graph ending in what letter?
void makeGraph(graphM<char>& build, char beginLetter,char endLetter){
     for(int i = (int)beginLetter; i <= int(endLetter); i++){
        build.addVertex((char)i);
    }
}

// connect: Makes and edge that connects both ways.

// build: The graph to build on.
// v1: First vertex.
// v2: Ending vertex.
// weight: The weight of the edge.
void connect(graphM<char>& build, char v1, char v2, int weight){
    size_t source = 0;
    size_t target = 0;
    if((int)v1 >=65){
        source = ((int)v1)%65;
        target = ((int)v2)%65;
    }
    else if ((int)v1 >= 97){
        source = ((int)v1)%97;
        target = ((int)v2)%97;
    }
    build.addEdge(source,target,weight);
    build.addEdge(target,source,weight);
 
}





int main(){
graphM<char> matrix;
makeGraph(matrix,'A','F');

connect(matrix,'A','C',1);
connect(matrix,'A','B',1);

connect(matrix,'B','D',1);
connect(matrix,'B','E',1);

connect(matrix,'C','A',1);
connect(matrix,'C','E',1);

connect(matrix,'D','B',1);
connect(matrix,'D','E',1);
connect(matrix,'D','F',1);

connect(matrix,'E','C',1);
connect(matrix,'E','B',1);
connect(matrix,'E','D',1);
connect(matrix,'E','F',1);

connect(matrix,'F','D',1);
connect(matrix,'F','E',1);



matrix.print();

}