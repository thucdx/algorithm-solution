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
#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define is insert
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>
//ham
template <class T>  //so ko am
T gcd(T a, T b){if(b==0) return abs(a); else return gcd(b,a%b);}
template <class T>  
T lcm(T a, T b){ return a/gcd(a,b) *b;}
#define MAX 920092009
bool isPrime[MAX+5];
void init();
int d(int i);
int main()
{
    //freopen("CTNEWS.IN", "rt", stdin);
    freopen("RS.OUT", "wt", stdout);  
    int dmax=-1,pos;
    //REP(i,1,10)
//    {
//        cout<<i<<" "<<d(i)<<endl;    
//    }
//    return 0;
    REP(i,1,999)
    {
        int dd=d(i);
        if(dd>dmax)
        {
            dmax=dd;
            pos=i;
        }
    }
    cout<<pos<<" "<<"do dai: "<<dmax;
        
}
int d(int n)
{
    set<int> s;
    vector <int> store;
    int count=0;
    int k=1;
    while(!s.count(k)) //khong co
    {
        s.is(k);
        store.pb(k);
        int tmp=k;
        if (tmp==0) return 0;
        while(tmp<n) tmp*=10;
        k=tmp%n;
    }
    REP(i,0,store.size()-1)
    {
        if(store[i]==k)
        {
            return (store.size()- i);    
        }    
    }
}

void init()
{
    memset(isPrime, true, sizeof(isPrime));
    int lim=sqrt(MAX)+1;
    REP(i,2,lim)
    {
        if(isPrime[i])
        {
            int j=i*i;
            while(j<=MAX)
            {
                isPrime[j]=false;
                j+=i;    
            }    
        }    
    }    
}
