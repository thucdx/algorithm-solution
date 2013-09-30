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

char rs[20];
char a[100005][20];
char b[20];
bool cmp(char *a, char *b)
{
    bool rs=true;
    int ia=0,ib=0;
    do
    {
        if(a[ia]!=b[ib]) return false;
        ++ia;++ib;    
    }    
    while(a[ia]!='\0' && b[ib]!='\0');
    return true;
}
int n;
int main()
{
    //freopen("LTPMSEQ.IN", "rt", stdin);
   // freopen("LTPMSEQ.OUT", "wt", stdout);              
    scanf("%d",&n);
    int i,j;
    REP(i,0,19) rs[i]=0;
    for(int i=1;i<=n;++i)
    {
        scanf("%s",a[i-1]);
        //cout<<a<<endl;
        j=0;
        while(a[i-1][j]!='\0')
        {
            rs[j]^=a[i-1][j];    
            ++j;
        }    
    }
    //Check xem co ton tai ko.
    bool found=false;
    REP(i,0,n-1)
    {
        if(cmp(rs,a[i])) {found=true; break;}
    }   
    if(!found) cout<<"-1";
    else
    {
        i=0;
        while(rs[i]!='\0')
        {
            printf("%c",rs[i]);
        //if(cnt[rs[i]]&1==0) {cout<<"-1"; return 0;};
            i++;    
        }
    }   
}

