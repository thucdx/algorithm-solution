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

int n;
int order;
int route[50];

int f[20][20]; //so cach di tu [i][j]=>[n][n];
void calcF();
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	cin>>n;
	
	FOR(i,0,2*n)
	{
    	cin>>route[i];
     }
    
	int rs=0;
	int x=0,y=0;
	calcF();
	FOR(i,1,2*n)
	{
        if(route[i]>route[i-1]) //di xuong
        {
        rs+=f[x][y+1]; 
         ++x;
                                
        }
        else //sang phai
        {
        //rs-=f[x][y];
         ++y;
        }
    }
    cout<<rs+1<<endl; 
    cin>>order;

    order=order-1;
    x=0;y=0;
    cout<<0;
    int prev=0;
    FOR(i,1,2*n)
    {
       if(order>=f[x][y+1]) //dich xuong
       {
        cout<<" "<<(prev+1);
        prev++;
        order-=f[x][y+1];
        x++;
       }
       else 
       {
        cout<<" "<<(prev-1);
        prev--;   
        y++; 
       } 
    } 	
}
void calcF() //hang i ,cot j
{
 f[n][n]=1;
 FORD(j,n-1,0)
 FORD(i,n,j)
 {
  if (i+1<=n) f[i][j]+=f[i+1][j];
  if (j+1<=i) f[i][j]+=f[i][j+1];  
  //cout<<i<<" "<<j<<" "<<f[i][j]<<endl;       
 }     
}
