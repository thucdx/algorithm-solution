#include <iostream>
#include <cstdio>
#include <conio.h>

using namespace std;

void swap(int* a, int* b);
void swap2(int &a, int &b);

int main()
{
    int a = 5;
    int b = 6;
    cout << "before " << a << "  " << b << endl;
    swap2(a, b);
    cout << "after " << a << "  " << b << endl;
    
    getch();
}
    
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap2(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;    
}
