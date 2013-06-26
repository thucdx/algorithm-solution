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


int main()
{
    //freopen("LENA.IN", "rt", stdin);
    //freopen("LENA.OUT", "wt", stdout);              
    int n;
    scanf("%d",&n);
    REP(i,0,n)
    {
        //left
        for(int j=1;j<=2*(n-i);++j)
        cout<<" ";
        for(int j=0;j<i;j++)
        cout<<j<<" ";
        cout<<i;
        //Right
        for(int j=i-1;j>=0;--j)
        cout<<" "<<j; 
        cout<<endl;       
    }
    //Duoi
    DOWN(i,n-1,0)
    {
        //left
        for(int j=1;j<=2*(n-i);++j)
        cout<<" ";
        for(int j=0;j<i;j++)
        cout<<j<<" ";
        cout<<i;
        //Right
        for(int j=i-1;j>=0;--j)
        cout<<" "<<j; 
        if(i!=0)
        cout<<endl;   
            
    }
}

