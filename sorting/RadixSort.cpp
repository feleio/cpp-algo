#include <iostream>

#include <vector>
#include <list>
#include <math.h>

using namespace std;

class RadixSort{
public:
    static void radixSort(int a[], int n){
        for (int k=0;k<3;++k){
            list<int> map[10];
            for(int i=0;i<n;++i){
                map[int(a[i]/pow(10,k) )% 10].push_back(a[i]);
            }

            int idx = 0;
            for(int i=0;i<10;++i){
                list<int>::const_iterator itr = map[i].begin();
                for(;itr != map[i].end();++itr){
                    a[idx] = *itr;
                    ++idx;
                }
            } 
        }
    }
};

int main(){
    int a[] = {114,353,827,170,999,353,698,0};

    int n = sizeof(a)/sizeof(*a);

    RadixSort::radixSort(a, n);

    for(int i=0;i<n;++i)
        cout << a[i] << " ";

    cout << endl;


}
