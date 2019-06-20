
#ifndef __IVERTEX_H__
#define __IVERTEX_H__
#include <iostream> 
#include <vector> 
#include <iomanip>
#include <cassert>
using namespace std;

template <class Item>
class ivertex{
public:

// CONSTRUCTORS.
ivertex(){} // Does nothing because all vectors are empty.
ivertex(size_t numVertex){ // Given a value, set the color, vertexID, and vector<vector> the same dimension.
    for(size_t i = 0; i < numVertex; i++){
        vertexID.push_back('0');
        colorID.push_back(0);
        vector<Item> myVector;
        neighbors.push_back(myVector);
    }
}

ivertex(vector<Item> vertexID, vector<int> colorID, vector<vector<Item>> neighborList){
   if(vertexID.size() == colorID.size() && vertexID.size() == neighborList.size()){ // Make sure that the input vectors have the same dimension! Vertexes can't be missing a color, or there can't be more colors than there are vertex.
        this->vertexID = vertexID;
        this->colorID = colorID;
        this->neighbors = neighborList;
   }
   else{
       cout<<"ALL INPUT VECTORS MUST BE THE SAME SIZE!\n"; // Don't do nothing unless all vectors are the same dimension.
       return;
   }
}

// COPY CONSTRUCTOR  - - - - - - - - - - - 
ivertex(const ivertex<Item>& Source){
    if(Source.vertexID.size() == Source.colorID.size() && Source.vertexID.size() == Source.neighbors.size()){
    this->vertexID = Source.vertexID;
    this->colorID = Source.colorID;
    this->neighbors = Source.neighbors;
    }
}

// MODIFICATION MEMBER FUNCTIONS  - - - - - - - - - - - 
void setVertexList(vector<Item> vertexID){
    this.vertexID = vertexID;
    if(this->colorID.empty() && this->neighbors.empty()){ // In case other vectors haven't been set already.
        resizeRest(0,this->vertexID);
    }
}
void setColorList(vector<int> colorID){
    this->colorID = colorID;
    if(this->vertexID.empty() && this->neighbors.empty()){ // In case other vectors haven't been set up already.
        resizeRest(1,this->colorID);
    }
}
void setNeighborList(vector<vector<Item> > neighbors){
    this->neighbors = neighbors;
    if(this->vertexID.empty() && this->colorID.empty()){ // In case other vectors haven't been set up already.
        resizeRest(2,this->neighbors);
    }
}

// SETTING INDIVIDUAL VALUES PER VECTOR - - - - - - - - - - - 
void addVertex(Item inputVertex){
    this->vertexID.push_back(inputVertex);
}
void addColor(int inputColor){
    this->colorID.push_back(inputColor);
}
void addNeighborhood(){
    vector<Item> myVector;
    this->neighbors.push_back(myVector);
}
void balanceData(){ // This will only resize accoring to the number of vertex.
    if(this->vertexID.size() > this->colorID.size() && this->vertexID.size() > this->neighbors.size()){
        resizeRest(0,this->vertexID);
    }
}

// CHANGING INDIVIDUAL VALUES PER VECTOR - - - - - - - - - - - 
void changeVertex(size_t index, Item vertexID){
    if(this->vertexID.size()-1 > index){ // Make sure there is a vertex at the current index.
        this->vertexID[index] = vertexID;
    }
    else{
        cout<<"vertexID DOES NOT EXIST AT index!\n";
    }
}

void changeColor(size_t index, int colorID){
    if(this->colorID.size()-1 > index){ // Make sure there is a vertex at the current index.
        if(colorID >= 0 && colorID <= 2){
            this->colorID[index] = colorID;
        }
        else{
            cout<<"COLORID VALUE NOT VALID!\n";
        }
    }
    else{
        cout<<"colorID DOES NOT EXIST AT index!\n";
    }
}

void changeNeighbors(size_t index, vector<Item> neighbors){
    if(this->neighbors.size() - 1 > index){ // Make sure a neighbor vector exists at index!.
        this->neighbors[index] = neighbors;
    }
    else{
        cout<<"THERE ISN'T A VERTEX THAT EXISTS AT "<<index<<"\n";
    }
}

 // CONSTANT MEMBER FUNCTIONS - - - - - - - - - - - 

 // GETTING ENTIRE VECTOR VALUES.
vector<Item> getVertexList() const{
    return vertexID;
}
vector<int> getColorList() const {
    return colorID;
}

vector<vector<Item> > getNeighborsList() const{
    return neighbors;
}

// GETTING INDIVIDUAL VECTOR VALUES.
Item getVertex(size_t index){
    if(vertexID.size() - 1 >= index){
        return vertexID[index];
    }
    return Item();
}
int getColor(size_t index){
    if(colorID.size() - 1 >= index){
        return colorID[index];
    }
    return 0;
}
vector<Item> getNeighborhood(size_t index) const{
     if(neighbors.size() - 1 >= index){
        return neighbors[index];
    }
    return vector<Item>();
}

void printInfo() const{
    cout<<"PRINTING VERTEXID LIST\n";
    for(size_t i = 0; i < vertexID.size(); i++){
        cout<<vertexID[i]<<setw(2);
    }
    cout<<"\n";

    cout<<"PRINTING COLORID LIST\n";
    for(size_t j = 0; j < colorID.size(); j++){
        cout<<colorID[j]<<setw(2);
    }
    cout<<"\n";
    
    if(neighbors[0].empty()){
        cout<<"NEIGHBORS FOR EACH VERTEX EMPTY\n";
        cout<<"NUMBER OF NEIGHBORHOODS: "<<neighbors.size()<<"\n\n";
    }
    else{
        cout<<"PRINTING NEIGHBORS: "<<neighbors.size()<<setw(2)<<"\n";
        for (size_t k = 0; k < neighbors.size(); k++){
            cout<<vertexID[k]<<":"<<setw(2);
            for (size_t l = 0; l < neighbors[k].size(); l++){
                cout<<neighbors[k][l]<<setw(2);
            }
            cout<<"\n";
        }
    }
}

private:
vector<Item> vertexID; // Vector containing the set if vertex IDs;
vector<int> colorID; // Vector containing the current color of each vertex... they are linked colorwise.
vector<vector<Item>> neighbors; // 2D Vector containing vectors of 

// OPTION
// 0  - vertexID <-- this is the initVector ... resize the rest.
// 1  - colorID <-- this is the initVector ... resize the rest.
// 2  - neighbors <-- this is the initVector ... resize the rest.
void resizeRest(size_t OPTION, vector<Item> initVector){
    assert(OPTION >= 0 && OPTION <=2);
    size_t targetSize = initVector.size();
    if(OPTION == 0){ 
        while(this.colorID.size() != targetSize){
            this.colorID.push_back(0);
        }
        while(this.neighbors.size() != targetSize){
            vector<Item> myVector;
            this.neighbors.push_back(myVector);
        }
    }
    else if (OPTION == 1){
        while(this.vertexID.size() != targetSize){
            this.vertexID.push_back('0');
        }
        while(this.neighbors.size() != targetSize){
            vector<Item> myVector;
            this.neighbors.push_back(myVector);
        }
    }
    else if(OPTION == 2){
        while(this.colorID.size() != targetSize){
            this.colorID.push_back(0);
        }
        while(this.vertexID.size() != targetSize){
            this.vertexID.push_back('0');
        }
    }
}


};

#endif 