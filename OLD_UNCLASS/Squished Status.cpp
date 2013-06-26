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
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>
#define MOD  4207849484
long long f[1005];
long long solve(int m, string s);
int main()
{
    //freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int nTest,m;
    string status;
    cin>>nTest;
    REP(i,1,nTest)
    {
        cin>>m>>status;
        cout<<"Case #"<<i<<": "<<solve(m,status)<<endl;
    }
}
    
long long solve(int m, string s)
{
    //cout<<m<<" "<<s<<endl;
    memset(f,0,sizeof(f));
    int l=s.length();
    f[l]=1;
    int num=s[l-1]-'0';
    if(num<=m && num>=1) f[l-1]=1;  
    for(int i=l-2;i>=0;i--)
    {
        if(s[i]=='0') {f[i]=0;continue;}
        num=s[i]-'0';
        if(num<=m && num>=1) f[i]=(f[i]+f[i+1])%MOD; 
        if(i+1<=l-1)
        {
            num=num*10+s[i+1]-'0';
            if(num<=m && num>=1) f[i]=(f[i]+f[i+2])%MOD; 
        }
        if(i+2<=l-1)
        {
            num=num*10+s[i+2]-'0';
            if(num<=m && num>=1) f[i]=(f[i]+f[i+3])%MOD;                 
        } 
    }
   //DOWN(i,l-1,0) cout<<i<<" "<<f[i]<<endl;
    return f[0];  
}
