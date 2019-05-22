
#ifndef __IVERTEX_H__
#define __IVERTEX_H__
#include <iostream> 
#include <vector> 
#include <iterator>
using namespace std;

template <class Item>
class iVertex{
public:

// CONSTRUCTORS.
iVertex(){
    color  = 0;
}
iVertex(Item vertexID, size_t colorID, vector<Item> neighborList){
    if(colorID > 2){
        cout<<"ERROR: colorID NOT CORRECT COLOR\n";
        return;
    }
    vertex = vertexID;
    color  = colorID;
    neighbors = neighborList;
}
// COPY CONSTRUCTOR.
iVertex(const iVertex& source){
    vertex = source.vertex;
    color  = source.color;
    neighbors = source.neighbors;
}

// MODIFICATION MEMBER FUNCTIONS.
void set_vertex(Item vertexID){
    vertex = vertexID;
}
void set_color(size_t colorID){
    if(colorID > 2){
        cout<<"ERROR: colorID NOT CORRECT COLOR\n";
        return;
    }
    color = colorID;
}
void set_neighbors(vector<Item> neighborList){
    vector<Item>::iterator copyPoint = neighbors.begin();
    copy(neighborList.begin(),neighborList.end(),inserter(neighbors,copyPoint));
}

// CONSTANT MEMBER FUNCTIONS. 
Item get_vertex() const{
    return vertex;
}

size_t get_color() const{
    return color;
}

vector<Item> get_neighbors() const{
    return neighbors;
}

private:
Item vertex;
size_t color;
vector<Item> neighbors;

};

#endif 