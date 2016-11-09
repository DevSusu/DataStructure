#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#define MaxTerms 10000

#include <iostream>
using namespace std;

class SparseMatrix;

class MatrixTerm {
    friend class SparseMatrix; public:
    int GetRow(); int GetCol(); int GetValue();
private:
    int row, col, value;
};

class SparseMatrix {
public:
    SparseMatrix(int, int, int); SparseMatrix Transpose(); SparseMatrix FastTranspose(); int AddTerms(int, int, int);
private:
    int Rows, Cols, Terms;
    MatrixTerm smArray[MaxTerms];
}
;
#endif