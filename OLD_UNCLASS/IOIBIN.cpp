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

int n;
int f[10005];
int main()
{
    //freopen("IOIBIN.IN", "rt", stdin);
    //freopen("IOIBIN.OUT", "wt", stdout);              
    scanf("%d",&n);
    int a,b,c;
    REP(i,1,n)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(c==1)
        {
            f[b]=f[a]+b-a;    
        } 
        else if(c==2)
        {
            if(f[b]-f[a]==b-a) cout<<"1"<<endl;
            else cout<<"0"<<endl;    
        }   
    }
}

