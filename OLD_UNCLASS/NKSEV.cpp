#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
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
#define REMAIN 1337377
//ham
template <class T>  //so ko am
T gcd(T a, T b){if(b==0) return abs(a); else return gcd(b,a%b);}
template <class T>  
T lcm(T a, T b){ return a/gcd(a,b) *b;}

double EPS=1e-9;

int n;
string str;
set<string> s[105];
set<string> p;
int solve(string str);
int main()
{
    //freopen("NKSEV.IN", "rt", stdin);
    //freopen("NKSEV.OUT", "wt", stdout);
    int len;  
    cin>>str;
    scanf("%d",&n);
    string patern;
    REP(i,1,n)
    {
        cin>>patern;       
        p.insert(patern);
        len=patern.length();
        REP(i,1,len)
        {
            s[i].insert(patern.substr(0,i)); 
            //cout<<patern.substr(0,i)<<endl;   
        }
    }
    cout<<solve(str);                
}
int solve(string str)
{
    int len=str.length();
    if(len==0) return 1;
    string sub;
    int nSub;
    int result=0;
    REP(i,1,len)
    {
        sub=str.substr(0,i);
        nSub=i;
        if(s[nSub].count(sub)==0) break;
        if(p.count(sub)>0) //found;
        {
            result=(result+solve(str.substr(i)))%REMAIN;
        }
    }    
    return result;
}
