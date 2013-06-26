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
int n,k,a[100005],b[100005],cnt[100005];
long long sum;
void solve();
bool check(int r);
int main()
{
    //freopen("RIDDLE.IN", "rt", stdin);
    //freopen("RIDDLE.OUT", "wt", stdout);    
    int nTest;
    scanf("%d",&nTest);
    REP(i,1,nTest)
    {
        scanf("%d%d",&n,&k);
        REP(j,0,n-1)
        {
            scanf("%d",&a[j]);    
        }   
        solve();    
    }          
}
bool check(int r)
{
    REP(i,0,r-1) b[i]=a[i];
    sort(b,b+r);
    sum=0;
    REP(i,0,r-1)
    {
        if(b[i]>sum+1) return false;
        sum +=(long long)b[i];    
    }
    if(sum>=k) return true;
    return false;
        
}
bool check2(int r)
{   //cout<<"r= "<<r<<endl;
    memset(cnt,0,sizeof(cnt));
    REP(i,0,r-1)
        cnt[a[i]]++;
    int run=0;
    REP(i,1,100000)
    {
        REP(j,0,cnt[i]-1)
        {
            b[run++]=i;
        }    
    }
    sum=0;
    //REP(i,0,r-1) cout<<i<<" "<<b[i]<<endl;
    REP(i,0,r-1)
    {
        if(b[i]>sum+1) return false;
        sum +=(long long)b[i];    
       // cout<<i<<" : "<<sum<<endl;
    }
    //cout<<"__ ___"<<endl;
    if(sum>=k) return true;
    return false;
        
}
void solve()
{
    
    int first=1,last=n;
    while(first<last)
    {
        int mid=(first+last)/2;
        //cout<<first<<" "<<mid<<" "<<last<<endl;
        //cout<<mid<<" kq check"<<check(mid)<<endl;
        if(check(mid))
        {
            last=mid;    
        }    
        else
            first=mid+1;
    }
    if(check(first)) cout<<first<<endl;
        else if(check(last)) cout<<last<<endl;
        else 
            cout<<"-1"<<endl;
}

