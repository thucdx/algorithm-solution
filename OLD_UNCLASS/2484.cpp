#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <sstream>
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
int n;
struct Point{
    int x,y;
};
long long f[15];
int strToInt(string s);
void solve(int numDig);
void init();
int main()
{
    string numDigit;

    freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    init();
    //return 0;
    while (true){
        cin>>numDigit;
        if(numDigit == "#") break;

        int numDig = strToInt(numDigit);

        solve(numDig);
    }
}
void init()
{
    //  f[i] so chu so can dung cho i chu so tro xuong.
    f[0] = 0;
    f[1] = 9;
    long long tenMu=10;
    for(int i=2;i<=10;i++){
        f[i]=f[i-1]+tenMu*9 *i;
        tenMu*=10;
    }


}
void solve(int numDig){
    int nDig=1, nPage =0;
    long long tenMu=1;
    while(numDig >=f[nDig]){
        tenMu*=10;
        nDig++;
    }

    nDig--;

    if ((numDig-  f[nDig]) % (nDig+1) == 0 )
    {
        nPage = (numDig - f[nDig]) / (nDig+1) + tenMu -1;
        cout<<nPage<<endl;
    }
    else cout<<"Impossible!"<<endl;
}
int strToInt(string s){
    stringstream ss;
    int iNum;

    ss<<s;
    ss>>iNum;

    return iNum;
}

