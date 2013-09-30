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

int main()
{
    //freopen("A.IN",  "rt", stdin);
    //freopen("A.OUT", "wt", stdout);
    int a;
    cin>>a;
    int nfoot,ninch;
    if(a%3==2) a++;
    nfoot=a/36;
    a=a%36;
    ninch=a/3;
//    if(a%3==2) ninch++;
    cout<<nfoot<<" "<<ninch;
//    getch();
    
    
}
    
