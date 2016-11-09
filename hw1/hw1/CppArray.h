#ifndef CPPARRAY_H
#define CPPARRAY_H

#include <ostream>
using namespace std;

class CppArray
{
public:
    
    CppArray(int size, float initvalue);
    CppArray(const CppArray& cp2);
    
    ~CppArray();
    
    CppArray& operator= (const CppArray& cp2);
    float& operator[] (int i) const;
    
    friend ostream& operator<<(ostream& os, const CppArray& cp);
    
    int GetSize() const;
    
private:
    
    int size;
    float* floatArray;
};

#endif