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

map<string, int > m ;
string s;
int n,k;
bool check(int mid);
int main()
{
    //freopen("DTKSUB.IN", "rt", stdin);
    //freopen("DTKSUB.OUT", "wt", stdout);
    scanf("%d%d", &n, &k);
    cin>>s;
    //cout<<s<<endl;
    int low=1,high=n;
    bool isOk;
    while(low<high-1)
    {
        int mid=(low+high)/2;
        cout<<"CHECK "<<mid<<" ";
        isOk=check(mid);
        cout<<isOk<<endl;
        if(isOk) //chua lon hon hoac bang k.
        {
            low=mid;
        }
        else
        {
            high=mid-1;
        }
    }
    if(check(high))
            printf("%d",high);
    else if(check(low))
            printf("%d",low);
    else
        printf("0");
    return 0;
}
bool check(int mid)
{
    m.clear();
    int maxRepeat=0,cur;
    int len=s.length();
    REP(i,0,len-mid)
    {
        cur= ++m[s.substr(i,mid)] ;
        if(cur>maxRepeat)
        {
            maxRepeat=cur;
            if(maxRepeat>=k) return true;
        }
    }
    if(maxRepeat>=k) return true;
    return false;
}

