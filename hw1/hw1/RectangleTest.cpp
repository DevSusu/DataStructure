#include <iostream>
#include "Rectangle.h"

using namespace std;

int main() {
    
    // xlow, ylow, height, width
    Rectangle a = Rectangle(-3,-3,3,6);
    Rectangle b = Rectangle(7,7,4,5);
    cout << a << b << (a&b) << endl; // 0
    cout << a << b << (a|b) << endl; // 0
    
    Rectangle a4 = Rectangle(6,6,4,6);
    Rectangle b4 = Rectangle(3,4,5,4);
    cout << a4 << b4 << (a4&b4) << endl;
    cout << a4 << b4 << (a4|b4) << endl;
    Rectangle a5 = Rectangle(-8,-2,6,8);
    Rectangle b5 = Rectangle(-3,-4,10,7);
    cout << a5 << b5 << (a5&b5) << endl;
    cout << a5 << b5 << (a5|b5) << endl;
    Rectangle a6 = Rectangle(0,5,5,5);
    Rectangle b6 = Rectangle(2,3,1,1);
    cout << a6 << b6 << (a6&b6) << endl;
    cout << a6 << b6 << (a6|b6) << endl;
    Rectangle a7 = Rectangle(3,4,2,2);
    Rectangle b7 = Rectangle(0,5,5,5);
    cout << a7 << b7 << (a7&b7) << endl;
    cout << a7 << b7 << (a7|b7) << endl;

    /*
    Rectangle c = Rectangle(2,3,3,3);
    cout << a << c << (a&c) << endl << (a|c) << endl; // 4 17
    
    Rectangle d = Rectangle(-2,5,3,4);
    cout << a << d << (a&d) << endl; // 4
    
    Rectangle e = Rectangle(-2,3,10,10);
    cout << a << e << (a&e) << endl; // 12
    
    CppArray aa = CppArray(5,0.0);
    CppArray bb = aa;
    
    aa[1] = 1.0; aa[2] = 2.0;
    cout << aa << endl; // 0 1 2 0 0
    cout << bb << endl; // 0 0 0 0 0
    
    CppArray cc = CppArray(10,1.1);
    cout << cc << endl; // 0 0 0 0 0
    
    cc = aa;
    cout << cc << endl; // 0 0 0 0 0
    */
    
    return 0;
}
