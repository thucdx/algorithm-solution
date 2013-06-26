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

using namespace std;

#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);

#define pb  push_back
#define ins insert
#define all(x) begin(x), end(x)
#define sz(x) size(x)
#define ms(arr,val) memset(arr, val, sizeof(arr))

#define INF 1000000000
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>

int G,T,A,D;

void solve();

int main()
{
    freopen("E.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    
    do
    {
        cin>> G >> T >> A >> D;
        if(G == -1 && T == -1 && A == -1 && D == -1) break;
        solve();
    }    
    while(true);    
}

void solve()
{
    long long totalMatches = 0;
    long long moreTeam = 0;
    long long teamToSecondRound = 0;
    long long totalTeamInSecondRound = 1;
    
    totalMatches = (long long)G * T * (T-1) / 2;
    teamToSecondRound = (long long)G * A + D;
    
    while(totalTeamInSecondRound < teamToSecondRound)
    {
        totalTeamInSecondRound <<= 1;          
    }
    
    cout << G <<"*"<<A<<"/" << T <<"+" <<D <<"="<<(totalTeamInSecondRound -1 +totalMatches)<<"+"<<totalTeamInSecondRound - teamToSecondRound <<endl;    
}
