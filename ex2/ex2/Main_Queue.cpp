#include "Queue.h"
#include "Queue.cpp"
#include <iostream>

int main() {
    Queue<int> q1(2);
    Queue<float> q2(2);
    
    q1.Push(1); q1.Push(5);
    cout << "Q1.Front : " << q1.Front() << endl;
    cout << "Q1.Rear : " << q1.Rear() << endl;
    
    q1.Push(2); q1.Pop();
    cout << "Q1.Front : " << q1.Front() << endl;
    cout << "Q1.Rear : " << q1.Rear() << endl;
    
    q2.Push(3.1415); q2.Push(2.78); q2.Push(1.414);
    cout << "Q2.Front : " << q2.Front() << endl;
    cout << "Q2.Rear : " << q2.Rear() << endl;
    
    q2.Push(2); q2.Pop();
    cout << "Q2.Front : " << q2.Front() << endl;
    cout << "Q2.Rear : " << q2.Rear() << endl;
    
    return 0;
}