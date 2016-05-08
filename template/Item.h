#ifndef ITEM_H
#define ITEM_H

template <class T>
class Item{
    T data;

public:
    Item();
    T GetData();
    void SetData(T& data);
};

#include "Item.cpp"

#endif 