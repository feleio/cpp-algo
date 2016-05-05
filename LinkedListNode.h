#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include <iostream>

template <class T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> * next;
public:
    LinkedListNode() : data(), next(NULL){}
    ~LinkedListNode(){}
};

#endif
