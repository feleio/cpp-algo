#include <iostream>

using namespace std;

void bubbleSort(int* a, int n){
    for(int i=n-2;i>=0;--i){
        for(int j=0;j<=i;++j){
            if(a[j] > a[j+1]){
                //swap
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(){
    int a[] = {5,3,6,7,3,21,1};
    int n = sizeof(a)/sizeof(*a);

    for (int i=0;i<n;++i){
        cout << a[i] << " ";
    }
    cout << endl;

    bubbleSort(a, n);

    for (int i=0;i<n;++i){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}