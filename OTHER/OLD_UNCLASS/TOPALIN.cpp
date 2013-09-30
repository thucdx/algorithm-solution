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
#include <set>
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
string str;
int cnt[256];
vector<int> adj[256];
set<int> equal[256];
set<int> s;
bool f[256];
int result=0;
void duyet(int i);
int main()
{
    cin>>str;
    int len=str.length();
    memset(cnt,0,sizeof(cnt));
    REP(i,0,len-1)
        ++cnt[str[i]];
    int mid=(len+1)/2 -1;
    REP(i,0,mid)
    {
        char first=str[i], last=str[len-1-i];
        if(first==last) continue;
        adj[first].pb(last);
        adj[last].pb(first);    
    }
    //Tao cac disjoin set.
    REP(i,0,255) 
    {
        if(cnt[i]!=0 && !f[i])
        {    
             s.clear();
             duyet(i);    
             int maxCnt=-1;
             for(set<int>::iterator it=s.begin();it!=s.end();it++)
             {  
                    result+=cnt[*it];
                    if(cnt[*it]>maxCnt) maxCnt=cnt[*it];
             }
             result-=maxCnt;
        }
    }
    cout<<result;
}

void duyet(int i)
{
    if(f[i]) return;
    f[i]=true;
    s.insert(i);
    int len=adj[i].size();
    REP(t,0,len-1)
    {
        int j=adj[i][t];
        if(!f[j])
            duyet(j);
    } 
}
