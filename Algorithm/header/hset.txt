### #include "hset.h" 
### AKA "Henry_set" :D
#### B:5/13/19
##
### A simple data structure to be used for the graphs.
#### Has been tested on test_hset.cpp
### TEMPLATE
##### template<class vType> [NAME]
##### hset<vertexType> [NAME]
##
#### Intended use for graphs:
##### hset<char> [NAME]
##
#### NOTE: COLOR and WEIGHT use typedef SIZE_T.
##### Therefore WEIGHT >= 0 && COLOR >=0
##### COLOR = 0 --- WHITE
##### COLOR = 1 --- GREY
##### COLOR = 2 ---  BLACK 
##
##
### Everything is defined in the header file.
#### typedef int CWTYPE // typedef for COLOR and WEIGHT.
#### CONSTRUCTOR
##### hset(); // Sets garbage values to private member variables.
##
#### CONSTRUCTOR WITH PARAMTERS
#####  hset(vType v1, vType v2,CWTYPE vertex1_color = 0, CWTYPE vertex2_color = 0, CWTYPE inWeight = 0); // Setting predefined values.
##
#### COPY CONSTRUCTOR
##### hset(const hset<vType>& source);
##
#### MODIFICATION MEMBER FUNCTIONS
##### void set_w(CWTYPE inWeight); // Sets the edge weight.
##### void set_v1(vType v1); // Sets vertex1.
##### void set_v2(vType v2); // Sets vertex2.
##### set_v1_color(CWTYPE inColor); // Set the color of vertex 1.
##### set_v2_color(CWTYPE inColor); // Set the color of vertex 2.
##
#### CONSTANT MEMBER FUNCTIONS
##### CWTYPE get_w() const; // Returns weight of edge.
##### vType get_v1() const; // Returns vertex 1.
##### vType get_v2() const; // Returns vertex 2.
##### CWTYPE get_color_v1() const; // Returns the color value of vertex 1.
##### CWTYPE get_color_v2() const; // Returns the color of vertex 2.
##### CWTYPE print() const; // Prints vertically weight vertex1, vertex1 color, vertex2, and vertex2 color.
##
#### PRIVATE MEMBER VARIABLES
##### vType vertex1; // The vertex 1 value.
##### vType vertex2; // The vertex 2 value.
##### tring colors[3] = {"WHITE","GREY","BLACK"}; // Array holding the colors.
##### CWTYPE color_v1;  // Array holding vertex 1 color value.
##### CWTYPE color_v2;  // Array holding vertex 2 color values.
##### CWTYPE edgeWeight; // The wieght of the edge between vertex 1 and vertex 2.
