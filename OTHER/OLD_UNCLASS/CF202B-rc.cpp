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

int inversion(vector<int> permutation);
vector<string> lesha;
vector<string> archieve;
vector<int> pos;

void attempt(int i);
int current;
int id;
int minInver;
int n, m;  
    
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
         
    int index;
    int similar = INF;
    
    string str;
    
    cin >> n;
    
    REP(i,1,n)
    {
        cin >> str;
        lesha.pb(str);    
    }
    
    cin >> m;
    REP(i,1,m)
    {
        int len;
        cin >> len;
        archieve.clear();
        
        REP(t,1,len)
        {
            cin >> str;
            archieve.pb(str);                
        }
        pos.clear();
        pos.resize(n);        
        current = INF;
        attempt(1);                           
        if(current < similar)
        {
            index = i;
            similar = current;   
        }            
    }
    
    if(similar != INF)
    {
        cout <<index<<endl;
        cout <<"[:";
        REP(i,1,(n*(n-1)/2 - similar + 1) )
            cout <<"|";
        cout <<":]";
    }
    else cout <<"Brand new problem!";
        
}

void attempt(int i )
{
    if (i > n)
    {
        current = min(current , inversion(pos));
        return ;    
    }
    
    REP(j,0,archieve.size()-1)
    {
        if (archieve[j] == lesha[i-1])
        {
            int tmp = pos[i-1];
            pos[i-1] = j;
            attempt(i+1);  
            pos[i-1] = tmp;              
        } 
    }
}

int inversion(vector<int> pos)
{
    int size = pos.size();
    int rs = 0;
    REP(i,0,size-1)
    {
        REP(j,i+1,size-1)
        {
            if (pos[i] > pos[j]) 
                rs ++;    
        }
    }    
    return rs;
}
