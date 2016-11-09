#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(int r, int c, int t) : Rows(r), Cols(c), Terms(t) {}

int MatrixTerm::GetRow() { return row; }
int MatrixTerm::GetCol() { return col; }
int MatrixTerm::GetValue() { return value; }

int SparseMatrix::AddTerms(int row, int col, int value)
{
    for (int i = 0; i < Terms; i++) {
        if (smArray[Terms].row == row && smArray[Terms].col == col) {
            return 0;
        }
    }
    if (Terms < MaxTerms) {
        smArray[Terms].row = row; smArray[Terms].col = col; smArray[Terms++].value = value; return 1;
    }
    return 0;
}

SparseMatrix SparseMatrix::Transpose()
{
    SparseMatrix b(Cols, Rows, Terms); if (Terms > 0)
    {
        int CurrentB = 0;
        for (int c = 0; c < Cols; c++)
            for (int i = 0; i < Terms; i++)
                if (smArray[i].col == c) {
                    b.smArray[CurrentB].row = c;
                    b.smArray[CurrentB].col = smArray[i].row;
                    b.smArray[CurrentB].value = smArray[i].value; CurrentB++;
                }
    }
    return b;
}

SparseMatrix SparseMatrix::FastTranspose()
{
    SparseMatrix b(Cols, Rows, Terms);
    
    if (Terms > 0)
    {
        int *rowSize = new int[Cols];
        int *rowStart = new int[Cols];
        fill(rowSize, rowSize + Cols, 0);
        for (int i = 0; i < Terms; i++)
            rowSize[smArray[i].col]++; rowStart[0] = 0;
        for (int i = 1; i < Cols; i++)
            rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
        for (int i = 0; i < Terms; i++)
        {
            int j = rowStart[smArray[i].col];
            b.smArray[j].row = smArray[i].col;
            b.smArray[j].col = smArray[i].row;
            b.smArray[j].value = smArray[i].value;
            rowStart[smArray[i].col]++;
        }
        delete[] rowSize;
        delete[] rowStart;
    }
    return b;
}