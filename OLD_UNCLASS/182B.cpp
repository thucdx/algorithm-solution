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

int d,n;
vector<int> day;

int main()
{
    cin>>d>>n;

    int days;
    REP(i,1,n){
        cin>>days;
        day.push_back(days);
    }

    int result = 0;

    REP(i,1,n-1){
        result += d+1-day[i-1]-1;
    }
    cout<<result;
}
