#include <iostream>
#include <vector>

#include "Item.h"
#include "Currency.h"

using namespace std;

int main(){

    const int Size = 10;
    Item<Currency> Values[Size];

    for(int i =0 ; i< Size ; ++i){
        Values[i].SetData(i*40 + 0.11);
    }
    Item<float> FloatItem;
    FloatItem.SetAverageFrom(Values, Size);

    //cout << FloatItem.GetData().dollar <<endl;
    //cout << FloatItem.GetData().cent <<endl;
    cout << FloatItem.GetData() <<endl;

    // Item<int> i;
    // Item<double> d;
    // cout << i.GetData() <<endl;
    //cout << "average: " << GetAverage(c, 10) << endl;
}