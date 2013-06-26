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

vector<int> cycle(int a);
int next(int a);

int main()
{
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
    int a, b;
    do
    {
        cin>> a>> b;
        if( a== 0 && b == 0) break;
    
        
        cout <<a <<" "<<b<<" ";        
        VI first = cycle(a);
        VI second = cycle(b);
        
        int s = INF;
        
        REP(i,0,second.size()-1)
        {
            REP(j,0,first.size()-1)
            {
                if(second[i] == first[j])
                {
                    int dis = 1 + i + 1 + j;
                    if(s > dis)
                        s= dis;   
                }    
            }    
        }
        if(s== INF) cout <<0<<endl;
        else 
            cout << s<<endl;

        
        
    }
    while(true);    

}

int next(int a)
{
    int sum = 0;
    while(a != 0)    
    {
        int dig = a%10;
        sum += dig*dig;
        a/=10;
    }
    return sum;
}

vector<int> cycle(int a )
{
    VI rs;    
    int nextNum = a;
    
    rs.pb(nextNum);
    while(true)
    {
        nextNum = next(nextNum);
        bool isExist = false;
        
        for(int i = 0; i< rs.size(); i++)
        {
            if(rs[i] == nextNum)
            {
                isExist = true;
                break;    
            }
        }
        
        if(isExist ) break;
        else rs.pb(nextNum);
    }
    
    return rs;
}
