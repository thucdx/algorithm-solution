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

double eps = 1e-10;
double dis(double xa, double ya, double xb, double yb)
{
    double dx = (xa - xb);
    double dy = (ya - yb);
    
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    int xa, ya, ra;
    int xb, yb, rb;
    string s;
    //freopen("input.txt", "rt", stdin);
    cin>>xa>>ya>>ra;
    cin>>xb>>yb>>rb;
    
    double disx = dis(xa,ya,xb,yb);
    double result ;

    double maxR = max(ra,rb);
    double minR = min(ra,rb);
    
    if(disx >= ra + rb)  // khong cat nhau
    {
        result = (disx - ra - rb)/2;
    }
    else if( maxR <= disx) //cat nhau
    {
        result = 0;
    }
    else  //disx <  maxR
        if(minR + disx >= maxR)
    {
        result = 0;
    }
    else // chua hoan toan
    {
        result = (maxR - minR - disx)/2;
    }
    
    printf("%.7lf",result);
    //getch();
}
