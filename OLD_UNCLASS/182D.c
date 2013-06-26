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
string s1,s2;
void solve();
inline bool isOK(string s, int lenth);

int main()
{
    freopen("input.txt",  "rt", stdin);
    freopen("output.txt", "wt", stdout);
    cin>>s1>>s2;
    solve();
}

void solve()
{
    int len1 = s1.length();
    int len2 = s2.length();
    int lim = min(len1, len2);
    int result = 0;

    for(int i=1 ;i <= lim ; ++i){
        if(len1 % i != 0 || len2 % i !=0) continue;
        //len1 %i =0 , len2 % i = 0
        if(isOk(s1 , i) && isOK(s2 , i))
            result ++;
    }

    cout<<result;
}

bool isOK(string s, in l)
{
    int len = s.length();

    for(int i=l; i<len ; i++){
        if(s[i] != s[i-l]) return false;
    }

    return true;
}


