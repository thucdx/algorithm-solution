#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>
#define MAX 1000000
#define isNotPrime(n) (mark[n/31] & (1<<(n%31)))
#define set(n) { mark[n/31] |=(1<<(n%31));}
int mark[166666];
bool p[1001];
vector<int> prime;
int val[MAX+5];
void init();
int len;
inline int soUoc(int n);
inline bool isPrime(int i)
{
    if (i==2) return true;
    return (i%2 && !isNotPrime(i/2));
}
void sieve();
int n;
int main()
{
    freopen("PAIRS.INP",  "rt", stdin);
    freopen("PAIRS.OUT", "wt", stdout);
    init();
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",val[n]);    
    }
}
void sieve()
{
    int lim=sqrt(MAX)+1;
    int j;
    set(0);
    for(int i=3;i<=lim;i+=2)
    {
        if(!isNotPrime(i/2))
        {
            for(j=i*i;j<=MAX;j+=2*i)
                set(j/2);          
        }   
    }
}
void init()
{
    sieve();
    memset(p,false,sizeof(p));
    REP(i,2,1001)
        p[i]=isPrime(i);
    REP(i,2,1001)
    {
        if(p[i])
            prime.push_back(i);    
    }
    len=prime.size();
    val[1]=1;
    val[2]=2;
    for(int i=2;i<=MAX;++i)
    {
        if(isPrime(i))
        {
            val[i]=2;    
        }    
        else
        {
            val[i]=soUoc(i);   
        }
    }
}
int soUoc(int n)
{
    REP(i,0,len-1)
    {
        if(n%prime[i]==0)
        {   
            int cnt=0;
            int tmp=1;
            bool tt=true;
            int save=n;
            
            int pi=prime[i];
            while(n%pi==0)
            {
                n/=pi;    
                tmp*=pi;
                cnt++;
            }
            return ((cnt+1)* val[save/tmp]);    
        }
    }        
}
