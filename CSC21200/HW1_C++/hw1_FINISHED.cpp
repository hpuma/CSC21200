#include <iostream>
#include <cctype>
#include"hw1.h"

using namespace std;


//QUESTION 1 COMPLETE ... TEST ME 
void fizzBuzz(){
    for (int i = 0 ; i <= 30 ; i++){ // from the interval 0 -  30 
        if((i%3 == 0) && (i%5 != 0))cout<<i<<" Fizz\n"; // if the number is a multiple of 3 and not of 5
        if((i%5 == 0) && (i%3 != 0))cout<<i<<" Buzz\n"; // if the number is a multiple of 5 and not of 3
        if((i%3 == 0) && (i%5 == 0))cout<<i<<" FizzBuzz\n"; // if the number is a multiple of BOTH 3 and 5
        if((i%3 != 0) && (i%5 != 0))cout<<i<<" \n"; // if the number is NOT the multiple of either numbers
    }
}

//QUESTION 2 COMPLETE ... TEST ME 
void printLargeSmall(const int large, const int small) {
    cout << "The largest is " << large << endl;
    cout << "The smallest is " << small << endl;
}
void findLargeSmall(){
    int input = 0, small = 0, large = 0; // input: gets used for user input storage
    while(cin >> input){
        if(input < 99){ // as long as the input is not 99 keep track of the smallest and largest number
            if(input < small){
                small = input;
                if(large == 0) large = input;
            } 

            if(input > large){
                large = input;
                if(small == 0) small = input;
            }
        }
        if(input == 99){
            printLargeSmall(large,small); //if the input is 99, then display the smallest and larget number
            break;      
        }
    }
}

//QUESTION 3 COMPLETE ... needs to go through tests 

//function that prints the contents of an array

void printAr(const char ar[], const size_t size) {
    for(size_t i = 0; i < size; i++){
        cout << ar[i];
    }
    cout<<endl;
}
//QUESTION 3 ... TEST ME 
void fillArray(char ar[], size_t& size){
    size = 0;
    char input; // used to store user's input 
        while(cin >> input){
            if(size == MAXSIZE) break;
            if(!isalpha(input)) break; 
            ar[size] = input;
            size++; // inserts the user's input to the array 
            

        


            // checks for non alphabetical input
            
            // cout<<"\t"<<size<<"\tBEFORE\n\n";
            // printAr(ar,size);
            
          

            // cout<<"\t"<<size<<"\tAFTER\n\n";
            // printAr(ar,size); //DEBUGGING: custom function used to show what's in the array 
            
        }
}

//QUESTION 4 ... TEST ME
char highestOccurrences(const char ar[], const size_t size){
    // count: keeps track of the # of occurances 
    // maxCount: keeps track of the most occurance seen so far
    size_t count = 0, maxCount = 0;
    // mostOccur: stores the integer value of the char with most occurance ... need for math when
    // it also has the same ammount of Max count seen so far
    int mostOccur = 0;

    for(size_t i = 0 ; i < size ; i++){
        count = 0; // resets counter after each iteration
        for(size_t j = 0 ; j < size ; j++){
            if (ar[i] == ar[j]) count++; // keeps track of the ammount of occurances of a char
        }
        if(count == maxCount){ 
            // if the current char has the same as maxCount, then calculate the distance from a
            // if this char is closer to a, then it becomes the char with most occurance
            if(((int)ar[i]-97) < (mostOccur - 97)){
                mostOccur = (int)ar[i];
            }
        }     
        // if the current char has more occurances than ever seen before
        if(count > maxCount){
            mostOccur = (int)ar[i]; // current char becomes most seen char
            maxCount = count;       // stores the amount of occurances of this char
        }
    }   
    return (char)mostOccur;
}

//QUESTION 5 ... TEST ME 
void shiftAr(char ar[], const size_t size, const int numShift){
    string fString = "";
    if (numShift < 0){ // If statement that checks if we should shift LEFT or RIGHT
    // numAbs: finds the abs value of the desired shift
    // numVar: finds the amount of variables needed to print out in the beginning
    size_t numAbs = numShift * - 1, numVar = size + numShift;
    
    for (size_t i = 0; i < numVar ; i++) fString += ar[numAbs + i]; // print out from numAbs and onward ... do this numVar times
    for (size_t j = 0; j < numAbs ; j++) fString += ar[j]; // from element 0 to numAbs ... print out the element
    }
    else{ // when we need to shift to the right
    //secondHalf: calculates the starting point for the first part of output ... NEED THIS POINT FOR SHIFT
    size_t secondHalf = size - numShift; 
    for (size_t i = secondHalf ; i < size ; i++) fString += ar[i]; // the second half of the original array gets printed out first
    for (size_t j = 0 ; j < secondHalf ; j++) fString += ar[j];//prints from element 0 to secondHalf
    }
    for (size_t k = 0 ; k < size ; k++){
        ar[k] = fString[k];
    }

}



//QUESTION 6 TEST ME 
char* merge(const char ar1[], const size_t n1, const char ar2[], const size_t n2){
    size_t newSize = n1 + n2; // sets up the size for the new array
    char temp; // used store the temp for sorting 
    char* newArr = new char[newSize]; // creates new array which is the size of the sume of given arrays
    
    for (size_t i = 0 ; i < n1 ; i++) newArr[i] = ar1[i]; // adds the first array to the new array
    for (size_t j = 0 ; j < n2 ; j++) newArr[j + n1] = ar2[j];// adds the second array to the new array

//BUBBLE SORT on new array
    for (size_t k = 0 ; k < newSize - 1 ; k++){
        for (size_t l = k+1; l < newSize ; l++){
            if ((int)newArr[l] < (int)newArr[k]){
                temp = newArr[k];
                newArr[k] = newArr[l];
                newArr[l] = temp;
            }
        }
    }
  return newArr;
}



