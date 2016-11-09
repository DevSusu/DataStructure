#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node(int input);
    Node(int input, Node* link);
    
    void SetNext(Node* link);
    Node* GetNext();
    int GetData();
    
    void Merge(Node* node2);
    
private:
    int data;
    Node* next;
};

#endif