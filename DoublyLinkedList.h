#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

using namespace std;

template <class T>
class Node{
public:
    Node* prev;
    Node* next;
    T data;
};

template <class T>
class DoublyLinkedList{
public:
    DoublyLinkedList() : head(NULL), tail(NULL){
    }

    ~DoublyLinkedList(){
        Node<T> * cur = head;
        while(head != NULL){
            Node<T>* toBeDeleted = head;
            head = head->next;
            delete toBeDeleted;
        }
    }

    void prepend(const T& t){
        Node<T>* newNode = new Node<T>();
        newNode->data = t;
        if(empty()){
            newNode->prev = NULL;
            newNode->next = NULL;
            head = tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            newNode->prev = NULL;
            head = newNode;
        }
    }

    void append(const T& t){
        Node<T>* newNode = new Node<T>();
        newNode->data = t;
        if(empty()){
            newNode->prev = NULL;
            newNode->next = NULL;
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = NULL;
            tail = newNode;
        }
    }

    bool empty() const{
        return head == NULL;
    }

    void remove(const T& t){
        Node<T>* curNode = head;
        while(curNode != NULL && curNode->data != t){
            curNode = curNode->next;
        }

        if(curNode != NULL){
            Node<T>* prev = curNode->prev;
            Node<T>* next = curNode->next;
            if (prev != NULL)
                prev->next = next;
            else
                head = next;

            if (next != NULL)
                next->prev = prev;
            else
                tail = prev;

            delete curNode;
        }
    }

    const T& front() const{
        return head->data;
    }

    const T& end() const{
        return tail->data;
    }

    const T* find(const T& t){
        Node<T>* curNode = head;
        while(curNode != NULL && curNode->data != t){
            curNode = curNode->next;
        }
        return curNode != NULL ? &(curNode->data) : NULL;
    }

    void print() const{
        Node<T>* curNode = head;
        while(curNode != NULL){
            cout << curNode->data << " -> " ;
            curNode = curNode->next;
        }
        cout << endl;
    }

    void reversePrint() const{
        Node<T>* curNode = tail;
        while(curNode != NULL){
            cout << curNode->data << " <- " ;
            curNode = curNode->prev;
        }
        cout << endl;
    }

private:
    Node<T> * head;
    Node<T> * tail;
};

#endif
