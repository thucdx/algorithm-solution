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

int n,a[100005],b[100005],l[100005],r[100005],m[100005],dis;
int main()
{             
    scanf("%d",&n);
    REP(i,0,n-1)
    {
        scanf("%d",&a[i]);
        b[n-1-i]=a[i];
    }
    //Tinh left
    REP(i,0,n) m[i]=100005; //fill;
    dis=1;
    m[1]=a[0];
    l[0]=1;
    REP(i,1,n-1)
    {
        if(m[1]>=a[i]) {
            l[i]=1;
            m[1]=a[i];
            continue;
        }
        if(m[dis]<a[i])
        {
            l[i]=dis+1;
            m[dis+1]=a[i];
            dis++;
            continue;
        }
        
        int first=1,last=dis;
        while(last-1>first)
        {
            int mid=(first+last)/2;
            if(m[mid]<a[i])
                first=mid;
            else  //m[mid]>=a[i]
            {
                last=mid;    
            } 
        }
        l[i]=last;
        m[last]=a[i];
        
    }
    REP(i,0,n) m[i]=100005; //fill;
    dis=1;
    m[1]=b[0];
    r[n-1]=1;
    REP(i,1,n-1)
    {
        if(m[1]>=b[i]) {
            r[n-1-i]=1;
            m[1]=b[i];
            continue;
        }
        if(m[dis]<b[i])
        {
            r[n-1-i]=dis+1;
            m[dis+1]=b[i];
            dis++;
            continue;
        }
        
        int first=1,last=dis;
        while(last-1>first)
        {
            int mid=(first+last)/2;
            if(m[mid]<b[i])
                first=mid;
            else  //m[mid]>=a[i]
            {
                last=mid;    
            } 
        }
        r[n-1-i]=last;
        m[last]=b[i];
        
    }

    int maxDis=-1;
    REP(i,0,n-1)
    {
        maxDis=max(maxDis,min(l[i],r[i]));    
    }
    
    if(maxDis==0) cout<<"0";
    else 
        cout<<2*maxDis-1;
}

