#include <iostream>
#include "Heap.h"
#include <stdlib.h>
#include <time.h>

void randomCall(Heap<int>& h){
    const int actionCount = 2;
    const int maxData = 100000;

    int action = rand()%actionCount;
    int data = rand()%maxData;
    switch(action){
    case 0:
        h.insert(data);
        std::cout << "h.insert(" << data <<")";
        break;
    case 1:
        if(!h.empty())
            h.deleteMin();
        std::cout << "h.deleteMin()";
        break;
    default:
        break;
    }
    std::cout <<std::endl;
}


int main(){
    long seed = time(NULL);
    //long seed = 1462643104;
    std::cout << "seed " << seed << std::endl;
    srand(seed);

    Heap<int> h;
    //srand()
    for(int i=0;i<100;++i){
        for(int j=0;j<100;++j){
            randomCall(h);
        }
        h.print();
        h.printSorted();
    }
    
    return 0;
}