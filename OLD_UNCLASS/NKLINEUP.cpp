#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
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
//ham
#define MAX 50000
template <class T>  //so ko am
T gcd(T a, T b){if(b==0) return abs(a); else return gcd(b,a%b);}
template <class T>  
T lcm(T a, T b){ return a/gcd(a,b) *b;}
double EPS=1e-9;
int tMax[MAX*4], tMin[MAX*4];
void update(int k, int l, int r, int i,int val);
void get(int k, int l, int r, int i, int j ); //cof=1 max, cof=-1 min
int n,q;
int resMax, resMin;
int main()
{
    //freopen("NKLINEUP.IN", "rt", stdin);
    //freopen("NKLINEUP.OUT", "wt", stdout);              
    scanf("%d %d",&n,&q);
    int hei;
    int low,hig;
    REP(i,1,n)
    {
        scanf("%d",&hei);
        update(1,1,n,i,hei);    
    }
    int i=1;
    REP(i,1,q)
    {
        scanf("%d%d",&low,&hig);
        resMax=-1;
        resMin=1000001;
        get(1,1,n,low,hig);
        printf("%d\n",resMax-resMin);    
    }
}
void update(int k, int l, int r , int i,int val)
{
    
    if(l>i || r<i) return;
    if(l==r)
    {
        tMax[k]=val;
        tMin[k]=val;
        return ;   
    }    
    int mid=(l+r)/2;
    
    update(2*k,l,mid,i,val);
    update(2*k+1,mid+1,r,i,val);
    
    tMax[k]=max(tMax[2*k],tMax[2*k+1]);
    tMin[k]=min(tMin[2*k],tMin[2*k+1]);
}

void get(int k, int l, int r, int u,int v)
{
    if(l>v || r<u)
    {
        return ;    
    }
    if(u<=l && r<=v)
    {
        resMax=max(resMax,tMax[k]);    
        resMin=min(resMin,tMin[k]);    
        return ;
    }
    int mid=(l+r)/2;
    get(2*k, l    ,mid, u,v);
    get(2*k+1, mid+1, r , u,v);        
}
