#include "Bag.h"
#include "Bag.cpp"
#include "Stack.h"
#include "Stack.cpp"

int main() {
    
    Bag<int> b(3); cout << endl;
    Stack<int> s(3); cout << endl;
    
    b.Push(1); b.Push(2); b.Push(3); cout << endl;
    s.Push(1); s.Push(2); s.Push(3); cout << endl;
    
    cout << "Bag.Element:" << b.Element() << endl << endl;
    cout << "Bag.Size:" << b.Size() << endl << endl;
    
    cout << "Stack.Element:" << s.Element() << endl << endl;
    cout << "Stack.Size:" << s.Size() << endl << endl;
    
    b.Pop(); cout << endl;
    
    cout << "Bag.Element:" << b.Element() << endl << endl;
    cout << "Bag.Size:" << b.Size() << endl << endl;
    
    s.Pop(); cout << endl;
    
    cout << "Stack.Element:" << s.Element() << endl << endl;
    cout << "Stack.Size:" << s.Size() << endl << endl;
    
    return 0;
}