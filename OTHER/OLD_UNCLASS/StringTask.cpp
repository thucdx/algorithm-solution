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
//ham
template <class T>  //so ko am
T gcd(T a, T b){if(b==0) return abs(a); else return gcd(b,a%b);}
template <class T>  
T lcm(T a, T b){ return a/gcd(a,b) *b;}

double EPS=1e-9;
string inp, out;
char toLower(char c)
{
    if(c>='A' && c<='Z') c+='a'-'A';
    return c;
}
bool isVowel(char c)
{
    c=toLower(c);
    return (c=='a' || c=='o' || c=='y' ||c=='e' || c=='u'||c=='i');
}
int main()
{
    //freopen("StringTask.IN", "rt", stdin);
    //freopen("StringTask.OUT", "wt", stdout);              
    cin>>inp;
    REP(i,0,inp.length()-1)
    {
        if(!isVowel(inp[i]))
        {
            out.push_back('.');
            out.push_back(toLower(inp[i]));    
        }
            
    }
    cout<<out;
    
}

