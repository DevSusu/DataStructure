#include "Bag.h"
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize){
    if( newSize < 0 ) throw "New length must be > = 0";
    T* temp = new T[newSize];
    int number = min(oldSize, newSize);
    
    copy(a, a+number, temp);
    delete[] a;
    a = temp;
}

template <class T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity) {
    cout << "call Bag:Bag()" << endl;
    if( capacity < 1 ) throw "Capactiy must be > 0";
    array = new T[capacity];
    top = -1;
}

template <class T>
Bag<T>::~Bag() {
    cout << "call Bag:~Bag()" << endl;
    delete[] array;
}

template <class T>
int Bag<T>::Size() const {
    cout << "call Bag:Size()" << endl;
    return top + 1;
}

template <class T>
bool Bag<T>::IsEmpty() const {
    cout << "call Bag:IsEmpty()" << endl;
    return Size() == 0;
}

template <class T>
int Bag<T>::Element() const {
    cout << "call Bag:Element()" << endl;
    if( IsEmpty() ) throw "Bag is empty";
    return array[0];
}

template <class T>
void Bag<T>::Push(const T& e) {
    cout << "call Bag:Push()" << endl;
    if(capacity == Size()) {
        ChangeSize1D(array, capacity, 2*capacity);
        capacity*=2;
    }
    array[++top] = e;
}

template <class T>
void Bag<T>::Pop() {
    cout << "call Bag:Pop()" << endl;
    if( IsEmpty() ) throw "Bag is empty. cannot delete";
    int deletePos = top/2;
    
    copy(array + deletePos + 1, array + top + 1, array + deletePos);
    array[top--].~T();
}