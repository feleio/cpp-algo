#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[] = {5,8,3,6,1,4,2};
    int n = sizeof(a) / sizeof(*a);
    make_heap(a, a + n);

    // heap sort
    for(int i=n;i>=0;--i){
        pop_heap(a, a + i);
    }

    for(int i=0;i<n;++i){
        cout << a[i] << " ";
    }
    cout <<endl;

}
