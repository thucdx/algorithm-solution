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
int n;
struct Point{
    int x,y;        
};
vector <Point> vp;
bool isCentral(Point p);
int main()
{
    //freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    //input    
    cin>>n;
    int x,y;
    int count=0;
    Point p;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d", & x, &y);
        p.x=x;
        p.y=y;
        vp.push_back(p);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(isCentral(vp[i-1]))
            count++;    
    }
    cout<<count;
       
}

bool isCentral(Point p)
{
    bool hasLeft=false, hasRight=false, hasUp=false, hasDown=false;
    
    for(int i=1;i<=n;i++)
    {
        Point tmp= vp[i-1];
        int _x=tmp.x, _y=tmp.y;
        if(_x==p.x)
        {
            if(_y>p.y) hasLeft=true;    
            else if(_y<p.y) hasRight=true;
        }
        if(_y==p.y){
            if(_x>p.x) hasUp=true;
            else if(_x<p.x) hasDown=true;
        }       
    }
    return (hasLeft && hasRight && hasUp && hasDown);        
}
    
