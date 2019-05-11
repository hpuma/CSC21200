#include"bag2.h"


bag::bag(){
    data = new bagdt[capacity];
    size = 0;
}

bag::bag(size_t initCapacity){
    data = new bagdt[initCapacity];
    capacity = initCapacity;
    size = 0;
}
size_t bag::getSize() const{
    return size;
}

size_t bag::getCapacity() const{
    return capacity;
}



bag::bag(const bagdt& source){
int *newData;
newData = new int[source.capacity];

}




