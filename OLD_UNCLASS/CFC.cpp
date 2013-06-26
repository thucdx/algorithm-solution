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

long long f[35][35];
void init();
int n,m,t;
long long rs=0;
int main()
{
   // freopen("input.txt",  "rt", stdin);
   // freopen("output.txt",  "wt", stdout);
    init();
    cin>>n>>m>>t;
    REP(i,4,n)
    {
        int j=t-i;
        if(j<=m && j>=1)
        {
            rs+= f[i][n] * f[j][m];
        }
    }
    cout<<rs;
    
}
void init()
{
    f[0][0]=1;
    REP(i,0,30){ 
        f[0][i]=1; f[i][i]=1;
    }
    REP(i,1,30)
    {
        REP(j,1,i)
        {
            f[j][i]=f[j][i-1]+f[j-1][i-1];    
            //cout<<j<<" "<<i<<" "<<f[j][i]<<endl;
        }
//        cout<<endl;
    }   
}
    
