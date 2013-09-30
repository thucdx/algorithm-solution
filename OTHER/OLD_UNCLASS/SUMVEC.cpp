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

#define INF 100000000
typedef long long LL;
typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<pair<int, int> > VII;

struct vec{
       int x;
       int y;
};
vec vt[15005];
int type(vec a)
{
 if(a.x>=0 && a.y>=0) return 1;
 if(a.x<=0 && a.y<=0) return 3;
 if(a.x>0) return 4;
 return 2;
}
int cmp(const void * va, const void * vb)
{
     vec *a=(vec*) va;
     vec *b=(vec *)vb;
     int t1=type(*a),t2=type(*b);
     if(t1!=t2) return (t1-t2);
     //bang nhau
     double val1,val2;
      val1=(a->x==0? INF: a->y/a->x);    
      val2=(b->x==0 ? INF: b->y/b->x); 
     if(val1-val2>0) return 1;
     if(val1-val2==0) return 0;
     return -1;
     
}

int n;

int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
    cin>>n;
    FOR(i,0,n-1)
    {
         cin>>vt[i].x>>vt[i].y;     
    }	
    qsort(vt,n,sizeof(vt[0]),cmp);
    FOR(i,0,n-1)
    {
     cout<<vt[i].x<<" "<<vt[i].y<<endl;            
    }
    int rs=-1;
    vec tmp;
    FOR(i,0,n-1)
    {   tmp.x=0;tmp.y=0;      
        FOR(j,i,n-1)
        {
           tmp.x+=vt[j].x;
           tmp.y+=vt[j].y;
           int t=tmp.x*tmp.x+tmp.y*tmp.y;
           cout<<i<<' '<<j<<" "<<tmp.x<<" "<<tmp.y<<" "<<t<<endl;
           if(t>rs)
           {
               rs=t;               
               //cout<<i<<" "<<j<<endl;
           }
        }
    }
    cout<<rs;
}
