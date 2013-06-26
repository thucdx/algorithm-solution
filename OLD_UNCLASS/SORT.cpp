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
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);
#define pb  push_back
#define INF 1000000000
#define VI vector<int>
#define VVI vector<VI>
int list[100],d[10][10],n;
vector<vector<int>> adj;
int hash(int * arr)
{
    int rs=0,k=8;
    
    REP(i,1,n)
    {
        rs=rs*k+arr[i];   
    }    
    return rs;
}
int main()
{
    freopen("SORT.IN",  "rt", stdin);
    freopen("SORT.OUT", "wt", stdout);

    //Doc day so dau tien
    string buffer;
    getline(cin,buffer);
    stringstream ss;
    ss<<buffer;
    while(ss>>list[n+1]) n++;
    REP(i,1,n) cout<<list[i]<<" ";
    //
    REP(i,1,n)
    REP(j,1,n)
    {
        scanf("%d",&d[i][j]);   
    }
    
    int listStart[10];
    REP(i,1,n) listStart[i]=i;
    int start=hash(listStart);
    int listEnd[10];
    REP(i,1,n) listEnd[i]=n+1-i;
    int end=hash(listEnd);
    adj.resize(
    
}
    
