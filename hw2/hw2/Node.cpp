#include "Node.h"

Node::Node(int input) {
    data = input;
}

Node::Node(int input, Node* link) {
    data = input;
    next = link;
}

void Node::SetNext(Node* link) {
    next = link;
}

Node* Node::GetNext() {
    return next;
}

int Node::GetData() {
    return data;
}

void Node::Merge(Node* node2) {
    
    // node2가 빈 경우
    if( !node2 ) {
        return;
    }
    // 다음 Node 가 없을 경우 추가하고 끝냄.
    if( !next ) {
        SetNext(node2);
        return;
    }
    
    Node* i1, *i2;
    i1 = this; i2 = node2->next;
    do {
        
        if( i2->GetData() < i1->next->GetData() ) {
            Node* tmp = i1->next;
            Node* tmp2 = i2->next;
            i1->SetNext(i2);
            i2->SetNext(tmp);
            
            i2 = tmp2;
        }
        i1 = i1->GetNext();
        
    } while( i1->next && i2 );
    
    // 남은 것 모두 병합하는 과정
    if( !i1->next ) i1->SetNext(i2);

}