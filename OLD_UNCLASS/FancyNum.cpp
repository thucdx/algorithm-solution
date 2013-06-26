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

int n,k;
string orgin;
int f[10];
int dis[10005];
struct P
{
    int id;
    int val;
    P(){}
    bool operator<(const P &that) const{
        if(abs(val) != abs(that.val))
                return (abs(val) < abs(that.val));
        else
        //nhuong cai val>0 truoc
        if(val != that.val)
        {
            return val>0;
        }
        else  //= nhau <0
        {
            if(val < 0) // old <new
                 return id > that.id;
            else return id < that.id; //val >0 old >new
        }
    }

};
int main()
{
    //freopen("FancyNum.IN", "rt", stdin);
    //freopen("FancyNum.OUT", "wt", stdout);
    cin>>n>>k;
    cin>>orgin;
    set<int> s;
    int minDis=100000,pos;
    REP(i,0,9)
    {
        //tinh f[i]= min chuyen doi
        REP(j,0,n-1)
        {
            dis[j]=abs(orgin[j]-i-'0');
        }
        sort(dis,dis+n);
        REP(t,0,k-1)
        {
            f[i]+=dis[t];
        }
        //cout<<i<<" "<<f[i]<<endl;
        if(f[i]<minDis)
        {
            minDis=f[i];
            pos=i;
        }
    }
    cout<<minDis<<endl;
    REP(i,0,9)
        if(f[i]==minDis) s.insert(i);
    //cout<<pos<<endl;
    //return 0;
    //Viet so;
    string final_result="z";
    for(set<int>::iterator ite=s.begin(); ite!=s.end();ite++)
    {
        string result=orgin;
        pos=*ite;
        P pak[10005];
        REP(j,0,n-1)
        {
            pak[j].id=j;
            pak[j].val=orgin[j]-pos-'0';
        }
        sort(pak,pak+n);
        REP(t,0,k-1)
        {
        //f[i]+=dis[t];
            result[pak[t].id]=pos+'0';
        }
        if(result<final_result)
        final_result=result;
        //cout<<final_result<<" "<<pos<<endl;

    }
    cout<<final_result;

}

