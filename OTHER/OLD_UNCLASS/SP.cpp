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
int a,b,c,s;
int f[205][205][205];
int curMoney,curGau;
void duyet(int x, int y, int z);
int main()
{
    freopen("SP.INP",  "rt", stdin);
    freopen("SP.OUT", "wt", stdout);
    cin>>a>>b>>c>>s;
    if(s>a+b*2+c*3) {cout<<0; return 0;}
    memset(f,-1,sizeof(f));
    f[0][0][0]=0;
    curMoney=0;
    curGau=0;
    duyet(0,0,0);
    cout<<f[a][b][c];
}
void duyet(int x, int y, int z)
{
    if(x==a && y==b && z==c) 
    {
        return ;
    }   
    int saveMn=curMoney, saveG=curGau;
    if(x<a)
    {
        curMoney=saveMn;
        curGau=saveG;
        curMoney++;
        if(curMoney>=s)
        {
            curMoney=0;
            curGau++;
        }
        f[x+1][y][z]=max(f[x+1][y][z],curGau);
        duyet(x+1,y,z);
    }
    if(y<b)
    {
        curMoney=saveMn;
        curGau=saveG;
        curMoney+=2;
        if(curMoney>=s)
        {
            curMoney=0;
            curGau++;
        }
        f[x][y+1][z]=max(f[x][y+1][z],curGau);
        duyet(x,y+1,z);
    }
    if(z<c)
    {
        curMoney=saveMn;
        curGau=saveG;
        curMoney+=3;
        if(curMoney>=s)
        {
            curMoney=0;
            curGau++;
        }
        f[x][y][z+1]=max(f[x][y][z+1],curGau);
        duyet(x,y,z+1);
    }
}
