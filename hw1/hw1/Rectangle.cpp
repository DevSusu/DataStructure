#include "Rectangle.h"

#include <iostream>
using namespace std;

Rectangle::Rectangle() {
    xlow = 0;
    ylow = 0;
    height = 0;
    width = 0;
}

Rectangle::Rectangle(int x, int y, int h, int w)
{
    xlow = x;
    ylow = y;
    height = h;
    width = w;
}

Rectangle::~Rectangle() {}

int Rectangle::GetHeight() const {
    return height;
}
int Rectangle::GetWidth() const {
    return width;
}
int Rectangle::GetArea() const {
    return height*width;
}

void Rectangle::SetHeight(int h) {
    height = h;
}
void Rectangle::SetWidth(int w) {
    width = w;
}

int Rectangle::operator==(const Rectangle &s)
{
    if (this == &s)
        return true;
    
    if ((xlow == s.xlow) && (ylow == s.ylow) && (height == s.height) && (width == s.width))
        return true;
    else
        return false;
}

int Rectangle::operator&(const Rectangle& s)
{
    const Rectangle* left;
    const Rectangle* right;
    
    // 경우의 수를 줄이기 위해, left 가 항상 right 왼쪽에 있도록 배치
    if( this->xlow <= s.xlow ) {
        left = this;
        right = &s;
    } else {
        left = &s;
        right = this;
    }
    
    // 겹치는 부분의 좌 우 하 상
    int xmin, xmax, ymin, ymax;
    
    xmin = right->xlow;
    xmax = std::min( left->xlow + left->width , right->xlow + right->width );
    ymin = std::max( left->ylow, right->ylow );
    ymax = std::min( left->ylow + left->height , right->ylow + right->height );
 
    // 음수면 겹치지 않는 경우
    return std::max(0, (xmax-xmin)*(ymax-ymin));
}

int Rectangle::operator|(const Rectangle& s)
{
    return this->GetArea() + s.GetArea() - ( (*this)&s );
}

ostream& operator<<(ostream& os, const Rectangle& r) {
    os << "Position is:" << r.xlow << " "; os << r.ylow << endl;
    os << "Height is:" << r.height << endl; os << "Width is:" << r.width << endl; return os;
}