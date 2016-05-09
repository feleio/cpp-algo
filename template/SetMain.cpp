#include <iostream>

#include <set>

int main(){
	std::set<int> s;
	s.insert(112);
	s.insert(12);
	s.insert(12);
	s.insert(17);
	s.insert(12);
	
	std::cout << "size " << s.size() << std::endl;
	
	std::set<int>::const_iterator itr = s.begin();
	for(;itr!=s.end();++itr){
		std::cout << "set element " << *itr << std::endl;
	}
}