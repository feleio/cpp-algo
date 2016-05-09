#include <iostream>
#include <vector>

#include "Vector.h"
#include <string>

int main(){
	Vector<float> v;
	v.push_back(3.3);
	v.push_back(2.3);
	v.push_back(4.3);
	v.push_back(5.3);
	v.push_back(6.3);
	
	v[3] = 9.99;
	
	std::cout << "size " << v.size() << std::endl;
	std::cout << "capacity " << v.capacity() << std::endl;
	
	for(int i=0;i<v.size();++i){
		std::cout << i << " :" << v[i] << std::endl;
	}
	
	Vector<std::string> s;
	s.push_back("asdf1");
	s.push_back("asdf2");
	s.push_back("asdf3");
	s.push_back("asdf5");
	
	s[3] = std::string("sdf9999a");
	
	std::cout << "size " << s.size() << std::endl;
	std::cout << "capacity " << s.capacity() << std::endl;
	
	for(int i=0;i<s.size();++i){
		std::cout << i << " :" << s[i] << std::endl;
	}
	
	// Item<int> i;
    // Item<double> d;
    // cout << i.GetData() <<endl;
    //cout << "average: " << GetAverage(c, 10) << endl;
}