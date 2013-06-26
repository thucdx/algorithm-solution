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

string s;
bool isAllUpper=false;
int main()
{
    //freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    cin>>s;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]>='a' && s[i]<='z') {isAllUpper=true;break;}    
    }
    if(isAllUpper)
        cout<<s;
    else
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                s[i]=s[i]-'a'+'A';    
            }    
            else
            {
                s[i]=s[i]-'A'+'a';
            }
        }
        cout<<s;
    }
  // getch();

    
    
    
}
    
