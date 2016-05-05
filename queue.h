#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedListNode.h"
#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
    LinkedListNode<T>* head;
    LinkedListNode<T>* tail;
public:
    Queue(): head(NULL), tail(NULL) {}
    ~Queue(){
        LinkedListNode<T>* curNode = tail;
        while(curNode != NULL){
            LinkedListNode<T>* toBeDelete = curNode;
            curNode = curNode->next;
            delete curNode;
        }
    }

    void push(const T& t){
        LinkedListNode<T>* newNode = new LinkedListNode<T>();
        newNode->data = t;
        if(!isEmpty()){
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    void pop(){
        if(!isEmpty()){
            LinkedListNode<T>* toBeDelete = head;
            head = head->next;
            if(head == NULL){
                tail = head;
            }
            delete toBeDelete;
        }
    }

    bool isEmpty() const{
        return head == NULL;
    }

    const T& front() const{
        return head->data;
    }

    void print() const{
        LinkedListNode<T>* curNode = head;
        while(curNode != NULL){
            cout << curNode->data << " -> ";
            curNode = curNode->next;
        }
        cout << endl;
    }
};

#endif
