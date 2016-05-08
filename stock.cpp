#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main(){
    int k = 3;
    vector<int> prices;

    prices.push_back(12);
    prices.push_back(112);
    prices.push_back(96);
    prices.push_back(185);
    prices.push_back(0);
    prices.push_back(136);
    prices.push_back(136);
    prices.push_back(197);

    vector<int> buy(k, -100);
    vector<int> sell(k, 0);

    for (int j = 0 ; j <prices.size(); ++j){
        for (int i = 0; i < k; ++i) {
            buy[i] = max(buy[i], (i > 0 ? sell[i-1] : 0) - prices[j]);
            sell[i] = max(sell[i], buy[i] + prices[j]);
        }
        cout << "buy ";
        for (int i = 0; i < k; ++i) 
            cout << buy[i] << " " ;
        cout << endl;

        cout << "sell ";
        for (int i = 0; i < k; ++i) 
            cout << sell[i] << " " ;
        cout << endl;
    }
    return 0;
}