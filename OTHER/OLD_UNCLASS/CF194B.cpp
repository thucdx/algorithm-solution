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

inline long long sol(int n);
int main()
{
    //freopen("input.txt",  "rt", stdin);
 //   freopen("output.txt", "wt", stdout);
    int ntest,n;
    cin>>ntest;

    REP(i,1,ntest)
    {
        cin>>n;
        cout<<sol(n)<<endl;
    }
}

long long sol(int n)
{
    //tim k de k*(n+1) chia het cho 4*n
    //ket qua la k+1
    if( n%2 == 0)
    {
        //(n+1) le
        return ((long long)n)*4 + 1;
    }
    else
    {
        if( (n+1)%4 == 0)
        {
            return ((long long)n) + 1;
        }
        else return ((long long)n)*2 + 1;
    }
}
