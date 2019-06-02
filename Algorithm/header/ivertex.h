
#ifndef __IVERTEX_H__
#define __IVERTEX_H__
#include <iostream> 
#include <vector> 
#include <iterator>
using namespace std;
// NEEEEEEEEEDS TO BE REDONE !!!!!!
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
// COPY CONSTRUCTOR  - - - - - - - - - - - 
ivertex(const ivertex& source){
    vertex = source.vertex;
    color  = source.color;
    neighbors = source.neighbors;
}

// MODIFICATION MEMBER FUNCTIONS  - - - - - - - - - - - 
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
void set_neighbors(vector<Item> neighborhood){
    neighbors.clear();
    neighbors = neighborhood;
}

 // CONSTANT MEMBER FUNCTION - - - - - - - - - - - 
Item get_vertex() const{
    return vertex;
}

size_t get_color() const{
    return color;
}

vector<Item> get_neighbors() const{ 
    return neighbors;
}

Item neighborAt(size_t index){
    if(index <neighbors.size()){
         return neighbors[index];
    }
    return Item();
}

bool isNeighbor(Item vertex) const{
    for(size_t i = 0; i < neighbors.size(); i++){
        if(neighbors[i] == vertex){
            return true;
        }
    }
    return false;
}
void operator=(ivertex source){
    this.vertex = source.vertex;
    this.color = source.color;
    neighbors.clear();
    for(size_t i = 0; i < source.neighbors.size(); i++){
        neighbors.push_back(source.neighbors[i]);
    }
}

private:
Item vertex;
size_t color;
vector<Item> neighbors;

};






#endif 