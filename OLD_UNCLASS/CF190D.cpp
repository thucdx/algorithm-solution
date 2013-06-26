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

int n,k;
vector<int> a;
map<int, int> rep;

//#include <conio.h>
int main()
{
    //freopen("input.txt", "rt", stdin);
    cin>> n >> k;
    int val;

    REP(i,1,n)
    {
        scanf("%d",&val);
        a.pb(val);
    }

    long long ret = 0;

    int i = 0,j = 0;
    int cur;

    bool isok = true;
    while(true)
    {
        if( j >= n) break;

        isok = false;
        do
        {
            if (j >= n) break;

            cur = a[j];
            int nSame ;
            if (rep.find(cur) != rep.end())
            {
                nSame = rep[cur];
                rep[cur] = ++nSame;
            }
            else rep[cur] = 1;

            j++;

            if (rep[cur] == k)
            {
                ret += (n + 1 - j);
                isok = true;
                break;
            }


        }
        while(true);

        if(isok)
        {
            do
            {
                if (i > j ) break;
                rep[a[i]] = rep[a[i]] - 1;
                i++;

                if(a[i - 1] == cur)
                    break;
                else
                {
                    ret += (n + 1 - j);
                }

            }
            while(true);
        }
    }

    cout<<ret;
}
