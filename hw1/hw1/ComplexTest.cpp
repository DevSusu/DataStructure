#include <iostream>
#include "Complex.h"

using namespace std;
int main() {
    
    Complex a = Complex();
    Complex b = Complex(-1,-1);
    Complex c = Complex(3,2);
    Complex d = Complex(5,3);
    
    cout << a << endl;
    cout << a+b << endl;
    
    cout << c+d << endl;
    cout << c-d << endl;
    cout << c*d << endl;
    
    return 0;
}