#include <iostream>
#include "hw1.h"

using namespace std;
int main(int argc, char const *argv[]){
// Write your own to TEST
// QUESTION 1 AND 2
fizzBuzz();
findLargeSmall();

// // QUESTION 3 fillArray
char testArray[] ={'h','i'};
size_t size = 2;
fillArray(testArray,size);

// // QUESTION 4 highestOccurences 
char tArray2[] ={'b','b','b','b','f','f','f','f','d'};
size_t tArraySize = 9;
cout<<highestOccurrences(tArray2, tArraySize)<<endl;

// // QUESTION 5 ShiftAr
char testA[] = {'C','A','S','T','L','E'};
size_t testSize = 6;
int shift = 3;
printAr(testA,testSize);
shiftAr(testA, testSize,shift);
printAr(testA,testSize);

// //QUESTION 6 merge
size_t n1 = 4, n2 = 3;
char ar1[n1] = {'a', 'c', 'e', 'f'}; 
char ar2[n2] = {'b', 'd', 'g'};
cout<<merge(ar1,n1,ar2,n2)<<endl;
    return 0;
}
