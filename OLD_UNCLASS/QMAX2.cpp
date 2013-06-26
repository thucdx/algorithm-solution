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
#define MAX 50000
int f[MAX+5];
int val[MAX*4],queryResult,n,q;
void update(int k,int u,int v, int i);
void get(int k, int u, int v, int low, int high);

int main()
{
    //freopen("QMAX.IN", "rt", stdin);
    //freopen("QMAX.OUT", "wt", stdout);  
    memset(val,0,sizeof(val));
    scanf("%d%d",&n,&q);
    int lowInt, higInt;
    int k;
    REP(i,1,q)
    {
        scanf("%d%d%d",&lowInt, &higInt,&k);  
        f[lowInt]+=k;
        f[higInt+1]-=k;
    }
    REP(i,1,n)
    {
        f[i]+=f[i-1];
        update(1,1,n,i);
    }
    int nQuestion;
    scanf("%d",&nQuestion);
    REP(i,1,nQuestion)
    {
        scanf("%d%d",&lowInt, &higInt);
        queryResult=-1;
        get(1,1,n,lowInt, higInt);
        printf("%d\n",queryResult);
    }
    
}
void update(int k,int u,int v, int i){
    if(v<i || u>i) return ;
    if(u==v)
    {
        val[k]=f[i];
        return ;    
    }
    int mid=(u+v)/2;
    update(k*2,u,mid,i);
    update(k*2+1, mid+1, v, i);
    val[k]=max(val[2*k], val[2*k+1]);
}
void get(int k, int u, int v, int low, int high)
{
    if(v<low || u>high) return ;
    if(low<=u && v<=high){
        queryResult=max(queryResult,val[k]);
        return;
    }
    int mid=(u+v)/2;
    get(2*k, u,mid, low, high);
    get(2*k+1, mid+1,v, low, high);
}

