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

long long Calc(int n, int k);

int main()
{
 //   freopen("input.txt",  "rt", stdin);
  //  freopen("output.txt", "wt", stdout);
    long long low=1, hi=(int)(1e9+1), mid;
    
    long long n,k;
    
    cin>>n>>k;
    
    if(n<hi) hi=n;
    
    while(low<hi-1)
    {
        mid=(low+hi)/2;
        int val= Calc(mid, k);
        //cout<<low<<" "<<hi<<" "<<mid<<" "<<k<<" "<<val<<endl;
        if(val>=n)
            hi=mid;                
        else low=mid+1;
    }
    
    if(Calc(low,k) >=n ) cout<<low;
    else if(Calc(hi,k)>=n) cout<<hi;
    else cout<<"No";    
}

long long Calc(int n, int k)
{
    long long result=0;
    long long mu=1;
    while(mu<=n)
    {
        result+=(long long) (n/mu);
        //cout<<result<<" "<<(long long)(n/mu)<<endl;
        mu*=k;    
    }
    
    return result;            
}
    
