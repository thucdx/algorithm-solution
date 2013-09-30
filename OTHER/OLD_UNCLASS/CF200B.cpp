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

using namespace std;

#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);

#define pb  push_back
#define ins insert
#define all(x) begin(x), end(x)
#define sz(x) size(x)
#define ms(arr,val) memset(arr, val, sizeof(arr))

#define INF 1000000000
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>

#include <conio.h>
int main()
{
    //freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);

    int n, val;
    int sum = 0;
    cin>> n;
    REP(i,1,n)
    {
       cin >> val;     
       sum += val;
    }
    
    printf("%.6lf", sum * 100.0 / (100 * n));
    //getch();
}
