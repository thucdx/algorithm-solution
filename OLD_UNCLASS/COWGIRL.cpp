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

int m,n;
int r,s;

int board[32];
int lim;
long long sum;
void exe(int i);
bool getBit(int nBit, int n);
void calc();
int main()
{
	//freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	//int nTest;
	//cin>>nTest;
	/*
	FOR(i,1,nTest)
	{
     cin>>m>>n;
     calc();              
    }
    */
    FOR(i,1,31)
    FOR(j,i,31)
    {
     m=i;n=j;
     if(m*n<=30)
     {
      calc();
      cout<<"f["<<m<<"]["<<n<<"]="<<sum<<endl;
     }
    }
}
bool getBit(int nBit, int n)
{
   return (n &(1<<nBit));  
}
void exe(int i)
{    
     if(i==s) {++sum;return;}
     FOR(num,0,lim)           
     {   board[i]=num;  
         bool isOk=true;   
         if(i>0)
         {
                            
             FOR(j,0,r-2)
             {                      
                  if(getBit(j,num)==getBit(j+1,num) && getBit(j,num)==getBit(j,board[i-1])
                                                    && getBit(j,num)==getBit(j+1,board[i-1]))
                  {
                      isOk=false;break;    
                  }
               
             } 
             
         }
         if(!isOk) continue;
         else  exe(i+1);
     } 
}
void calc()
{
    r=((m<n)? m: n);
    s=m*n/r;
    lim=(1<<r)-1;
    sum=0;
    //cout<<r<<" "<<s<<"CHON "<<endl;
    exe(0);  
    //cout<<sum<<endl;
}
