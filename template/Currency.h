#ifndef CURRENCY_H
#define CURRENCY_H

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

    Currency(double d){
        dollar = d;
        cent = int(d*100 )% 100;
    }

    operator double(){
        return dollar + cent/100.0;
    }

    double operator += (const Currency& other){
        dollar += other.dollar;
        cent += other.cent;
        dollar += cent/100;
        cent = cent % 100;
    }

};

#endif