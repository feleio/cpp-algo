#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

template <class T>
class Heap{
public:
    Heap(): size(0), v(){}
    ~Heap(){}

    void insert(const T& t){
        int hole = v.size();
        v.push_back(t);
        while(t < v[(hole-1)/2] && hole>0){
            v[hole] = v[(hole-1)/2];
            hole = (hole - 1)/2;
        }
        v[hole] = t;
    }

    T deleteMin(){
        if(!empty()){
            T min = v[0];
            T t = v[v.size()-1];
            v.pop_back();
            int hole = 0;
            while((hole*2 + 1 < v.size() && t > v[hole*2 + 1]) || ( hole*2 + 2 < v.size() && t > v[hole*2 + 2]  )){
                if(hole*2 + 2 < v.size()){
                    if(v[hole*2 + 1] < v[hole*2 + 2]){
                        v[hole] = v[hole*2 + 1];
                        hole = hole*2 + 1;
                    } else {
                        v[hole] = v[hole*2 + 2];
                        hole = hole*2 + 2;
                    }
                } else {
                    v[hole] = v[hole*2 + 1];
                    hole = hole*2 + 1;
                }
            }
            v[hole] = t;
            return min;
        } 
        throw "empty";
    }

    bool empty() const{
        return v.empty();
    }

    void print() const{
        std::cout<<"p"<<std::endl;
        typename std::vector<T>::const_iterator it;
        for (it = v.begin(); it != v.end() ; ++it){
            std::cout<<*it<<std::endl;
        }
        std::cout<<std::endl;
    }

    void printSorted(){
        std::cout<<"s"<<std::endl;
        while(!empty()){
            std::cout << deleteMin() << std::endl;
        }
        std::cout<<std::endl;
    }


private:
    int size;
    std::vector<T> v;

};

#endif