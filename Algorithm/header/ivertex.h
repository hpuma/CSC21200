
#ifndef __IVERTEX_H__
#define __IVERTEX_H__
#include <iostream> 
#include <vector> 
#include <iterator>
using namespace std;

template <class Item>
class ivertex{
public:

// CONSTRUCTORS.
ivertex(){
    color  = 0;
}
ivertex(Item vertexID, size_t colorID, vector<Item> neighborList){
    if(colorID > 2){
        cout<<"ERROR: colorID NOT CORRECT COLOR\n";
        return;      
    }
    vertex = vertexID;
    color  = colorID;
    neighbors = neighborList;
}
// COPY CONSTRUCTOR.
ivertex(const ivertex& source){
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
    for(size_t i = 0 ; i < neighborList.size(); i++){
        neighbors.push_back(neighborList[i]);
    }
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