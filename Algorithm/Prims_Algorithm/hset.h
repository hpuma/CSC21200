#ifndef __HSET_H__
#define __HSET_H__

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include <sstream>

using namespace std;

template<class vType>
class hset{
public:
typedef size_t CWTYPE;

// CONSTRUCTORS
hset(){
    vertex1 = vType();
    vertex2 = vType();
    color_v1 = 0;
    color_v2 = 0;
    edgeWeight  = 0;
}
hset(vType v1, vType v2,CWTYPE vertex1_color = 0, CWTYPE vertex2_color = 0, CWTYPE inWeight = 0){
    if((vertex1_color > 2) || (vertex2_color > 2)){  
      cout<<"BOTH COLOR VALUES MUST BE VALID.\n";
      if(vertex1_color > 2){cout<<vertex1_color<<" IS NOT A VALID COLOR VALUE.\n";}
      if(vertex2_color > 2){cout<<vertex2_color<<" IS NOT A VALID COLOR VALUE.\n";}
      return;
    }
    vertex1 = v1;
    vertex2 = v2;
    color_v1 = vertex1_color;
    color_v2 = vertex2_color;
    edgeWeight = inWeight;
} 

// COPY CONSTRUCTOR
hset(const hset<vType>& source){
    edgeWeight = source.weight;
    vertex1 = source.vertex1;
    vertex2 = source.vertex2;
    color_v1 = source.color_v1;
    color_v2 = source.color_v2;
}

// MODIFICATION MEMBER FUNCTIONS.
void set_w(CWTYPE inWeight){
    edgeWeight = inWeight;
}
void set_v1(vType v1){
    vertex1 = v1;
}
void set_v2(vType v2){
    vertex2 = v2;
}
void set_v1_color(CWTYPE inColor){
    if(inColor > 2){
        cout<<"\n\tERROR COLOR VALUE: "<<inColor<<" NOT VALID.\n";
        return;
    }
    color_v1 = inColor;
}
void set_v2_color(CWTYPE inColor){
    if(inColor > 2){
    cout<<"\n\tERROR COLOR VALUE: "<<inColor<<" NOT VALID.\n";
    return;
    }
    color_v2 = inColor;
}

// CONSTANT MEMBER FUNCTIONS.
CWTYPE get_w() const{
    return edgeWeight;
}
vType get_v1() const{
    return vertex1;
}
vType get_v2() const{
    return vertex2;
}
CWTYPE get_color_v1() const{
    return color_v1;
}
CWTYPE get_color_v2() const{
    return color_v2;
}

// PRINT PRIVATE VARIABLE CONTENTS
void printData() const{
    cout<<"EDGE WEIGHT  : "<<edgeWeight<<"\n";
    cout<<"VERTEX 1: "<<vertex1<<"\n";
    cout<<"COLOR   : "<<color_v1<<" : "<<colors[color_v1]<<"\n";
    cout<<"VERTEX 2: "<<vertex2<<"\n";
    cout<<"COLOR   : "<<color_v2<<" : "<<colors[color_v2]<<"\n";    
}

private:
vType vertex1;
vType vertex2;
string colors[3] = {"WHITE","GREY","BLACK"};
CWTYPE color_v1; 
CWTYPE color_v2; 
CWTYPE edgeWeight;
};
#endif