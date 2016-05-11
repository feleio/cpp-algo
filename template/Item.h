#ifndef ITEM_H
#define ITEM_H

template <class T>
class Item{
    T data;

public:
    Item();
    T GetData();
    void SetData(T data);
    template <class U>
    void SetAverageFrom(U values[], int n);
    operator double();

    template <class U>
    void operator= (const U& other);
};

#include "Item.cpp"

#endif 