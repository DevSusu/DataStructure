//
//  main.cpp
//  ex1
//
//  Created by Subin_Choi on 9/19/16.
//  Copyright © 2016 DevSusu. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Rectangle.h"
#include "SparseMatrix.h"

using namespace std;
using namespace chrono;

int main(int argc, const char * argv[]) {
    Rectangle a;
    Rectangle *b = new Rectangle();
    Rectangle c(1, 2, 3, 4);
    
    cout << a << endl;
    cout << *b << endl;
    cout << c << endl;
    cout << "a = b ? " << (a == *b) << endl;
    
    a.SetHeight(4);
    a.SetWidth(3);
    
    cout << a << endl;
    cout << "a = c ? " << (a == c) << endl;
    
    srand(time(NULL));
    SparseMatrix mat(100, 100, 0); int cnt = 0;
    while (cnt < 500){
        int r = rand() % 100;
        int c = rand() % 100;
        int v = rand() % 9 + 1;
        cnt += mat.AddTerms(r, c, v);
    }
    steady_clock::time_point begin = steady_clock::now();
    SparseMatrix mat1 = mat.Transpose();
    steady_clock::time_point end = steady_clock::now();
    cout << "Transpose : " << duration_cast<nanoseconds>(end - begin).count() << "ns" << endl; begin = steady_clock::now();
    SparseMatrix mat2 = mat.FastTranspose();
    end = steady_clock::now();
    cout << "FastTranspose : " << duration_cast<nanoseconds>(end - begin).count() << "ns" << endl;
    
    return 0;
}
