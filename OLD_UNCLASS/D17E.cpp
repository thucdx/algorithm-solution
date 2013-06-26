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

long long mu[65];
void init();

int main()
{
//   freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
        
    long long G,T,A,D,X,Y;
    init();
    do
    {
//        scanf("%lld%lld%lld%lld",&G,&T,&A,&D);
        cin >> G >> T >> A >> D;
        
        if ( G == -1 && T == -1 && A == -1 && D == -1)
            break;
        
        long long firstRound = 0;
        long long teamsToSecondRound = 0;
        
        firstRound = G * T * (T-1)/2;
        teamsToSecondRound = G * A + D;
        
        long long nTeam = 1;
        int i = 0;
        while(nTeam < teamsToSecondRound)
        {
            i++; 
            nTeam = mu[i];  
        }
        
        long long moreTeam = nTeam - teamsToSecondRound;
        cout<<G<<"*"<<A<<"/"<<T<<"+"<<D<<"="<<firstRound+ nTeam-1<<"+"<<moreTeam<<endl;
        //printf("%lld*%lld/%lld+%lld=%lld+%lld\n",G,A,T,D,firstRound + nTeam -1 , moreTeam);                 
    }
    while(true);
}
void init()
{
    mu[0]=1;
    REP(i,1,60)
    {
        mu[i] = 2 * mu[i-1];    
    }        
}
