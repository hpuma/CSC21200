# #include "hset.h" 
# AKA "Henry_set" B:5/13/19
## Has been tested on test_hset.cpp
# A simple data structure to be used for the graphM
###
### template<class type1, class type2, class type3>
###
# Intended use for graphs:
### hset<char,char,int> [NAME]
### hset<vertex1,vertex2,edgeWeight>
###
# Everything is defined in the header file.
### CONSTRUCTOR
#### hset(); // Sets garbage values to private member variables.
###
### CONSTRUCTOR WITH PARAMTERS
#### hset(type1 v1, type2 v2, type3 inWeight); // Setting predefined values.
###
### COPY CONSTRUCTOR
#### hset(const hset<type1,type2,type3>& source);
### 
### CONST FUNCTIONS
#### type1 get_v1() const;
#### type2 get_v2() const;
#### type3 get_w() const;
#### void print() const; // Prints vartically vertex1,vertex2,weight.
### 
### MODIFICATION MEMBER FUNCTIONS
#### void set_v1(type1 v1); // Sets vertex1.
#### void set_v2(type2 v2); // Sets vertex2.
#### void set_w(type3 inWeight); // Sets weight.
###
### PRIVATE MEMBER VARIABLES
#### type1 vertex1;
#### type2 vertex2;
#### type3 vertex3;
