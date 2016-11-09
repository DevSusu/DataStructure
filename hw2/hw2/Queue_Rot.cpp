#include "Queue_Rot.h"
#include <iostream>

Queue_Rot::Queue_Rot(int queueCapacity) : capacity(queueCapacity) {
    if(capacity < 1) throw "Queue capacity must be > 0";
    array = new int[queueCapacity];
    front = rear = 0;
}

Queue_Rot::~Queue_Rot() {
    delete[] array;
}

bool Queue_Rot::IsEmpty() {
    return front == rear;
}

int Queue_Rot::Front() {
    return array[(front+1)%capacity];
}

int Queue_Rot::Rear() {
    return array[rear];
}

bool Queue_Rot::Push(int item) {
    
    if( (rear+1)%capacity == front ) {
        return false;
    }
    rear = (rear+1)%capacity;
    array[rear] = item;
    return true;
}

void Queue_Rot::Pop() {
    if( IsEmpty() ) return;
    
    front =(front+1)%capacity;
}

int Queue_Rot::Size() {
    int size = rear - front;
    if( size < 0 ) size += capacity+1;
    return size;
}

void Queue_Rot::Rotate(int amount) {
    if( IsEmpty() ) return;
    
    if(amount < 0) amount *=-1;
    else amount = Size() - amount;

    for(int i=0;i<amount;i++) {
        int tmp = Front();
        Pop();
        Push(tmp);
    }
}
void Queue_Rot::Print() {
    for(int i=(front+1)%capacity;i!=rear;i=(i+1)%capacity) {
        std::cout << array[i] << " ";
    }
    std::cout << array[rear];
    std::cout << std::endl;
}