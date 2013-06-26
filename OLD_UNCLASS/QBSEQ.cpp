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
int n,k,a[1005];
int f[1005][55];
int main()
{
    //freopen("QBSEQ.IN", "rt", stdin);
    //freopen("QBSEQ.OUT", "wt", stdout); 
    scanf("%d%d",&n,&k);
    REP(i,0,n-1)
    {
        scanf("%d",&a[i]);
        a[i]=(a[i]+k)%k;    
        //cout<<i<<" "<<a[i]<<endl;
    }
    f[0][a[0]]=1;
    REP(i,1,n-1)
    {
       REP(RM,0,k-1)
        {   
            f[i][RM]=f[i-1][RM];
        }
        REP(RM,0,k-1)
        {
            if(f[i-1][RM]!=0)
            {
                int remain=(RM+a[i])%k;
                int a=1+f[i-1][RM];
                f[i][remain]=max(a, f[i][remain]);
            }
        }    
    }
    cout<<f[n-1][0];              
}

