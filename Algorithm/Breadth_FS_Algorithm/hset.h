#ifndef __HSET_H__
#define __HSET_H__

#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

// NOTE: COLOR = 0; WHITE
// NOTE: COLOR = 1; GREY
// NOTE: COLOR = 2; BLACK 
template<class type1,class type2, class type3,class type4>
class hset{
    public:
    // CONSTRUCTOR
    hset(){
        vertex1 = type1();
        vertex2 = type2();
        weight  = type3();
        color  = 0;
    }
    hset(type1 v1, type2 v2, type3 inWeight,type4 firstColor){
    vertex1 = v1;
    vertex2 = v2;
    weight  = inWeight;
    color  = firstColor;
    }

    // COPY CONSTRUCTOR
    hset(const hset<type1,type2,type3>& source){
        vertex1 = source.vertex1;
        vertex2 = source.vertex2;
        weight = source.weight;
        color = source.color;
    }

    // CONST FUNCTIONS
    type1 get_v1() const{
        return vertex1;
    }

    type2 get_v2() const{
        return vertex2;
    }

    type3 get_w() const{
        return weight;
    }
    type4 get_c() const{
        return color;
    }

    // MODIFICATION MEMBER FUNCTIONS
    void set_v1(type1 v1 = type1()){
        vertex1 = v1;
    }
    void set_v2(type2 v2 = type2()){
        vertex2 = v2;
    }
    void set_w(type3 inWeight = type3()){
        weight = inWeight;
    }
    void set_c(type4 inColor){
        color = inColor;
    }
   
    // PRINT CONTENTS
    void print() const{
        cout<<vertex1<<"\n";
        cout<<vertex2<<"\n";
        cout<<weight<<"\n";
        cout<<color<<"\n";
    }
    private:
    type1 vertex1;
    type2 vertex2;
    type3 weight;
    type4 color;
};
#endif