#include <iostream> 
#include "bagDynamic.h"
using namespace std;


int main(){
    bag myBag;
    cout<<myBag.isEmpty()<<endl;
    myBag.insert(5);
    cout<<myBag.isEmpty()<<endl;
    return 0;
}