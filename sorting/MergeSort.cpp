#include <iostream>

using namespace std;

class MergeSort{
public:
    static void mergeSort(int a[], int start, int end){
        if(end- start <= 1)
            return;

        int m = (start + end)/2;
        mergeSort(a, start, m );
        mergeSort(a, m, end );

        //merge
        int l[end-start];
        //int* l = new int[end - start];
        int i=start;
        int j=m;
        int k=0;

        while(i < m && j < end){
            if(a[i] < a[j]){
                l[k] = a[i];
                ++k;
                ++i;
            } else {
                l[k] = a[j];
                ++k;
                ++j;
            }
        }

        while(i < m){
            l[k] = a[i];
            ++k;
            ++i;
        }

        while(j < end){
            l[k] = a[j];
            ++k;
            ++j;
        }

        for(int itr=0;itr<end-start;++itr){
            a[start+itr] = l[itr];
        }

        //delete[] l;
    }
};

int main(){
    int a[] = {14,33,27,10,35,19,42,44};
    int n = sizeof(a)/sizeof(*a);
    MergeSort::mergeSort(a, 0, n);
    for(int i =0; i<n;++i){
        cout << a[i] << " " <<endl;
    }
}
