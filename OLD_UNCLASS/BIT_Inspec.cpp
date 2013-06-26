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

int n;
int f[1005];

void update(int id, int val);
int getCumulative(int id);
int getValue(int start, int end);
int getSingle(int id);

int main()
{
    freopen("BIT_Inspec.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
        
    REP(i,1,20)
        cout  <<i<<" "<<(i & -i)<<endl;
    //cin >> n;
//    memset(f,0,sizeof(f));
//    int val;
//    REP(i,1,n)
//    {
//        int id;
//        cin >> id >> val;
//        update(id,val);
//        cout<<"update"<<id<<" "<<val<<endl;
//    }
//    
//    REP(i,1,n)
//        cout <<i <<" " << getSingle(i)<<endl;
        

    
}

void update(int id, int val)
{
    while(id <= n)
    {
        f[id] += val;
        id += id & -id;            
    }    
}

int getSingle(int id)
{
    int sum = f[id];
    int r = id - (id & -id);
    id--;
    while (id != r)
    {
        sum -= f[id];
        id -= id & -id;    
    } 
    return sum;   
}

int getCumulative(int id)
{
    int sum = 0;
    while(id > 0)
    {
        sum += f[id];
        id -= id & -id;    
    }    
    
    return sum;
}

int getValue(int low, int hi)
{
    return getCumulative(hi) - getCumulative(low-1);       
}
