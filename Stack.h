#ifndef STACK_H
#define STACK_H

#include "LinkedListNode.h"

template <class T>
class Stack
{
private:
    LinkedListNode<T>* head;
public:
    Stack(): head(NULL) {}
    ~Stack(){
        LinkedListNode<T>* curNode = head;
        while(curNode != NULL){
            LinkedListNode<T>* toBeDelete = curNode;
            curNode = curNode->next;
            delete curNode;
        }
    }

    void push(const T& t){
        LinkedListNode<T> * newNode = new LinkedListNode<T>();
        newNode->data = t;
        newNode->next = head;
        head = newNode;
    }

    void pop(){
        if(!isEmpty()){
            LinkedListNode<T> * toBeDelete = head;
            head = head->next;
            delete toBeDelete;
        }
    }

    bool isEmpty() const{
        return head == NULL;
    }

    const T& top() const{
        return head->data;
    }
};

#endif
