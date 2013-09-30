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
#include <conio.h>
#include <ctime>
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
    freopen("DTKSUB.IN",  "wt", stdout);
    srand(time(NULL));
    int n=50000,k=20;
    cout<<n<<" "<<k<<endl;
    REP(i,1,n)
    {
        cout<<(char)(rand()%('z'-'a')+'a');    
    }
    cout<<endl;
        //getch();
    
}
    
