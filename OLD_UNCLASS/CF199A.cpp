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

VI fibo;

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    //init
    fibo.pb(0);
    fibo.pb(1);
    fibo.pb(1);
    int num = 2;
    int a = 1, b = 1;
    do
    {
        num = a + b;
        b = a;
        a = num;
        fibo.pb(num);        
    }
    while(num < 1e9);
    
    int n;
    cin >> n;
    VI::iterator it1, it2, it3;
    for(it1 = fibo.begin(); it1 != fibo.end(); it1++)
    {
        for(it2 = it1; it2 != fibo.end(); it2++)
        for(it3 = it2; it3 != fibo.end(); it3++)
        {
            if ( *it1 + *it2 + *it3 == n)
            {
                cout <<*it1 <<" "<<*it2<<" "<<*it3<<endl;
                return 0;    
            }    
        }    
    }
    
    cout <<"I'm too stupid to solve this problem" ;
    

    
}
