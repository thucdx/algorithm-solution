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

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int n;
bool flag[610][610];
string b[610];
int nGreen, nRed;
void solve();
void backTrack(int a, int b);
int main()
{
    //freopen("OilSkimming.IN", "rt", stdin);
    //freopen("OilSkimming.OUT", "wt", stdout);              
    int nTest;
    scanf("%d",&nTest);
    REP(i,1,nTest)
    {   
        memset(flag,false, sizeof(flag));
        scanf("%d",&n);
        REP(j,0,n-1)
        {   b[j]="";
            cin>>b[j];
        }
        cout<<"Case "<<i<<": ";
        solve();
        if(i!=nTest) cout<<endl;
    }   
}
void backTrack(int p, int q)
{  
    //cout<<p<<" "<<q<<endl;
    int x, y;
    if(p<0 || p>=n  || q<0 || q>=n ) return ;
    if(flag[p][q]==true) return ;
    flag[p][q]=true;
    if((p+q)%2==0) nRed++;
    else nGreen++;
    REP(t,0,3)
    {
        x=p+dx[t];
        y=q+dy[t];
        if(0<=x && x<n && 0<=y && y<n)
        {
            if((b[x][y]=='#') && (flag[x][y]==false) )
                backTrack(x,y);
        }    
    }       
}
void solve()
{   
    int result=0;
    REP(i,0,n-1)
    {
        REP(j,0,n-1)
        {
        if(b[i][j]=='#' && flag[i][j]==false)
        {
            nGreen=0;
            nRed=0;
            //quay lui
            backTrack(i,j);
            result+=min(nRed,nGreen);
            //cout<<"Red :  Green"<<nRed<<" "<<nGreen<<endl;
        }     
        }
    }
    cout<<result;
        
}

