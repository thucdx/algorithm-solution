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

//char *s;
string s;
bool f[1005][1005];
int kq;
int main()
{
    //freopen("NKSP.IN", "rt", stdin);
    //freopen("NKSP.OUT", "wt", stdout);              
    cin>>s;
    //cout<<s<<endl;
    
    int len=s.length();
    memset(f,false,sizeof(f));
    REP(i,0,len-1)
        f[i][i]=true;
    REP(i,0,len-2)
    {
        if(s[i]==s[i+1]) f[i][i+1]=true;
    }
    REP(i,2,len-1)
    {
        REP(j,0,len-1-i)
        {
            if(s[j]==s[j+i])
            {
                f[j][j+i]=f[j+1][i+j-1];    
            }   
        }    
    }
    
    REP(i,0,len-1) f[i][i]=false;
    
    REP(i,1,len-1)
    DOWN(j,i-1,0)
    REP(u,j,i-1)
        if (f[j][u]&& f[u+1][i])
        {
            f[j][i]=true;
            break;    
        }
    REP(i,0,len-1)
    {
        REP(j,i+1,len-1)
        {
            kq+=f[i][j];
            //if(f[i][j])
            //cout<<i<<" "<<j<<endl;
        }
    }
    cout<<kq;

}

