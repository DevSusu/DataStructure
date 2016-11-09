#ifndef QUEUE_ROT_H
#define QUEUE_ROT_H

class Queue_Rot {
public:
    Queue_Rot(int queueCapacity);
    ~Queue_Rot();
    bool IsEmpty();
    int Front();
    int Rear();
    
    bool Push(int item);
    void Pop();
    void Rotate(int amount);
    
    int Size();
    
    void Print();
    
private:
    int *array;
    int front;
    int rear;
    int capacity;
};

#endif