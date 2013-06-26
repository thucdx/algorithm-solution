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
    //freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int nTest;
    cin>>nTest;
    REP(i,1,nTest)
    {
        int k;
        string bit;
        cin>>k>>bit;
        int nStep=0, cntOne=0;
        for(int i=0;i<bit.length();i++)
        {
                if(bit[i]=='1')  cntOne++;
                else
                {
                    nStep+=cntOne/k;
                    cntOne=0;
                }
        }
        nStep+=cntOne/k;   
        //cout<<nStep<<endl; 
        if(nStep%2==0) cout<<"2\n";
        else cout<<"1\n";
    }
}
    
