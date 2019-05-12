#ifndef __HIST_H__
#define __HIST_H__

#include <iostream>   // Provides ostream
#include <cstdlib>    // Provides size_t

class hist {
	public:
	hist() {count = 0;}
	hist(const int& entry) {data = entry; count = 1;}
	hist(const int& entry, const size_t& ct) {data = entry; count = ct;}

	int getData() const {return data;}
	size_t getCt() const {return count;}
	void increaseCt() {count++;}

	void operator=(const int& entry) {data = entry;count = 1;}
	bool operator==(const int& entry) {return data == entry;}
	hist operator++() {count++; return hist(data, count);}
	hist operator++(int) {hist h(data, count); count++; return h;}

	

	private:
	int data;
	size_t count;
};

std::ostream & operator << (std::ostream &out, const hist& c) 
{ 
    out << '(' << c.getData() << '/' << c.getCt() << ')'; 
    return out; 
} 

#endif