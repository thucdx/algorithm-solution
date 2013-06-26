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
template <class T>  //so ko am
T gcd(T a, T b){if(b==0) return abs(a); else return gcd(b,a%b);}
template <class T>  
T lcm(T a, T b){ return a/gcd(a,b) *b;}

double EPS=1e-9;
int n,x,y;
int a[25005],b[25005];
int main()
{
    //freopen("CTNEWS.IN", "rt", stdin);
    //freopen("CTNEWS.OUT", "wt", stdout);  
    scanf("%d%d%d",&n,&x,&y);
    REP(i,0,n-1)
    {
        scanf("%d%d",&a[i],&b[i]);    
    }
    sort(a,a+n);
    sort(b,b+n);
    long long rs=0;
    REP(i,0,n-1)
    {
        rs+= a[i]> b[i] ? (y*(a[i]-b[i])): (x* (b[i]-a[i]));
    }
    cout<<rs;
                
}

