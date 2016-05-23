#include <iostream>

using namespace std;

class HeapSort{
public:
    static void heapify(int a[], int n){
        for(int i=(n-2)/2; i>=0; --i)
            maxHeapify(a, n, i);
    }

    static void maxHeapify(int a[], int n, int i){
        if(i >= n)
            return;

        // find largest
        int l = i*2 + 1;
        int r = i*2 + 2;
        int largest = i;
        if(l < n && a[l] > a[i]){
            largest = l;
        } else {
            largest = i;
        }

        if(r < n && a[r] > a[largest]){
            largest = r;
        }

        if(largest != i){
            //swap i with largest
            int temp = a[largest];
            a[largest] = a[i];
            a[i] = temp;
            maxHeapify(a, n, largest);
        }
    }

    static void popHeap(int a[], int n){
        if(n <= 1)
            return;
        // swap top with last
        int temp = a[n-1];
        a[n-1] = a[0];
        a[0] = temp;

        heapify(a, n-1);
    }
};

int main(){
    int a[] = {5,8,3,6,1,4,2};
    int n = sizeof(a) / sizeof(*a);
    HeapSort::heapify(a, n);

    // heap sort
    for(int i=n;i>=0;--i){
        HeapSort::popHeap(a, i);
    }

    for(int i=0;i<n;++i){
        cout << a[i] << " ";
    }
    cout <<endl;

}
