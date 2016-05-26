#include <iostream>

using namespace std;

class Myclass {
public:
    Myclass() {
        cout << "constructor called\n" <<endl;
    };
    Myclass(const Myclass& other) {
        cout << "copy constructor called\n" <<endl;
    };
    Myclass& operator=(const Myclass& other) {
        cout << "copy assignment operator called\n" <<endl;
        return *this;
    };
};

void test(Myclass a){
    a;
}

int main(){
    Myclass b;
    Myclass a = b;
}
