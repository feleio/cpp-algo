#include <iostream>
#include <vector>

using namespace std;

template <class T1, class T2>
class Pair{
public:
    Pair():data1(T1()), data2(T2()){}
    Pair(const Pair<T1, T2>& other):data1(other.data1), data2(other.data2){}
    ~Pair(){}

    bool operator == (const Pair<T1, T2>& other) const{
        return data1 == other.data1 && data2 == other.data2;
    }

    bool operator != (const Pair<T1, T2>& other) const{
        return !operator== (other);
    }

    bool operator > (const Pair<T1, T2>& other) const{
        if(data1 == other.data1){
            return data2 > other.data2;
        } else {
            return data1 > other.data1;
        }
    }

    bool operator < (const Pair<T1, T2>& other) const{
        return !(operator>(other) || operator==(other));
    }

    bool operator <= (const Pair<T1, T2>& other) const{
        return operator<(other) || operator==(other);
    }

    bool operator >= (const Pair<T1, T2>& other) const{
        return operator>(other) || operator==(other);
    }

    bool operator = (const Pair<T1, T2>& other){
        data1 = other.data1;
        data2 = other.data2;
    }

    void swap(Pair<T1, T2>& other){
        T1 tmp1 = other.data1;
        other.data1 = data1;
        data1 = tmp1;

        T2 tmp2 = other.data2;
        other.data2 = data2;
        data2 = tmp2;
    }


    void print() const{
        cout << "data1 " << data1 << "  data2 " << data2 << endl;
    }

    T1 data1;
    T2 data2;
};

int main(){
    Pair<int, bool> p1;
    p1.data1 = 2;
    p1.data2 = false;

    Pair<int, bool> p2;
    p2.data1 = 3;
    p2.data2 = true;

    Pair<int, bool> p3;
    p3 = p1;

    p1.print();
    p2.print();

    p1.swap(p2);

    p1.print();
    p2.print();
    //cout << "== " << (p1 <= p2) <<endl;
}