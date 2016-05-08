#include <iostream>
#include <vector>

using namespace std;

class Currency{
public:
    int dollar;
    int cent;

public:
    Currency():dollar(0), cent(0){}
    Currency(int d, int c){
        dollar = d;
        cent = c;
    }

    operator double(){
        return dollar + cent/100;
    }

    double operator += (const Currency& other){
        dollar += other.dollar;
        cent += other.cent;
    }
};

template <class T>
double GetAverage(T ts[], int n){
    T sum = T();
    for (int i=0; i<n ; ++i){
        sum += ts[i];
    }
    return double(sum) / n;
}



int main(){
    Currency c[10];
    c[0].dollar = 100;

    cout << "average: " << GetAverage(c, 10) << endl;
}