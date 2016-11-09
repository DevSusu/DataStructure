#include "BST.h"
#include "BST.cpp"
#include <iostream>

int main(int argc, const char * argv[]) {

    BST<int,float>* bst = new BST<int,float>();
    
    std::cout << bst->IsEmpty() << std::endl;
    
    bst->Insert(4, 4.4);
    bst->Insert(3, 3.3);
    bst->Insert(6, 6.6);
    bst->Insert(1, 1.1);
    bst->Insert(5, 5.5);
    bst->Insert(8, 8.8);
    bst->Insert(7, 7.7);
    bst->Insert(9, 9.9);
    
    bst->Remove(1);
    bst->Levelorder();
    std::cout << std::endl;
    
    bst->Remove(4);
    bst->Levelorder();
    std::cout << std::endl;
    
    bst->Remove(3);
    bst->Levelorder();
    std::cout << std::endl;
    
    
    
    return 0;
}
