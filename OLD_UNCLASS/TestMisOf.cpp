#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>
const int MAXN = 20;
int tr[MAXN + 1][1 << MAXN];
void insert(int x) { FOR(i, 0, MAXN) tr[i][x]++, x >>= 1; }
void erase(int x) { FOR(i, 0, MAXN) tr[i][x]--, x >>= 1; }
int kThElement(int k) {
    int a = 0, b = MAXN;
    while (b--) a <<= 1, k -= (tr[b][a] < k ? tr[b][a++] : 0);
    return a;
}

int main()
{
    insert(2);
    insert(3);
    insert(0);
    insert(40);
    insert(5);
    insert(1);
    REP(i,1,6)
        cout<<i<<" "<<kThElement(i)<<endl;
       getch();    
}
    
