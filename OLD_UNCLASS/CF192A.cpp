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
//#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>
int n;
void solve();
bool isTriangular(int n);
bool isSumOfTwoTriangular(int n);
int main()
{
    //freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    cin>>n;
    if(isSumOfTwoTriangular(n)) cout<<"YES";
    else cout<<"NO";
    //solve();
}

bool isTriangular(int n)
{
        int a = sqrt(2*n) ;
        if(a == 0) return false;
        if(a*(a+1)/2 == n) return true;
        return false;
}

bool isSumOfTwoTriangular(int n)
{
    int lim = sqrt(n);
    int result;

    for(int i = 1; i <= lim; ++i)
    {
        result = i * (i+1)/2;

        if(isTriangular(n-result))
            return true;
    }

    return false;
}

