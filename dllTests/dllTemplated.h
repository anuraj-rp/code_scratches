//
// Created by ARajendraprakash on 21-Mar-20.
//

#ifndef DLLTESTS_DLLTEMPLATED_H
#define DLLTESTS_DLLTEMPLATED_H

template<typename T>
class DLList;

template<typename T>
class dllNode {
private:
    T value;
    dllNode* next;
    dllNode* prev;
    friend class DLList<T>; //to access the private members
};

template<typename T>
class DLList{
private:
    dllNode<T>* head;
    dllNode<T>* tail;
public:
    DLList();
    ~DLList();
    bool isEmpty() const;
    void addFront(const T& value);
    void addBack(const T& value);
    void removeFront();
    void removeBack();
    void printList() const;
    int getNodeCount(const dllNode<T>* hd);
    dllNode<T>* getHead();
    dllNode<T>* getFront();
    void sortList(dllNode<T>* head, dllNode<T>* p1, dllNode<T>* p2);

protected:
    void addBeforeNodeX(dllNode<T>* x, const T& value);
    void remove(dllNode<T>* x);
};

template class DLList<int>;
template class DLList<float>;
#endif //DLLTESTS_DLLTEMPLATED_H
