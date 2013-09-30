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

struct P{
    int size;
    int index;
    P(){};
    P(int _size, int _index)
    {
        size=_size;
        index=_index;    
    }    
};

int n, m, x, y;
vector<int> a,b;
bool isFit(int i, int j);
vector<P> rs;

int main()
{
    //freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    //input    
    scanf("%d %d %d %d", &x, &y, &n, &m);
    int size;
    for(int i=0;i<x;i++)
    {
        scanf("%d",&size);
        a.push_back(size);  
//        cout<<size<<" ";  
    }
   // cout<<endl;
    for(int i=0;i<y;i++)
    {
        scanf("%d",&size);
        b.push_back(size);    
//        cout<<size<<" ";
    }
    //cout<<endl;
    int i=0,j=0, result=0;
    
    for(i=0;i<y;i++)
    {
        if(j>=x) break;
        if(isFit(a[j],b[i])){
            result++;
            
            P nP;
            nP.size=j+1;
            nP.index=i+1;
            
            rs.push_back(nP);
            
            j++;
        }
        else
        {
            while(a[j]+m<b[i])
            {

                j++;
                if(j>=x) break;                            
            }
        }       
    }
    cout<<result<<endl;
    for(vector<P>::iterator it = rs.begin();it!=rs.end();it++)
    {
//        cout<<it->size<<" "<<it->index<<endl;
        printf("%d %d\n",it->size, it->index);
    }
    
}
bool isFit(int i, int j)
{
    if(i-n<=j  && j<=i+m) return true;
    return false;
}    
