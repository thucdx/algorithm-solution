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
string s;

int main()
{
    //freopen("MEO.IN", "rt", stdin);
    //freopen("MEO.OUT", "wt", stdout);              
    int n,k;
    scanf("%d%d\n", &n,&k);
    cin>>s;
    REP(j,1,k)
    {
    REP(i,0,n-1)
    {
        int j=(i+1)%n;
        if(s[i]!=s[j])
        {   
            char c=(char)('G'+'R'+'W'-s[i]-s[j]);
            s[i]=s[j]=c;    
        }    
    }
    }
    cout<<s;
}

