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
string s[20];
set<string> maxCur[20];
int nString;
void xuli(int i);
int main()
{
    freopen("chorus.IN",  "rt", stdin);
    freopen("chorus.OUT", "wt", stdout);
    scanf("%d\n",&nString);
    REP(i,0,nString-1)
    {
        getline(cin,s[i]);    
        cout<<s[i]<<endl;
       // process(i);
    }
    int i;
    for(i=0;i<nString;i++)
    {
        xuli(i);    
    }
}
void xuli(int k)
{
    //dua list set<string> maxCur[i] ,gom cac string do dai dai nhat, xuat hien >=2 lan .
//    return ;
    cout<<"process : "<<s[k]<<endl;
    return ;
    int len=s[k].length();
    int f[1505][1505];
    memset(f,0,sizeof(f));
    int maxLen=-1;
    for(int i=len-1;i>=0;i--)
    {
        for(int j=len-1;j>=i+1;j--)    
        {
            if(s[k][i]==s[k][j])
            {
                if(j+1 <len)
                    f[i][j]=1+f[i+1][j+1];    
                else f[i][j]=1;
            }
            else f[i][j]=0;
            if(f[i][j]>maxLen)
                maxLen=f[i][j];
        }
    } 
    cout<<s[k]<<" "<<maxLen<<endl;      
}
    
