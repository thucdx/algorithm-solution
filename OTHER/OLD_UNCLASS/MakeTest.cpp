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
struct P{
    int x,y;
    P(){}
    P(int _x, int _y)
    {
        x=_x; 
        y=_y;    
    }
    P(const P& that){
        x=that.x;
        y=that.y;
    }
    bool operator<(const P&  that) const
    {
        return x< that.x;    
    }
    bool operator>(const P& that) const
    {
        return x>that.x;
    }
    bool operator==(const P& that) const
    {
        return ((x==that.x) && (y==that.y));    
    }
};
int main()
{
    freopen("KMIX.IN", "wt", stdout);
    srand(time(NULL));
    int n,m,a,b;
    n=100000;
    m=100000;
    cout<<n<<endl;
    REP(i,1,n)
    {
        a=rand()%(int)1e8+100;
        b=rand()%(int)1e8+100;
        cout<<a<<" "<<b<<endl;
    }
    cout<<m<<endl;
    REP(i,1,n)
    {
        a=rand()%(int)1e8+100;
        b=rand()%(int)1e8+100;
        cout<<a<<" "<<b<<endl;
    }
    
}

