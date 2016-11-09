#include "Stack.h"
#include <iostream>
using namespace std;

template <class T>
Stack<T>::Stack(int stackCapacity) : Bag<T>::Bag(stackCapacity) {
    cout << "call Stack:Stack()" << endl;
}

template <class T>
Stack<T>::~Stack() {
    cout << "call Stack:~Stack()" << endl;
}

template <class T>
int Stack<T>::Top() const {
    cout << "call Stack:Top()" << endl;
    if(Bag<T>::IsEmpty()) throw "Stack is empty.";
    return Bag<T>::array[ Bag<T>::top ];
}

template <class T>
void Stack<T>::Pop() {
    cout << "call Stack:Pop()" << endl;
    if(Bag<T>::IsEmpty()) throw "Stack is empty. cannot delete";
    Bag<T>::top--;
}