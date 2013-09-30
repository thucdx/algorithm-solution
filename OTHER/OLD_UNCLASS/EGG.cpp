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
int f[1005][1005];
void init();
int main()
{
    //freopen("EGG.IN", "rt", stdin);
    //freopen("EGG.OUT", "wt", stdout);              
    init();
   // cout<<f[2][100]<<endl;
    int nTest,n,m;
    scanf("%d",&nTest);
    REP(i,1,nTest)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",f[n][m]);
    }
    
}
void init()
{
    REP(i,0,1000)
    {
        f[i][1]=1;        
        f[1][i]=i;
        f[i][0]=0;
        f[0][i]=0;
    }
    REP(i,2,1000)
    {
        REP(j,1,1000)
        {
            if(i>=10) f[i][j]=(int) (log(1.0 * j)/log(2.0)+1e-8) +1;
            else
            {   
                f[i][j]=1001;
                REP(k,1,j)
                {
                    f[i][j]=min(f[i][j], 1+ max(f[i-1][k-1],f[i][j-k]));    
                }    
            }    
        }    
    }
}

