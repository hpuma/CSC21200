#include <iostream> 
#include "hw2.h"
using std::cout;
using std::cin;


int main(){
// Point thisPoint(1,2,3);
// Point thisPoint2(1,3,3);
// thisPoint.print();


//COPY CONSTRUCTOR TEST
// Point thisCopy(thisPoint); PASS
// thisCopy.print(); PASS

// set TEST
// thisPoint.setX(3); PASS
// thisPoint.setY(2); PASS
// thisPoint.setZ(1); PASS
// thisPoint.print(); PASS
// thisPoint.setXY(3,2); PASS
// thisPoint.setXYZ(3,2,1); PASS
// cout<<thisPoint.distance()<<"\n"; PASS

// point DISTANCE
// Point thisPoint2(3,2,1);
// cout<<thisPoint.distance(thisPoint2)<<"\n"; PASS

// point ORIGIN
// cout<<thisPoint.origin()<<"\n"; PASS

// point LINE
//  Point thisPoint(4,10,2);
//  Point lineTest(2,5,1);
//  cout<<thisPoint.line(lineTest)<<"\n";

// point add/subtract OPERATORS
// Point pointAdd = thisPoint + thisPoint2;
// pointAdd.print(); PASS
// Point pointSub = thisPoint2 - thisPoint;
// pointSub.print(); PASS

// point in/out OPERATORS
// cout<<"BEFORE: "<<thisPoint2;
// cin >> thisPoint2;
// cout<<"AFTER: "<< thisPoint2;


// point PLANE ... so far PASS
// size_t arSize = 3;
// Point pt1(1,2,3);
// Point pt2(1,4,7);
// Point pt3(4,5,3);
// Point testPoint(2,3,3);
// Point testAr[arSize] = {pt1,pt2,pt3};
// cout<<plane(testAr,testPoint)<<"\n";

// point SQUARE
// Point pt1(-2,0,0);
// Point pt2(0,2,0);
// Point pt3(0,-2,0);
// Point pt4(2,0,0);
// size_t size_sq = 4;
// Point sqtest[size_sq]  = {pt1,pt2,pt3,pt4};
// cout<<square(sqtest,size_sq)<<"\n"; PASS????

//point CENTROID
// Point pt1(4,2,4);
// Point pt2(5,-5,5);
// Point pt3(3,-2,6);
// size_t chkSize = 3;
// Point checkCenter[chkSize] = {pt1,pt2,pt3};
// Point pointAns;
// pointAns.print();
// pointAns  = centroid(checkCenter,chkSize);
// pointAns.print();



    return 0;
}