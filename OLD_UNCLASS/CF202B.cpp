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

int nInver(vector<int> b);

string les[5];
string arc[25];
vector< vector<int> > exist;
int n,m;
bool isBreak = false;
int finalInver = INF;
int minInver = INF;   
int bestPos ;
int cc ;

void tries(int i);
vector<int> pos;
vector<int> ori;
int main()
{
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
    
    string str;    
    cin >> n;
    ori.resize(n);
    exist.resize(n);
    REP(i,1,n)
        ori[i-1]=i;
    
    REP(i,1,n)
    {
        cin>> str;
        les[i-1] = str;
    }      

    cin>>m;
    
    REP(i,1,m)
    {
        int len;
        cin >> len;
        REP(j,1,len)
        {
            cin>> str;
            arc[j-1] = str;   
        }
        
        exist.clear();
        exist.resize(n);
        bool isOk = true;
        REP(i,0,n-1)
        {
            REP(j,0,len-1)
            {
                if( arc[j] == les[i])
                {
                    exist[i].pb(j);
                }
            }    
            if( exist[i].size() == 0)
            {
                isOk = false;
                 break;
            }
        }
        
        if(!isOk) continue;
        
        minInver = INF;
        pos.clear();
        pos.resize(n);
        cc = 0;
        isBreak = false;
        tries(1);     
        if(minInver < finalInver)
        {
            bestPos = i;
            finalInver = minInver;   
        }               
    }
    
    if(minInver == INF)
    {
        cout << "Brand new problem!";
    }
    else
    {
        cout << bestPos<<endl;
        cout<<"[:";
        REP(i,1,n*(n-1)/2  - finalInver + 1)
            cout <<"|";
        cout<<":]";
    }
}

void tries(int i)
{  
    
    if(i == n +1)
    {   
        vector<int> b;
        b.resize(n);
        
        for(int t = 0; t < n; t++)
        {
            b[t] = 0;
            for(int j = 0; j < n; j++)
            {
                if( pos[j] <= pos[t])
                    b[t]++;
            }    
        }
        
        int nInv = nInver(b);        
        if (nInv < minInver)
            minInver = nInv;  
        return;                      
    }
    else 
    {
        int tmp ;
        for(int j  = 0; j < exist[i-1].size(); j++)
        {
            tmp = pos[i-1];
            pos[i-1] = exist[i-1][j];
            tries(i+1);  
            pos[i-1] = tmp;  
        }    
    } 
}

int nInver(VI b) //same Size;
{
    int rs = 0;
    int size = b.size();
    
    REP(i,0,size-1)
    REP(j,i+1, size-1)
    {
        if (b[j] < b[i]) rs ++;    
    }
    return rs;
}
