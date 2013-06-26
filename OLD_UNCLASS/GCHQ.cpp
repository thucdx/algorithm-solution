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
#define base 8
int getVal(char c)
{
    if('0'<=c && c<='9') return c-'0';
    return c-'a'+10;    
}
int main()
{
    freopen("input.txt",  "rt", stdin);
    freopen("output.txt", "wt", stdout);
    string s;
    int num;
    while(cin>>s)
    {
        cout<<s<<" "<<(char)(s[0]*base+s[1])<<" "<<endl;;
        
        
    }
}
    
