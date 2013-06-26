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


int main()
{
    //freopen("?.IN", "rt", stdin);
    freopen("ANS.OUT", "wt", stdout);              
    int n=0;
    while(true)
    {
        n+=169; //n=a+5;
        int a=n-5;
        if(a%4==0 && (a+1)%9==0 && (a+2)%25==0 && (a+3)%49==0 && (a+4)%121==0)
        {
            cout<<a;
            break;    
        } 
    }
}

