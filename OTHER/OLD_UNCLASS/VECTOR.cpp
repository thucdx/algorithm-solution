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

struct vt
{
 int x,y;
 vt operator+(vt b)
 {
  vt rs;
  rs.x= x+b.x;
  rs.y= y+b.y;    
  return rs;           
 }       
};
vt l[35];
vt f;
int n;
int lft[3100][3100];
int makeL();
int makeR();
int result;
void calc();
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	cin>>n;
	FOR(i,0,n-1)
	cin>>l[i].x>>l[i].y;
	cin>>f.x>>f.y;
	calc();
}
void calc()
{
 makeL();
 makeR();     
 cout<<result<<endl;
}
int makeL() //nua dau 1->n/2
{
     int lim=(1<<(n/2))-1;
     FOR(i,0,lim)
     {
      vt sum;            
      sum.x=0;sum.y=0;
      FOR(j,0,n/2-1)
      {
       if((i &(1<<j))!=0) sum=sum+l[j];              
      }
      lft[sum.x+1500][sum.y+1500]++;
      /*
      cout<<i<<endl;
      cout<<sum.x<<" "<<sum.y<<endl;
      */
     }   
}
int makeR()
{   
    int lim=(1<<(n-n/2))-1;
    FOR(i,0,lim)
     {
      vt sum;            
      sum.x=0;sum.y=0;
      FOR(j,0,(n-n/2)-1)
      {
       if((i &(1<<j))!=0) sum=sum+l[j+n/2];              
      }
      /*
      cout<<sum.x<<" "<<sum.y<<endl;
      */
      result+=lft[f.x-sum.x+1500][f.y-sum.y+1500];
     }    
}
