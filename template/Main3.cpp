#include <iostream>
#include <vector>

#include "Item.h"

using namespace std;



int main(){

    const int Size = 10;
    Item<long> Values[Size];

    for(int i =0 ; i< Size ; ++i){
        Values[i].SetData(i*40);
    }

    Item<float> FloatItem;
    FloatItem..SetAverageFrom(Values, Size);

    // Item<int> i;
    // Item<double> d;
    // cout << i.GetData() <<endl;
    //cout << "average: " << GetAverage(c, 10) << endl;
}