#include <iostream>
#include <algorithm>
#include <cstdio>
#include <conio.h>
using namespace std;

int tree[17][65536];
void insert(int x) { for (int i=0; i<17; i++) { tree[i][x]++; x/=2; } }
void erase(int x) { for (int i=0; i<17; i++) { tree[i][x]--; x/=2; } }
int kThElement(int k) {
    int a=0, b=16;
    while (b--) { a*=2; if (tree[b][a]<k) k-=tree[b][a++]; }
    return a;
}
int main()
{
    insert(4);
    insert(1);
    insert(3);
    insert(-1);
    insert(30);
    cout<<kThElement(2)<<endl;
    insert(0);
    cout<<kThElement(4)<<endl;
    getch();    
}
