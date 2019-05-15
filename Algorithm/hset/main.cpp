#include <iostream> 
#include "hset.h"
using namespace std;


int main(){
    // hset works with pointers as well.
    hset<char>* dummy1 = new hset<char>();
    dummy1->printData();
    return 0; 
}