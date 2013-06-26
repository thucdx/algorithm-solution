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


struct Point{
    int x,y;
};

bool isUp(char c){
    return  (c>='A' && c <='Z');
}

VI upLeft,downLeft;
VI f;
int up;
string s;
void solve();

int main()
{
    freopen("input.txt",  "rt", stdin);
    cin>>s;
    solve();

}

void solve()
{
    int len = s.length();
    int result = INF;
    up=0;

    REP(i,0,len-1){
        if(isUp(s[i]))
        {
            ++up;
        }
        upLeft.push_back(up);
    }

    result = len-up;

    REP(i,0,len-1){
        int fi = (i+1-upLeft[i])+ (up -upLeft[i]);
        if(fi < result) result = fi;
    }

    if(up <result) result = up;

    cout<<result;

}
