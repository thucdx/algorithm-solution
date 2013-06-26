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

int solve(string s);
int main()
{
    freopen("input.txt",  "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int nTest;
    cin>>nTest;
    string s;
    getline(cin,s);    
    for(int i=1;i<=nTest;i++)
    {
        cout<<"Case #"<<i<<": ";
        getline(cin,s);    
//        cout<<s<<endl;
        cout<<solve(s)<<endl;
    }
}
int solve(string s)
{
    int cnt[256];
    memset(cnt, 0, sizeof(cnt));
    string pat="HACKERCUP";
    for(int i=0;i<s.length();i++)
    {
        cnt[s[i]]++;    
    }
    int val=9999999;
    for(int i=0;i<pat.length();i++)
    {
        val=min(val, cnt[pat[i]]); 
    }
    return val;
}
    
