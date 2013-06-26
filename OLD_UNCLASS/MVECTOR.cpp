#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FIT(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int) (c).size()
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define SET(a, x) memset(a, x, sizeof(a));

typedef long long LL;
typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<pair<int, int> > VII;


struct point{
     long long x,y;
     point(){}
     point(long long _x,long long _y)
     {
      x=_x;y=_y;          
     }
      point operator+(point b)
      {
            point rs;
            rs.x=x+b.x;
            rs.y=y+b.y;
            return rs;     
      }
      point operator-(point b)
      {
          point rs;
          rs.x=x-b.x;
          rs.y=y-b.y;
          return rs;   
      }
     
     void operator=(point b)
     {
      x=b.x;y=b.y;     
     }              
};

double theta(point);
int cmp(const void * , const void*);
long long w(point);
point p[30005];
point ite;
int n;
long long maxW;
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	cin>>n;
	FOR(i,0,n-1)
	{
                cin>>p[i].x>>p[i].y;
    }
    qsort(p,n,sizeof(p[0]),cmp);
    int i,j;
    j=0;
    ite.x=0;ite.y=0;
    
    while(w(ite) < w(ite+p[j]))
    {
     ite=ite+p[j%n];             
     j=(j+1)%n;
    }
    if(maxW<w(ite)) maxW=w(ite);
    
    FOR(i,1,n-1)
    {
     ite=ite-p[i-1];
     while(w(ite)< w(ite+p[j]))
     {
      ite=ite+p[j];
      j=(j+1)%n;    
     }
     if(maxW<w(ite)) maxW=w(ite);
    }
    cout<<maxW;
    return 0;
    
}

double theta(point a)
{
    double t;
    if (a.x==0 && a.y==0) t=0;
    else t=a.y/(fabs(a.x)+fabs(a.y));
    if (a.x<0) t=2-t;
    else if (a.y<0) t=4+t;
    return t*90;  
}
int cmp(const void *a, const void *b)
{
    point *_a=(point *) a;
    point *_b= (point *) b;
    double rs= theta(*_a)- theta(*_b);
    if(rs>0) return 1;
    if(rs<0) return -1;
    return 0;  
}
long long w(point a)
{
 return (a.x*a.x+ a.y*a.y);
}
