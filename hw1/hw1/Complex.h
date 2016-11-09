#ifndef _COMPLEX_H_
#define _COMPLEX_H_
#include <ostream>
using namespace std;

class Complex {
public:
    Complex();
    Complex(int re, int im);
    
    Complex operator+(Complex& com);
    Complex operator-(Complex& com);
    Complex operator*(Complex& com);
    friend ostream& operator<<(ostream& os, const Complex& com);
    
private:
    int re, im;
};

#endif