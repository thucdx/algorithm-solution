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
//#include <conio.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>
#define REMAIN 100000007

long long f[50000];
int freq=2;
int base='z'-'a'+2;
int nghichDao;
bool check(int k);
string s;
long long mut(int a, int mu, int k);
void init();
int main()
{
    //freopen("DTKSUB.IN",  "rt", stdin);
   // freopen("STRING.IN" ,"rt", stdin);
    //freopen("STRING.OUT", "wt", stdout);
    int n;
    cin>>n>>freq>>s;
    init();
    int len=s.length();
    int low=1,hi=len;
    while(low<hi-1)
    {
        int mid=(low+hi)/2;
        if(check(mid))
        {
            low=mid;    
        }    
        else {
            hi=mid-1;
        }
    }
    if(check(hi)) cout<<hi<<endl;
    else if (check(low)) cout<<low<<endl;
    else cout<<"-1";
}
long long mut(int a, int mu, int k)
{
    if(mu==1) return a%k;
    if(mu==0) return 1;
    long long tmp=mut(a,mu/2,k);
    tmp=tmp*tmp%k;
    if(mu&1) tmp=tmp*a%k;
    return tmp;    
}
void init(){
    int len=s.length();
    f[0]=s[0]-'a'+1;
    REP(i,1,len-1)
    {
        f[i]=f[i-1]*base+s[i]-'a'+1;
        if(f[i]>REMAIN) f[i]=f[i]%REMAIN;
    }
}
bool check(int k)
{
    int len=s.length();
    multiset<long long > sll;
    REP(i,0,len-k)
    {
        //tinh gia tri tu i->i+k-1; len-k=>len-1;
        long long val;
        if(i==0) val=f[k-1];
        else 
        {
            val=(f[i+k-1]-f[i-1])%REMAIN; //val=*'z'-'a'+1)^(i-1)
            if(val<0) val=(val+REMAIN);
//            if(val>REMAIN) val-=REMAIN;
        }
        val=val*mut(base,len-i,REMAIN);
        val=val%REMAIN;
        sll.insert(val);
    }
    for(set<long long>::iterator it=sll.begin(); it!=sll.end();it++ )
    {
        if(sll.count(*it)>=freq) return true;    
    }
    return false;
}
    
