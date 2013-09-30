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

long long n;
long long calc(long long n);
int findN(long long n);
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
    int h,i,nTest;
    cin>>nTest;
    FOR(i,1,nTest)
    {
       cin>>n;
       if(n==0) {cout<<"0 1 1"<<endl;continue;}
       long long rs=calc(n);
       if(rs==0) cout<<"1 "<<findN(n);
       else cout<<"0 "<<rs<<" "<<findN(n+rs);
       cout<<endl;
    }     	
}
int findN(long long n)
// (k(k+1)/2)^2 = n;  k*(k+1)=2*can(n) => k^2+k-2*can(n). (-1+ sqrt(8*can(n)))/2
{
    long long can=sqrt(n);
    return (int)((-1+sqrt(1+8.0*can))/2.0);
}
long long calc(long long n)
{
     int less=findN(n);
     //cout<<"("<<n<<" "<<less<<")"<<endl;
     long long temp=less*(less+1)/2;
     if(temp*temp==n) return 0;
     else
     {
      long long l=n-temp*temp;
      temp=(less+1)*(less+2)/2;
      long long r=temp*temp-n;
      if(r>l) return -l;
      else return r;    
     }
}
