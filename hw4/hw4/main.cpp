#include "AVL.h"
#include "AVL.cpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    AVL<int,float> test;
    
    test.Insert(4, 4.44);
    test.Insert(3, 4.44);
    test.Insert(7, 4.44);
    test.Insert(5, 4.44);
    test.Insert(8, 4.44);

    test.Levelorder();
    
    std::cout << std::endl;
    
    test.Insert(6, 6.66);
    test.Levelorder();
    
    return 0;
}
