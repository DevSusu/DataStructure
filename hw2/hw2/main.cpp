#include "Queue_Rot.h"
#include "Node.h"
#include "Math.h"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    Node *a = new Node(0, new Node(2, new Node(5, new Node(6, new Node(7)))));
    Node *b = new Node(0, new Node(1, new Node(3, new Node(4, new Node(5)))));
    a->Merge(b);
    Node *temp = a->GetNext();
    while (temp != nullptr || temp != NULL) {
        cout << temp->GetData() << endl;
        temp = temp->GetNext();
    }
    
    return 0;
}
