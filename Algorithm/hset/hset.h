#ifndef __HSET_H__
#define __HSET_H__

#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;


template<class type1,class type2, class type3>
class hset{
    public:
    // CONSTRUCTOR
    hset(){
        vertex1 = type1();
        vertex2 = type2();
        weight  = type3();
    }
    // CONSTRUCTOR WITH PARAMTERS
    hset(type1 v1, type2 v2, type3 inWeight){
    vertex1 = v1;
    vertex2 = v2;
    weight  = inWeight;
    }

    // COPY CONSTRUCTOR
    hset(const hset<type1,type2,type3>& source){
        vertex1 = source.vertex1;
        vertex2 = source.vertex2;
        weight = source.weight;
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
   
    // PRINT CONTENTS
    void print() const{
        cout<<vertex1<<"\n";
        cout<<vertex2<<"\n";
        cout<<weight<<"\n";
    }
    private:
    type1 vertex1;
    type2 vertex2;
    type3 weight;
};
#endif