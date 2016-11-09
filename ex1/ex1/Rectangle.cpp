#include "Rectangle.h"

#include <ostream>
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
int Rectangle::GetHeight() {
    return height;
}
int Rectangle::GetWidth() {
    return width;
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

ostream& operator<<(ostream& os, const Rectangle& r) {
    os << "Position is:" << r.xlow << " "; os << r.ylow << endl;
    os << "Height is:" << r.height << endl; os << "Width is:" << r.width << endl; return os;
}