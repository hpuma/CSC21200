#include "hw2.h"
#include <iostream>
#include <cmath> 
using std::cout;
using std::istream;
using std::ios;

// Put your functions/prototype here

// #2 Default constructor ... Sets all coordinate points to 0 if no arguments are passed. 
Point::Point(){ 
    x = 0; 
    y = 0;
    z = 0;
}

// #3 Default constructor with user input ... Sets points to parameters. If Z isn't given, then Z = 0.
Point::Point(double inX, double inY, double inZ){
    x = inX;
    y = inY;
    z = inZ;
}

// #4 Copy constructor 
Point::Point(const Point& inPt){
     x = inPt.getX(); // gets x coordinate for copy. 
     y = inPt.getY(); // gets y coordinate for copy. 
     z = inPt.getZ(); // gets z coordinate for copy.
}

// #5 Set functions ... Sets the point x,y,z values based on the user's input.
void Point::setX(double inX){x = inX;} 
void Point::setY(double inY){y = inY;}  
void Point::setZ(double inZ){z = inZ;}
void Point::setXY(double inX, double inY){ // Only sets the (x,y) value.
    x = inX;
    y = inY;
}
void Point::setXYZ(double inX, double inY, double inZ){ // Only sets the (x,y,z) value ... also changes the point coordinates.
    x = inX;
    y = inY;
    z = inZ;
}

// #6 Get functions ... Gets the individual private members.
double Point::getX() const{return x;} 
double Point::getY() const{return y;}
double Point::getZ() const{return z;}

// #7 Print member function ... Prints the coordinate valuse of the Point.
void Point::print(){cout<<"("<<x<<", "<<y<<", "<<z<<")\n";}

// #8 Distance ... Calculates from a point to the origin ... Finds the magnitude of the point from the origin.
double Point::distance(){
    double calculate = pow(x,2) + pow(y,2) + pow(z,2); 
    double totalDistance  = sqrt(calculate);
return totalDistance;
}

// #9 Distance(param) ... Calculates the distance between points.
double Point::distance(const Point& pt2) const{
    double xDistance = pt2.getX() - x; // Individial X distance.
    double yDistance = pt2.getY() - y; // Individial Y distance.
    double zDistance = pt2.getZ() - z; // Individial Z distance.
    double exp_2 = pow(xDistance,2) + pow(yDistance,2) + pow(zDistance,2); // Squares each coordinate distance and adds them up.
    double totalDistance = sqrt(exp_2); // Takes the square root of all the distances. 
return totalDistance;
}

// #10 Origin
bool Point::origin(){
return ((x ==0) && (y==0) && (z==0)); // Checks if point is the origin (0,0,0)
}

Point Point::distanceVec(Point A, Point B){
    double x_dist = B.getX() - A.getX();
    double y_dist = B.getY() - A.getY();
    double z_dist = B.getZ() - A.getZ();
Point distVec(x_dist,y_dist,z_dist);
return distVec;
}

// #11 Line(param)
bool Point::line(Point pt2){ // origin == A, pt2 == B, pointCopy == C 
    bool isLine = false; // It isn't a line yet.
    Point origin(0,0,0); //defining the ORIGIN.
    if(((x==0) && (y==0 )&&(z==0)) || pt2.origin() ){return isLine;} // Checks to make sure neither points are the origin.
    else{
        Point pointCopy(x,y,z); //take copy points of POINT
        Point AB = distanceVec(origin,pt2);
        Point BC = distanceVec(pt2,pointCopy);
        Point crossVec = AB.cross(BC);
        if(crossVec.getX() == 0 && crossVec.getY() == 0 && crossVec.getZ()==0){isLine = true;}
    return isLine;
    }
}

// #12 Cross Product(param)
Point Point::cross(Point pt2){
    double xParam = (y * pt2.getZ()) - (z * pt2.getY()); // Deals with a2b3 - a3b2.
    double yParam = (z * pt2.getX()) - (x * pt2.getZ()); // Deals with a3b1 - a1b3.
    double zParam = (x * pt2.getY()) - (y * pt2.getX()); // eals with a1b2 - a2b1.
    Point crossProd(xParam,yParam,zParam); // Assigns each computations to its corresponding parameter.
return crossProd;
}

// #13 Overloading functions
Point operator+(const Point& pt1, const Point& pt2){
    double xSum = pt1.getX() + pt2.getX(); // Takes the sum of the X values.
    double ySum = pt1.getY() + pt2.getY(); // Takes the sum of the Y values.
    double zSum = pt1.getZ() + pt2.getZ(); // Takes the sum of the Z values.
    Point pointSum(xSum,ySum,zSum); // Assigns the sums of each parameter.
return pointSum;
}
Point operator-(const Point& pt1, const Point& pt2){
    double xDiff = pt1.getX() - pt2.getX();
    double yDiff = pt1.getY() - pt2.getY();
    double zDiff = pt1.getZ() - pt2.getZ();
    Point pointDiff(xDiff,yDiff,zDiff);
return pointDiff;
}

// #14 Friend functions
istream& operator>>(istream& ins, Point& target){
     ins>>target.x>>target.y>>target.z;
return ins;
 }

ostream& operator<<(ostream& outs, const Point& source){
    outs<<"("<<source.x<<", "<<source.y<<", "<<source.z<<")\n";
return outs;
 }

// #15 Non Member Functions PLANE
bool plane(const Point pts[], const Point& target){
    bool onPlane = false;
    Point u_Vec = pts[1] - pts[0];
    Point v_Vec = pts[2] - pts[0];
    Point cross_UV = u_Vec.cross(v_Vec);
        for (size_t i = 0 ; i < 3 ; i++){
            double checkX_pt = target.getX() - pts[i].getX();
            double checkY_pt = target.getY() - pts[i].getY();
            double checkZ_pt = target.getZ() - pts[i].getZ();
            if(!((cross_UV.getX() * checkX_pt) + (cross_UV.getY() * checkY_pt) + (cross_UV.getZ() * checkZ_pt))){
                onPlane = true;
            }
        }
return onPlane;
}

// #16 Non Member Functions SQUARE
// NEED TO MORE TEST !!!!!!!!!!
bool square(const Point pts[], const size_t size){
    bool isSquare = false;
    size_t firstLine = 0;
    size_t i;
    
    if(size >= 4){
        for (i = 0 ; i < size - 3; i++ ){
            double lineOne = pts[i].distance(pts[i+1]);
            double lineTwo = pts[i+1].distance(pts[i+2]);
            double lineThree = pts[i+2].distance(pts[i+3]);
            double lineFour = pts[i+3].distance(pts[i]);

            double diagOne = pts[i].distance(pts[i+2]) * sqrt(2);
            double diagTwo = pts[i+1].distance(pts[i+3]) * sqrt(2);

            if((lineOne == lineThree)&&(lineTwo == lineFour)){
                if(diagOne == diagTwo){isSquare = true;}
            }
        }

        for (size_t j = i ; j < 3 ; j++){

        }






        // double lineOne = pts[0].distance(pts[1]);
        // double lineTwo = pts[1].distance(pts[2]);
        // double lineThree = pts[2].distance(pts[3]);
        // double lineFour = pts[3].distance(pts[0]);

        // double diagOne = pts[0].distance(pts[2]) * sqrt(2);
        // double diagTwo = pts[1].distance(pts[3]) * sqrt(2);

        // if((lineOne == lineThree)&&(lineTwo == lineFour)){
        //     if(diagOne == diagTwo){isSquare = true;}
        //     }
        // return isSquare;
    }
    else{
        return isSquare;
        }
}

// #17 Non Member Functions CENTROID
// NEED TO MORE TEST !!!!!!!!!!
Point centroid(const Point pts[], const size_t size){
    Point origin(0,0,0);
    if (size == 0){ return origin;}
    double midX = 0, midY = 0, midZ = 0;
    for (size_t i = 0; i < size; i++){
        midX += pts[i].getX();
        midY += pts[i].getY();
        midZ += pts[i].getZ();
    }
    Point centroi(midX/size,midY/size,midZ/size);
return centroi;
}

    

 

