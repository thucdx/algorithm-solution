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
long long a[30005];
long long m[30005]; //m[i] la so nho nhat ma day con tang ,phan tu cuoi cung la m[i], do dai i
int main()
{
    //freopen("LIS.IN", "rt", stdin);
    //freopen("LIS.OUT", "wt", stdout);              
    scanf("%d",&n);
    REP(i,0,n) m[i]=500000;
    REP(i,0,n-1) scanf("%lld",&a[i]);
    int dis;
    m[1]=a[0];
    dis=1;

    REP(i,1,n-1)
    {
        int first=1,last=dis;
        while(last-1>first)
        {
            int mid=(first+last)/2;
            if(m[mid]<a[i])
                first=mid;
            else  //m[mid]>=a[i]
            {
                last=mid-1;    
            } 
        }
        if(m[last]<a[i]) first=last;
        if(m[first]<a[i])
        { 
            m[first+1]=min(m[first+1],a[i]);
            if(first+1>dis) dis=first+1;   
        }
        else //m[first]>=a[i]; 
            m[1]=min(m[1],a[i]); 
    }
    cout<<dis;
    
}

