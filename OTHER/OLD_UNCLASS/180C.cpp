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
int len;
string s;
int low,up;
int f[100005]; //f[i]= so buoc de tu i-1 tro ve truoc toan U, i=> sau toan lower
inline bool isLower(char c);
void solve();
int main()
{
    //freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    cin>>s;
    solve();
}
bool isLower(char c)
{
    return 'a'<=c && c<='z';
}
void solve()
{
    len= s.length();
    
    low=0;
    up=0;
    
    REP(i,0,len-1)
    {
        if(isLower(s[i])) low++;
        else up++;
    }
    
    int lowLeft=0, upLeft=0;
    
    int result=INF;
    
    REP(i,0,len-1)
    {
        //doi tat ca low trai=> up, up phari => trai
        f[i]=lowLeft+ up- upLeft;
        
        if(isLower(s[i]))
        {
            lowLeft++;
            //f[i]--;
        }
        else //chu hoa
        {
            upLeft++;
            //f[i]++;
        }
        
        //cout<<i<<" "<<f[i]<<endl;
        if (f[i] < result)
            result = f[i];
    }
    f[len] = low;
    if( f[len] <result) result= f[len];
    
    cout<<result;
}
    
