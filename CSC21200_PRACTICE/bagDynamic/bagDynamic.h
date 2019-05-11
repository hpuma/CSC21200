#include<cstdlib>

class bag{

public: 
typedef int bagdt;
bag();
bag(size_t initCapacity);

bag(const bagdt& source);


~bag(){
    delete []data;
}





size_t getCapacity() const;
size_t getSize()const;



private:
int *data;
size_t size;
size_t capacity = 20;
};
