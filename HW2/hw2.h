#ifndef __HW2_H__
#define __HW2_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 2 header file

// Try not to change this file

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class Point {
private:
	double x, y, z;
public:
	// Constructors
	Point();
	Point(double inX, double inY, double inZ = 0);
	Point(const Point& inPt);

	// Get Functions
	double getX() const;
	double getY() const;
	double getZ() const;

	// Set Functions
	void setX(double inX);
	void setY(double inY);
	void setZ(double inZ);
	void setXY(double inX, double inY);
	void setXYZ(double inX, double inY, double inZ);

	// Member Functions
	void print();
	double distance();
	double distance(const Point& pt2) const;
	bool origin();
	bool line(Point pt2);
	Point cross(Point pt2);

	// Friend functions
	friend istream& operator>>(istream& ins, Point& target);
	friend ostream& operator<<(ostream& outs, const Point& source);
};

// Overloading Functions
Point operator+(const Point& pt1, const Point& pt2);
Point operator-(const Point& pt1, const Point& pt2);

// Non-Member Functions
bool plane(const Point pts[], const Point& target);
bool square(const Point pts[], const size_t size);
Point centroid(const Point pts[], const size_t size);

// Following line is the end of the marco guard
#endif