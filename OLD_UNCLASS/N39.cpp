#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
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

double EPS=1e-9;


bool check(int i)
{
    int sumcs=0;
    int save=i;
    while(i!=0)
    {
        int cs=i%10;
        sumcs+=cs*cs*cs*cs*cs;
        i/=10;    
    }    
    return (sumcs==save);
}
int main()
{
//    freopen("?.IN", "rt", stdin);
    freopen("ANS.OUT", "wt", stdout);              
    long long rs=0;
    REP(i,10,99999999)
    {
        if(check(i)) rs+=i;    
    }
    cout<<rs;
}

