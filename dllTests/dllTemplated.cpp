//
// Created by ARajendraprakash on 21-Mar-20.
//

#include <iostream>
#include <string>
#include <exception>

#include "dllTemplated.h"

using namespace std;
template<typename T>
DLList<T>::DLList() {
    head = new dllNode<T>;
    tail = new dllNode<T>;

    //point head and tail to each other
    head->next = tail;
    tail->prev = head;

    //end the list with NULL to know termination
    head->prev = NULL;
    tail->next = NULL;
}

template<typename T>
DLList<T>::~DLList(){
    while(!isEmpty()){
        removeFront();
    }
    delete(head);
    delete(tail);
}

template<typename T>
bool DLList<T>::isEmpty() const {
    return (head->next == tail);
}

template<typename T>
void DLList<T>::addBeforeNodeX(dllNode<T> *x, const T &value) {

    dllNode<T>* newNode = new dllNode<T>;
    newNode->value = value;

    //unlink and relink the next and prev pointers of the new node
    //and adjacent nodes
    newNode->next = x;
    newNode->prev = x->prev;
    x->prev->next = newNode;
    x->prev = newNode;
}

template<typename T>
void DLList<T>::addFront(const T &value) {
    addBeforeNodeX(head->next, value);
}

template<typename T>
void DLList<T>::addBack(const T &value) {
    addBeforeNodeX(tail, value);
}

template<typename T>
void DLList<T>::remove(dllNode<T> *x) {

    //unlink and relink adjacent nodes next/prev pointers
    dllNode<T>* prevNode = x->prev;
    dllNode<T>* nextNode = x->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    //boundary checks. needed?
    if(prevNode == head)
        head->prev = NULL;
    if(nextNode == tail)
        tail->next = NULL;
    delete x;
}

template<typename T>
void DLList<T>::removeFront() {
    try{
        if(head->next != tail)
        {
            remove(head->next);
            return;
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}

template<typename T>
void DLList<T>::removeBack() {
    try{
        if(head->next != tail)
        {
            remove(tail->prev);
        }
    }
    catch (exception& e){
        cout << e.what() << endl;
    }
}

template<typename T>
void DLList<T>::printList() const {
    try{
        if(head->next != tail){
            dllNode<T>* temp = head->next;
            while(temp->next != NULL){
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
    }
    catch (exception& e){
        cout << e.what() << endl;
    }
}

template<typename T>
dllNode<T>* DLList<T>::getHead() {
    return this->head;
}

template<typename T>
dllNode<T>* DLList<T>::getFront() {
    return this->head->next;
}

template<typename T>
int DLList<T>::getNodeCount(const dllNode<T> *hd) {
    int i = 0;

    if(hd->next == tail)
    {
        return i;
    }
    dllNode<T>* temp = (dllNode<T>*)hd;
    while(temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

template<typename T>
void DLList<T>::sortList(dllNode<T> *head, dllNode<T> *p1, dllNode<T> *p2) {
    if(p2->next == NULL)
    {
        return;
    }

    dllNode<T>* p3 = p1->next;
    while(p3->next != NULL)
    {
        if(p1->value < p3->value)
        {
            swap(p1->value, p3->value);
        }
        p3 = p3->next;
    }

    sortList(head, p2, p2->next);//go again
}