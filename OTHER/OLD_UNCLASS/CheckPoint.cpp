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
#define LIM  10000000
#define MAX 1000000000
int f[LIM+5];
int c[3200][3200];
void init();
int solve(int x);
bool isPrime(int a);
int main()
{
   // freopen("input.txt",  "rt", stdin);
   // freopen("output.txt", "wt", stdout);
    int nTest;
    init();
    cin>>nTest;
    REP(i,1,nTest)
    {   
        int x;
        cin>>x;
        cout<<"Case #"<<i<<": "<<solve(x)<<endl;
    }
}
void init()
{
    memset(f,-1,sizeof(f));
    REP(i,1,3200) 
    {   
        c[1][i]=1;
        c[0][i]=1;
        c[i][i]=1;
    }
    f[1]=1;
    REP(i,1,3200)
    REP(j,1,i-1)
    {
        c[j][i]=c[j][i-1] + c[j-1][i-1];
        if(c[j][i]>LIM || c[j][i]<0) break; //khong tinh doan nay nua.
        if(f[c[j][i]]==-1) f[c[j][i]]=i;
    }

    //cout<<j<<" "<<i<< "   "<<c[j][i]<<endl;
      
}
int solve(int x)
{
    int result=MAX;
    int bound=(int)sqrt(x+0.01);
    for(int i=2;i<=bound;i++)
    {
        if(x%i ==0)
        {
            if(f[i]!=-1 && f[x/i]!=-1)
            {
                result= min(result, f[i]+f[x/i]);   
            }    
        } 
    }
    result=min(result,x+1);
    return result;
}
bool isPrime(int a)
{
    if(a<=1) return false;
    if(a<=3) return true;
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0) return false;    
    }    
    return true;
}
    
