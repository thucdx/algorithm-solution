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
#define FOR(i,a) REP(i,0,a)

#define pb  push_back
#define ins insert
#define all(x) begin(x), end(x)
#define sz(x) size(x)
#define ms(arr,val) memset(arr, val, sizeof(arr))

#define INF 1000000000
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>

string suite = "SDHC";
string value = "23456789TJQKA";

inline string toCard(int number)
{        
    string rs = "12";
    rs[1] = suite[number % 4];
    rs[0] = value[(number - number %4)/4];
    return rs;
}

inline int toNumber(string card)
{
    int s, v;
    for(s = 0; s < suite.length(); s++)
    {
        if(suite[s] == card[1])
            break;
    }
    
    for(v = 0; v < value.length(); v++)
    {
        if(value[v] == card[0])
            break;
    }    
    return v * 4 + s;
}

inline bool canGroup(int a, int b)
{
    return (a % 4 == b % 4) || (a / 4 == b /4 );
}

int n;

vector<int> card;
int currentSize ;

bool disable[55];

bool go(int n);

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    
    cin >> n;
    string c;
    memset(disable, 0, sizeof(disable));    
    card.resize(n);
    
    REP(i,1,n)
    {
        cin >> c;        
        card[i-1] = toNumber(c);        
    }    
        
    bool possible = go(n);    
    if(possible) cout <<"YES";
    else cout <<"NO";
}
