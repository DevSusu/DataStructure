
#include <iostream>
#include <time.h>

using namespace std;

void hanoi(int* source, int* middle, int* dest, int level);
void push(int* arr, int value);
int pop(int* arr);

int n;
int main(int argc, const char * argv[]) {
    
    for( n=18;n>=1;n-- ) {
        
        int a[30],b[30],c[30];
        fill(a,a+n+1,0);
        fill(b,b+n+1,0);
        fill(c,c+n+1,0);
        
        a[0] = 1; b[0] = 2; c[0] = 3;
        
        for(int i=1;i<=n;i++) {
            a[i] = n-i+1;
        }
        
        long start_time = clock();
        
        hanoi(a,b,c,n);
        
//        cout << "원판 갯수" << n << "개 : " << clock() - start_time << "ms" << endl;
        cout << clock() - start_time << endl;
        
    }
    
    return 0;
}
void push(int* arr, int value) {
    int i;
    for(i=1;arr[i]!=0;i++);
    arr[i] = value;
}

int pop(int* arr) {
    int i, value;
    for(i=n;arr[i]==0;i--);
    
    value = arr[i]; arr[i] = 0;
    return value;
}

void hanoi(int* source, int* middle, int* dest, int level) {

    if( level == 1 ) {
        int plate = pop(source);
//        cout << plate << "번째 원판 : " << source[0] << " -> " << dest[0] << endl;
        push(dest, plate);
        
        return;
    }
    
    hanoi(source, dest, middle, level-1);
    hanoi(source, middle, dest, 1);
    hanoi(middle, source, dest, level-1);
    
}