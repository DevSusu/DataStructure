
#include "CppArray.h"

#include <ostream>
using namespace std;

CppArray::CppArray(int size, float initvalue) {
    this->size = size;
    floatArray = new float[size];
    fill(floatArray, floatArray+size, initvalue);
}

// copy constructor
CppArray::CppArray(const CppArray& cp2) {
    
    size = cp2.size;
    floatArray = new float[size];
    for(int i=0;i<size;i++) {
        floatArray[i] = cp2[i];
    }
    
}

CppArray::~CppArray() {
    delete[] floatArray;
}

CppArray& CppArray::operator=(const CppArray& cp2) {
    
    delete[] floatArray;
    size = cp2.size;
    floatArray = new float[size];
    for(int i=0;i<size;i++) {
        floatArray[i] = cp2[i];
    }
    
    return (*this);
}

float& CppArray::operator[](int i) const {
    return floatArray[i];
}

int CppArray::GetSize() const {
    return size;
}

ostream& operator<< (ostream& os, const CppArray& cp) {
    os << "[" << cp[0];
    for(int i=1;i<cp.size;i++) {
        os << ", " << cp[i];
    }
    os << "]";
    
    return os;
}