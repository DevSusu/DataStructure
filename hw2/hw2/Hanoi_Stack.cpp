#include <iostream>
#include "StackForHanoi.h"

using namespace std;

void printTowers(StackForHanoi* towers);
void hanoi(StackForHanoi* source, StackForHanoi* middle, StackForHanoi* dest, int level);

int main() {
    int n;
    cin >> n;
    
    StackForHanoi towers[3] = {
        StackForHanoi(1,n,n), StackForHanoi(2,n,0), StackForHanoi(3,n,0)
    };
    
    printTowers(towers);
    hanoi(towers, towers+1, towers+2, n);
    printTowers(towers);
}

void printTowers(StackForHanoi* towers) {
    for(int i=0;i<3;i++) {
        cout << "Tower " << i+1 << " :";
        for(int j=0;j<=towers[i].Top();j++) {
            cout << " " << towers[i][j];
        }
        cout << endl;
    }
}

void hanoi(StackForHanoi* source, StackForHanoi* middle, StackForHanoi* dest, int level) {
    
    if( level == 1 ) {
        int plate = source->Pop();
        dest->Push(plate);
        cout << plate << "th disk : " << source->Num() << " -> " << dest->Num() << endl;
        return;
    }
    
    hanoi(source, dest, middle, level-1);
    hanoi(source, middle, dest, 1);
    hanoi(middle, source, dest, level-1);
    
}