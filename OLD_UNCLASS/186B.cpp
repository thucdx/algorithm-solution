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
int n;
int t1, t2,k;
struct mushroom
{
    int id;
    int a,b;
    double mH;
    mushroom(){}
    mushroom(int _a,int _b)
    {
        a = _a;
        b = _b;
        maxHeight();
    }
    double maxHeight()
    {
        double rs1 = t1 * a *(1.0-k*1.0/100.0)+ t2 * b ;
        double rs2 = t1 * b * 1.0 *(1-k*1.0/100.0)+ t2 * a ;
       //cout<<"!!"<<t1<<" "<<t2<<" "<<a<<" "<<b<<" "<<rs1<<','<<rs2<<endl;
        mH = (rs1 > rs2)? rs1 : rs2;
        //cout<<mH<<endl;
        return mH;
    }
    bool operator<= (mushroom other){
        return mH <= other.mH;
    }
};

bool cmp(const mushroom & a,const mushroom & b)
{
    if (a.mH != b.mH)
        return a.mH > b.mH;
    else return a.id < b.id;

}
void solve();
vector<mushroom> ms;

int main()
{
    //freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    cin>>n>>t1>>t2>>k;
    //cout<<n<<t1<<t2<<k<<endl;
    int a,b;
    for(int i=1 ; i<=n; i++)
    {
        scanf("%d%d",&a,&b);
        mushroom mss;
        mss.a = a;
        mss.b = b;
        mss.id = i;
        mss.maxHeight();
        ms.push_back(mss);
    }

    sort(ms.begin(), ms.end(),cmp);
    for(int i=0 ;i< n;i++){
        printf("%d %.2lf\n",ms[i].id,ms[i].mH);
    }
}

void solve()
{

}

