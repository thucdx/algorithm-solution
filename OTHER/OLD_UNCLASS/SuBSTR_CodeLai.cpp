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

void KMP(string str, string patern); //print list of position
void FailureFunction(string patern, int next[]);
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	string p,t;
	cin>>t>>p;
	KMP(t,p);
}
void FailureFunction(string patern, int next[])
{
     int len=patern.length();
     int i=1,j=0;
     next[0]=0;
     while(i<len)
     {
      if(patern[i]==patern[j])
      {
             next[i++]=++j;
      }
      else if(j>0){
                   j=next[j-1];
           }
           else {
                next[i++]=0;
                }            
     }     
}
void KMP(string t, string p)
{
     int m=t.length(), n=p.length();
     int * next=new int [n];
     FailureFunction(p,next);
     int i=0,j=0;
     while(i<m)
     {
      if(t[i]==p[j]){
                     if(j==n-1)
                     {
                      cout<<(i-j+1)<<" "; //position
                      j=next[j-1];
                     }
                     else {++i;++j;}          
     }
     else 
     {
      if(j>0) j=next[j-1]; 
      else {++i;}   
     }
     }
}
