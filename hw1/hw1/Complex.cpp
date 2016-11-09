#include "Complex.h"
using namespace std;

Complex::Complex() {
    Complex(0,0);
}

Complex::Complex(int re, int im) {
    this->re = re;
    this->im = im;
}

Complex Complex::operator+(Complex& com) {
    return Complex( this->re + com.re , this->im + com.im );
}
Complex Complex::operator-(Complex& com) {
    return Complex( this->re - com.re , this->im - com.im );
}
Complex Complex::operator*(Complex& com) {
    return Complex(this->re * com.re - this->im * com.im, this->re * com.im + this->im * com.re);
}

ostream& operator<<(ostream& os, const Complex& com)
{
    os << "(" << com.re << "+" << com.im << "i)";
    return os;
}