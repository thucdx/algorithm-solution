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

int n, m;
vector<int> pos;
int main()
{
    cin >> n >> m;
    pos.resize(n+1);
        
    int ball = 1;
    double middle = (m+1)/2.0;
    int basket = (m+1)/2;           
        
    while(ball <= n)
    {        
         pos[ball] = basket;
         
         if(basket < middle)
         {
                basket = m+1 - basket;
         }
         else if(basket > middle)        
         {
                basket = m - basket;
                if(basket == 0) 
                    basket =(m+1)/2;
         }
         else if(basket * 2 == m+1)
         {
                basket --;
                if(basket == 0)
                    basket = 1;                   
         }         
         ball++;                     
    }
    REP(i,1,n)
    cout<<pos[i]<<endl;
}
