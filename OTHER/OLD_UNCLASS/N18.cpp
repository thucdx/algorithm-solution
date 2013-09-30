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

int sumcs(long long a)
{
    int rs=0;
    while(a!=0)    {
        rs+=a%10;
        a/=10;   
    }
    return rs;
}
bool isPrime(int n)
{
for(int i=3;i*i<=n;i++)
    {
        if(n%i==0)
        {   cout<<i<<endl;
             return false;    
            }
    }
    return true;
}
int main()
{
//    freopen("?.IN", "rt", stdin);
    freopen("ANS.OUT", "wt", stdout);   
    cout<<isPrime(241);
    return 0;  
    long long n=0;
    while(true)
    {
        n+=2009;
        if(sumcs(n)==2009){ cout<<n; break;}
    }         
    
}

