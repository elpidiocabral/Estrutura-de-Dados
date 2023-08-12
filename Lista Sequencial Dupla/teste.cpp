#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "doublevector.cpp"

using namespace std;

int main() {
    DoubleVector teste = DoubleVector(6);
    
    for(int i=0; i<5; i++) {
        int a;
        cin >> a;
        teste.push_back(a);  
        //teste.print();
    } 
    // cout << teste.pop_front() << endl;
    teste.print();
    teste.insert(100, 1);
    printf("\n");
    teste.print();
    printf("\n");
    //teste.printReverse();
    //printf("%d\n%d", teste.at(2), teste.at(4));
}