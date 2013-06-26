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

double EPS=1e-9;

int sumcs(int n);
void solve(int n);
bool check(int n);
int main()
{
    //freopen("DigitalPrime.IN", "rt", stdin);
    //freopen("ANS.OUT", "wt", stdout);              
    int n;
    //bool first=true;
    while(scanf("%d",&n)==1 && n!=0)
    {
        //if(first) first=false;
        solve(n);    
        cout<<endl;
    }
    //getch();
}
int sumcs(int n)
{
    int rs=0;
    while(n!=0)
    {
        rs+=n%10;
        n/=10;    
    }    
    return rs;
}
bool check(int n)
{
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0) return false;
    int lim=sqrt(n)+1;
    for(int i=3;i<=lim;i+=2)
    {
        if(n%i==0) return false;    
    }
    return true;
}


void solve(int n){
    int save=n;
    while(check(n)==false && n>=10)
    {
        n=sumcs(n);    
    }    
    if(check(n)==true)
    {
        printf("%7d %7d",save,n);
    }
    else printf("%7d    none",save);
        
}
