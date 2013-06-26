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
int n;
string s1, s2;
bool f[257];
void solve();

int main()
{
    //freopen("input.txt",  "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    cin>>s1>>s2;
    solve();
}

void solve()
{
    memset(f,sizeof(f), false);
    bool isRep = false;
    int len1 = s1.length();
    int len2 = s2.length();

    if(len1 != len2) {
        cout<<"NO";
        return;
    }

    int countDiff = 0;
    int first, second;

    REP(i,0,len1-1)
    {
        if(f[s1[i]]) isRep = true;
        f[s1[i]] = true;

        if(s1[i]!= s2[i])
        {
            countDiff ++;

            if(countDiff >2) {
                cout<<"NO";
                return;
            }

            if(countDiff == 1)
                first = i;
            else second = i;
        }
    }

    if(countDiff == 1)
    {
        cout<<"NO";
        return;
    }
    else if(countDiff == 0)
    {
        if(isRep)
            cout<<"YES";
        else cout<<"NO";
        return;
    }
    //cout<<first<<" "<<second<<endl;
    if(s1[second] == s2[first] && s1[first] == s2[second]){
        cout<<"YES";
        return ;
    }
    else cout<<"NO";

}

