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
#define MAX 100000
int n,k;
string p,s;
long long f[30][100005],l[30][100005],r[30][100005];
bool isExist[30];
void init();
long long calc(int i, int j);
long long min(long long a, long long b)
{
    if(a<b) return a;
    return b;    
}
long long diff(string p);
int main()
{
    //freopen("INPUT.txt",  "rt", stdin);
    //freopen("OUTPUT.txt", "wt", stdout);
    cin>>k>>n;
    cin>>s;
    init();
    //cout<<s<<endl;
    REP(i,1,k)
    {
        cin>>p;
        //cout<<p<<endl;
        cout<<diff(p)<<endl;    
    }
}
long long diff(string p)
{
    long long ret=0;
    int len=p.length();
    REP(i,0,len-1)
    {
        int d=f[p[i]-'a'][i]; 
        if(d>=INF) d=len;
        ret+=d;
        //cout<<(char)p[i]<<" "<<d<<" "<<endl;
    }    
    return ret;
}
void init()
{
    int slen=s.length();
    memset(isExist,false, sizeof(isExist));
    REP(i,0,slen-1)
    {
        isExist[s[i]-'a']=true;
    } 
    REP(i,0,28)
    REP(j,0,MAX)
    {
        f[i][j]=INF;  
        l[i][j]=INF;
        r[i][j]=INF;
    }
    REP(i,0,'z'-'a')
    {
        if(s[0]==i+'a'){ f[i][0]=0; l[i][0]=0;r[i][0]=0;}
        REP(j,1,MAX)
        {   
            if(!isExist[i]) {l[i][j]=INF; continue;}
            if(j<n)
            {
                if(s[j]==i+'a') {l[i][j]=0; continue;}
            }
            l[i][j]=1+l[i][j-1];
            //if(i=='d'-'a' && j==10) cout<<i<<" "<<j<<" "<<l[i][j]<<endl;
            if(l[i][j]>INF) l[i][j]=INF;
        }   
        //if(i=='d'-'a') REP(j,0,10) cout<<i<<" "<<j<<" "<<l[i][j]<<endl; 
        DOWN(j,n-1,0)
        {
            if(!isExist[i]) {r[i][j]=INF; continue;}
            if(s[j]==i+'a') { r[i][j]=0; continue;}
            r[i][j]=1+r[i][j+1];
            if(r[i][j]>INF) r[i][j]=INF;
        }
        //if(i=='d'-'a') cout<<i<<" "<<10<<" "<<r[i][10]<<endl;
        REP(j,0,MAX)
        {
                f[i][j]=min(l[i][j],r[i][j]);
        }
        //if(i=='d'-'a') cout<<i<<" "<<10<<" "<<f[i][10]<<endl;
    }
}
long long calc(int i, int j)
{
    if(f[i][j]!=n) return f[i][j];    
    if(!isExist[i]) {f[i][j]=n;return n;}
    if(s[j]==i+'a') { f[i][j]=0;return 0;}
    long long rs=n+1;
    if(j>=1)
         rs=min(rs,1+calc(i,j-1));
    if(j+1<n) 
        rs=min(rs,1+calc(i,j+1));
    f[i][j]=rs;
    return rs;
}
