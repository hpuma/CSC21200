## #include "hset.h" 
## AKA "Henry_set" :D
## B:5/13/19
## EDIT: 5/15/19
# *** hset NEEDS FURTHER TESTING IN MAIN.
# ***THIS README NEEDS AN UPDATE.
##
## A simple data structure to be used for the graphs
### Has been tested on test_hset.cpp
### TEMPLATE
#### template<class vType> [NAME]
#### hset<vertexType> [NAME]
##
### Intended use for graphs:
#### hset<char> [NAME]
##
### NOTE: COLOR  and WEIGHT use typedef INT.
#### COLOR = 0 --- WHITE
#### COLOR = 1 --- GREY
#### COLOR = 2 ---  BLACK 
##
##
# Everything is defined in the header file.
## typedef int CWTYPE // typedef for COLOR and WEIGHT.
### CONSTRUCTOR
#### hset(); // Sets garbage values to private member variables.
###
### CONSTRUCTOR WITH PARAMTERS
####  hset(vType v1, vType v2, CWTYPE inWeight = 0,CWTYPE firstColor = 0); // Setting predefined values.
###
### COPY CONSTRUCTOR
#### hset(const hset<vType>& source);
### 
### CONST FUNCTIONS
#### vType get_v1() const; // Gets vertex1.
#### vType get_v2() const; // Gets vertex2.
#### CWTYPE get_w() const; // Gets weight of edge.
#### CWTYPE print() const; // Prints vertically vertex1,vertex2,weight, and color.
### 
### MODIFICATION MEMBER FUNCTIONS
#### void set_v1(vType v1); // Sets vertex1.
#### void set_v2(vType v2); // Sets vertex2.
#### void set_w(CWTYPE inWeight); // Sets weight.
###  void set_w(CWTYP inColor); // Sets color.
### PRIVATE MEMBER VARIABLES
#### vType vertex1; // Beginning Vertex.
#### vType vertex2; // Ending Vertex.
#### CWTYPE weight; // Weight of edge.
#### CWTYPE color_v1; // color of vertex1;
#### CWTYPE color_v1; // color of vertex1;
