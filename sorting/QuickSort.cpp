#include <iostream>

using namespace std;

class QuickSort{
public:
    static void quickSort(int a[], int start, int end){
        if(end - start <= 1)
            return;

        int r = end - 1; // pivot
        int p = start;
        int q = start;

        for(int j=start; j<end-1; ++j){
            if(a[j] <= a[r]){
                //swap with q
                int tmp = a[q];
                a[q] = a[j];
                a[j] = tmp;
                ++q;
            }
        }

        int tmp = a[q];
        a[q] = a[end-1];
        a[end-1] = tmp;

        quickSort(a, start, q);
        quickSort(a, q+1, end);
    }
};

int main(){
    int a[] = {14,33,27,10,35,19,42,44};
    int n = sizeof(a)/sizeof(*a);
    QuickSort::quickSort(a, 0, n);
    for(int i =0; i<n;++i){
        cout << a[i] << " " <<endl;
    }
}
