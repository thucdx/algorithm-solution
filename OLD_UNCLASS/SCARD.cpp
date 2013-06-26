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
long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}
vector <long long> key;
vector < vector<long long> > room;
bool check(vector<long long> mau, vector<long long> tu);

int main()
{
    freopen("SCARD.INP",  "rt", stdin);
    freopen("SCARD.OUT", "wt", stdout);
    int n,k;
    scanf("%d %d",&n,&k);
    //cout<<n<<" "<<k<<endl;
    room.resize(k);
    long long a;
    REP(i,0,n-1)
    {
        scanf("%lld",&a );
        key.push_back(a);
    }
    REP(i,0,k-1)
    {
        long long a;
        REP(j,0,n-1)
        {
            scanf("%lld",&a);
            room[i].push_back(a);    
        }    
    }
    vector<int> rs;
    REP(i,0,k-1)
    {
        if(check(room[i],key))
            rs.push_back(i+1);    
    }
    int rss=rs.size();
    cout<<rss<<endl;
    if(rss>=1)
    {
        REP(i,1,rss)
        {
            cout<<rs[i-1];
            if(i!=rss) printf(" ");
        }    
    }
}
bool check(vector <long long> mau, vector<long long> tu) //kiem tra tich tu chia het cho mau ko.
{

    int smau=mau.size(), stu=tu.size();
    for(int i=0;i<smau;i++)
    {
         for(int j=0;j<stu;j++)
         {
            long long a=gcd(mau[i],tu[j]);
            mau[i]/=a;  
            tu[j]/=a;         
         }
//         cout<<i<<" "<<mau[i]<<endl;   
         if(mau[i]!=1) return false;
    }
    return true;        
}
    
