#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <ostream>
using namespace std;

class Rectangle {
public:
    Rectangle();
    Rectangle(int x,int y,int h,int w);
    ~Rectangle();
    int GetHeight();
    int GetWidth();
    void SetHeight(int);
    void SetWidth(int);
    
    int operator==(const Rectangle&);
    friend ostream& operator<<(ostream&, const Rectangle&);
    
private:
    int xlow, ylow, height, width;
};

#endif