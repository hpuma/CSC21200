#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include "header/hw6q1.h"
#include "header/hset.h"
#include "header/ivertex.h"
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
    // When the input letters are upper case.
    if((int)v1 >=65){
        source = ((int)v1)%65;
        target = ((int)v2)%65;
    }
    // When the input letters are lower case.
    else if ((int)v1 >= 97){
        source = ((int)v1)%97;
        target = ((int)v2)%97;
    }
    // Adding edges both ways.
    build.addEdge(source,target,weight);
    build.addEdge(target,source,weight);
 
}

// COLOR 0 : WHITE
// COLOR 1 : GREY
// COLOR 2 : BLACK
vector<char> bfs(graphM<char> graph){
    ivertex<char> myVertex; // Vector containg the corresponding BFS walk.
    
    // Vectors containing information about vertex.
    vector<char> graphVertex; // Vertex id.
    vector<char> neighbors; // List of niehgbors to the current vertex.
    vector<int> color; // Color Values of each vertex in the graph vertex.

    queue<char> graphList; // Queue used for navigation.

    char vertex = graph[0]; // Variable used to store the current vertex we're at.
    graphList.push(vertex); 

    for(size_t i = 0; i < graph.numVertices(); i++){
        color.push_back(0); // Setting all the vertexes to white.
    }
    while(!graphList.empty()){
        vertex = graphList.front();
        graphList.pop();
        neighbors = graph.neighbors(graph.index(vertex));
        for(size_t j = 0; j < neighbors.size(); j++){
            if(color[graph.index(neighbors[j])] == 0){
                color[graph.index(neighbors[j])] = 1;
                graphList.push(neighbors[j]);
            }
        }
        color[graph.index(vertex)] = 2;
        graphVertex.push_back(vertex);
    }
    return graphVertex;
}


int main(){
graphM<char> matrix;
makeGraph(matrix,'A','F');

connect(matrix,'A','B',1);
connect(matrix,'A','D',1);
connect(matrix,'A','F',1);

connect(matrix,'B','A',1);
connect(matrix,'B','E',1);
connect(matrix,'B','C',1);

connect(matrix,'C','B',1);
connect(matrix,'C','F',1);
connect(matrix,'C','D',1);

connect(matrix,'D','C',1);
connect(matrix,'D','A',1);
connect(matrix,'D','E',1);

connect(matrix,'E','D',1);
connect(matrix,'E','B',1);
connect(matrix,'E','F',1);

connect(matrix,'F','E',1);
connect(matrix,'F','C',1);
connect(matrix,'F','A',1);
matrix.print();

// OUTPUT.
cout<<"Neighbor Walk BFS:\n";
vector<char> test = bfs(matrix);
for(vector<char>::iterator itr = test.begin(); itr != test.end(); itr++){
    cout<<(*itr)<<setw(2);
}

return 0;
}