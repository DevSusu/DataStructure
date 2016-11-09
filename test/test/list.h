#ifndef LIST_H
#define LIST_H

class List {
private:
    class listNode {
    public:
        int getData();
        int data;
        listNode* next;
        listNode(int newItem);
    };
    
    List(int size, listNode* head) : size(0), head(head){};
    ~List();
    int GetSize();
    
private:
    listNode* head;
    int size;
};

#endif