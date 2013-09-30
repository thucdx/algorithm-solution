#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FIT(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int) (c).size()
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define SET(a, x) memset(a, x, sizeof(a));

typedef long long LL;
typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<pair<int, int> > VII;
#define INF 1000000000
int n,m,p,q,s,t;
struct cell
{
    int r,d; 
    cell(){
        r=0;
        d=   INF; 
    }
    cell(int _r, int _d)
    {
        r=_r;
        d=_d;
    }
    cell(int x, int y, int _d)
    {
        r=(x-1)*n +y;
        d=_d;
    }
};
queue<cell> b;
bool f[40005];
bool pass[40005];

int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	
    scanf("%d%d%d%d%d%d",&n,&m,&p,&q,&s,&t);
    int x,y;
	for(int i=0;i<m;i++)
	{
        scanf("%d%d",&x,&y);
        f[(x-1)*n+y ]=true;   
    }
    
    if(((p+q)%2 )!=((s+t)%2))
    {
         cout<<"-1"; return 0;
    }
    b.push(cell(p,q,0));
    pass[(p-1)*n+q]=true;
    cell c;
    int num,dis;
    int lim=n*n;
    int end=(s-1)*n+t;
    while(!b.empty())
    {
        c=b.front();
        //cout<<c.r<<endl;
        b.pop();
        num=c.r-(n+1);
        dis=c.d+1;
        while(!f[num]&& !pass[num] && num>0 && num <=lim)
        {   
            
            b.push(cell(num,dis));
            pass[num]=true;
            if(num==end){
                 cout<<dis;
                 return 0;
            }
            if(num%n==1) break;
            num-=(n+1);        
        }
        num=c.r+(n+1);
        while(!f[num] &&!pass[num]&& num>0 && num <= lim)
        {   

            if(num==end){
                 cout<<dis;
                 return 0;
            }  
            b.push(cell(num,dis));
            pass[num]=true; 
            if(num%n==0) break;
            num+=(n+1);        
        }
        num=c.r-(n-1);
        while(!f[num] && !pass[num]&&num>0 && num <=lim)
        {   
            b.push(cell(num,dis));
            if(num==end){
                 cout<<dis;
                 return 0;
            }    
            pass[num]=true;
            num-=(n-1);        
        }
        num=c.r+(n-1);
        while(!f[num] &&!pass[num]&& num>0 && num <=lim)
        {
            b.push(cell(num,dis));
            if(num==end){
                 cout<<dis;
                 return 0;
            }    
            pass[num]=true;
            num+=(n-1);        
        }        
    } 
    cout<<"-1";
}
