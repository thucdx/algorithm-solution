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

bool check(int width, int height, int size, vector<string>);
int solve(int wi, int hei, string s);
int main()
{
    freopen("input.txt",  "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int nTest;
    cin>>nTest;
    REP(i,1,nTest)
    {
        cout<<"Case #"<<i<<": ";
        int wi,hei;
        string txt;
        scanf("%d %d ",&wi,&hei);
        getline(cin,txt);
        cout<<solve(wi,hei,txt)<<endl;
    }
    
}
int solve(int wi, int hei, string s)
{
    vector<string> word;    
    vector<int> lword;
    
}
    
