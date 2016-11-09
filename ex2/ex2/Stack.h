#ifndef STACK_H
#define STACK_H

#include "Bag.h"

template <class T>
class Stack : public Bag<T> {
public:
    Stack(int stackCapacity = 10);
    ~Stack();
    int Top() const;
    void Pop();
};

#endif