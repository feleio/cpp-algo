#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListNode.h"
#include <iostream>

using namespace std;

template<class T>
class LinkedList
{
private:
    LinkedListNode<T>* head;
    LinkedListNode<T>* tail;

public:
    LinkedList() : head(NULL), tail(NULL) {}
    ~LinkedList(){
        LinkedListNode<T>* curNode = head;
        while(curNode != NULL){
            LinkedListNode<T>* toBeDelete = curNode;
            curNode = curNode->next;
            delete toBeDelete;
        }
    }

    void append(const T& t){
        LinkedListNode<T>* newNode = new LinkedListNode<T>();
        newNode->data = t;
        if (head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void remove(const T& t){
        LinkedListNode<T>* curNode = head;
        LinkedListNode<T>* prevNode = NULL;

        while(curNode != NULL && curNode->data != t ){
            prevNode = curNode;
            curNode = curNode->next;
        }

        if(curNode != NULL){
            if(curNode == head){
                head = curNode->next;
            } else {
                if(curNode == tail){
                    tail = prevNode;
                }
                prevNode->next = curNode->next;
            }
            delete curNode;
        }
    }

    const T* find(const T& t){
        LinkedListNode<T>* curNode = head;
        while(curNode != NULL && curNode->data != t ){
            curNode = curNode->next;
        }

        if(curNode != NULL){
            return &(curNode->data);
        }
        return NULL;
    }

    void print(){
        LinkedListNode<T>* curNode = head;
        while(curNode != NULL){
            cout << curNode->data << " -> ";
            curNode = curNode->next;
        }
        cout << endl;
    }
};

#endif
