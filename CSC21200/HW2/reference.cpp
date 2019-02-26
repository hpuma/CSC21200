#include "hw2.h"

// Put your functions/prototype here

Point::Point(){//Default constructor;finished
	x=0;
	y=0;
	z=0;
}

Point::Point(double inX, double inY, double inZ){//constructor with param;finished
	x=inX;
	y=inY;
	z=inZ;
}

Point::Point(const Point& inPt){//copy constructor;finished
	x=inPt.x;
	y=inPt.y;
	z=inPt.z;
}

void Point::setX(double inX){//set member functions;finished
	x=inX;
}
void Point::setY(double inY){
	y=inY;
}
void Point::setZ(double inZ){
	z=inZ;
}
void Point::setXY(double inX, double inY){
	x=inX;
	y=inY;
}
void Point::setXYZ(double inX, double inY, double inZ){
	x=inX;
	y=inY;
	z=inZ;
}

double Point::getX() const{//get member functions;finished
	return x;
}
double Point::getY() const{
	return y;
}
double Point::getZ() const{
	return z;
}

void Point::print(){
	cout << "("<<x<<", "<<y<<", "<<z<<")\n";
}

double Point::distance(){//distance from origin;finished
	double a = x;
	double b = y;
	double c = z;
	double distSqrd = pow(a,2) + pow(b,2) + pow(c,2);
	return sqrt(distSqrd);
}

double Point::distance(const Point& pt2) const{//distance from another point;finished
	double a = pt2.getX() - x;
	double b = pt2.getY() - y;
	double c = pt2.getZ() - z;
	double distSqrd = pow(a,2) + pow(b,2) + pow(c,2);
	return sqrt(distSqrd);
}

bool Point::origin(){//boolean origin point;finished
	if(x==0&&y==0&&z==0)
		return true;
	return false;
}

bool Point::line(Point pt2){//boolean colinear 3 points;finished
	if((x==0&&y==0&&z==0)&&(x==pt2.getX()&&y==pt2.getY()&&z==pt2.getZ()))
		return false;
	if(x==0&&y==0&&z==0||pt2.getX()==0&&pt2.getY()==0&&pt2.getZ()==0)
		return true;
	/*if(pt2.getX()==0&&pt2.getY()==0&&pt2.getZ()==0)
		return true;*/
	if(x==pt2.getX()&&y==pt2.getY()&&z==pt2.getZ())
		return true;
	Point pt1(x,y,z);
	double distOriginPt1 = pt1.distance();
	double distPt1Pt2 = pt1.distance(pt2);
	double distOriginPt2 = pt2.distance();
	if(distPt1Pt2>distOriginPt2)
		if(distOriginPt1+distOriginPt2==distPt1Pt2)
			return true;
	if(distOriginPt1+distPt1Pt2==distOriginPt2)
		return true;
	return false;
}

Point Point::cross(Point pt2){//cross product between two points;finished
	double crossX=(y*pt2.getZ())-(z*pt2.getY());
	double crossY=(z*pt2.getX())-(x*pt2.getZ());
	double crossZ=(x*pt2.getY())-(y*pt2.getX());
	Point crossProd(crossX,crossY,crossZ);
	return crossProd;
}

Point operator+(const Point& pt1, const Point& pt2){//sum of two points in the xyz plane
    double sumX = pt1.getX() + pt2.getX();
    double sumY = pt1.getY() + pt2.getY();
    double sumZ = pt1.getZ() + pt2.getZ();
    Point sumPoint(sumX,sumY,sumZ);
	return sumPoint;
}
Point operator-(const Point& pt1, const Point& pt2){//difference between two points in the xyz plane;finished
    double diffX = pt1.getX() - pt2.getX();
    double diffY = pt1.getY() - pt2.getY();
    double diffZ = pt1.getZ() - pt2.getZ();
    Point diffPoint(diffX,diffY,diffZ);
	return diffPoint;
}

istream& operator>>(istream& ins, Point& target){//input operator;finished
    ins>>target.x>>target.y>>target.z;
	return ins;
 }

ostream& operator<<(ostream& outs, const Point& source){//output operator;finished
    outs<<"("<<source.x<<", "<<source.y<<", "<<source.z<<")\n";
	return outs;
 }

bool plane(const Point pts[], const Point& target){//plane check non member function;finished
    Point u=pts[1]-pts[0];
    Point v=pts[2]-pts[0];
    Point uvCross=u.cross(v);
        for(size_t i=0;i<3;i++){
            double XminusXnaught=target.getX()-pts[i].getX();
            double YminusYnaught=target.getY()-pts[i].getY();
            double ZminusZnaught=target.getZ()-pts[i].getZ();
            if(!((uvCross.getX()*XminusXnaught)+
            	 (uvCross.getY()*YminusYnaught)+
            	 (uvCross.getZ()*ZminusZnaught))){
                return true;
            }
        }
	return false;
}


bool square(const Point pts[], const size_t size){//not finished
	if(size<=3)
		return false;
	for(size_t i=0;i<size-3;i++){
		Point ar[3]={pts[i+1],pts[i+2],pts[i+3]};
		if(plane(ar,ar[i])){
			//logic for 4 points using array ar instead of array pts
			double lineOne = ar[0].distance(ar[1]);
        	double lineTwo = ar[1].distance(ar[2]);
        	double lineThree = ar[2].distance(ar[3]);
        	double lineFour = ar[3].distance(ar[0]);
			double diagOne = ar[0].distance(ar[2]) * sqrt(2);
        	double diagTwo = ar[1].distance(ar[3]) * sqrt(2);

        	if((lineOne == lineThree)&&(lineTwo == lineFour)){
            	if(diagOne == diagTwo)
            		return true;
            }
        }
    }
	/*for(size_t j=0;j<3;j++){
		Point ar[3]={pts[i+1],pts[i+2],pts[i+3]}
		if(plane(ar[],ar[i])){
			//logic for 4 points using array ar instead of array pts
			double lineOne = ar[0].distance(ar[1]);
        	double lineTwo = ar[1].distance(ar[2]);
        	double lineThree = ar[2].distance(ar[3]);
        	double lineFour = ar[3].distance(ar[0]);
			double diagOne = ar[0].distance(ar[2]) * sqrt(2);
        	double diagTwo = ar[1].distance(ar[3]) * sqrt(2);

        	if((lineOne == lineThree)&&(lineTwo == lineFour)){
            	if(diagOne == diagTwo)
            		return true;
        	}
		}
	}
    if(size == 4){
        double lineOne = pts[0].distance(pts[1]);
        double lineTwo = pts[1].distance(pts[2]);
        double lineThree = pts[2].distance(pts[3]);
        double lineFour = pts[3].distance(pts[0]);

        double diagOne = pts[0].distance(pts[2]) * sqrt(2);
        double diagTwo = pts[1].distance(pts[3]) * sqrt(2);

        if((lineOne == lineThree)&&(lineTwo == lineFour)){
            if(diagOne == diagTwo)
            	return true;
        }
    }*/
    return false;
}

Point centroid(const Point pts[], const size_t size){//not finished
	Point origin(0,0,0);
	if(size==0)
		return origin;
    double midpointX=0,midpointY=0,midpointZ=0;
    for(size_t i=0;i<size;i++){
        midpointX += pts[i].getX();
        midpointY += pts[i].getY();
        midpointZ += pts[i].getZ();
    }
    Point centroi(midpointX/size,midpointY/size,midpointZ/size);
	return centroi;
}