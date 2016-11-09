#include "StackForHanoi.h"

StackForHanoi::StackForHanoi(int stackNum, int stackCapacity, int def) : num(stackNum), capacity(stackCapacity) {
    
    array = new int[capacity];
    top = def - 1;
    
    for(int i=0;i<def;i++) {
        array[i] = def - i;
    }
    
}

StackForHanoi::~StackForHanoi() {
    delete[] array;
}

int StackForHanoi::Push(int element) {
    if( top == capacity -1 ) {
        return 0;
    }
    array[++top] = element;
    return 1;
}

int StackForHanoi::Pop() {
    return array[top--];
}

int StackForHanoi::Top() {
    return top;
}

int StackForHanoi::Num() {
    return num;
}

int& StackForHanoi::operator[](int i) {
    return array[i];
}