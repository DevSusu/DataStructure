#ifndef STACKFORHANOI_H
#define STACKFORHANOI_H

class StackForHanoi {
public:
    
    StackForHanoi(int stackNum, int stackCapacity, int def);
    ~StackForHanoi();
    
    int Push(int element);
    int Pop();
    int Top();
    int Num();
    
    int& operator[](int i);
    
private:
    
    int *array;
    int top;
    int capacity;
    int num;
};

#endif