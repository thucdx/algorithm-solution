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

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

vector<string> sheet;
bool visit[55][55];
int n,m;

void solve();

void go(int x, int y);
int deg(int i, int j);
int countConnectedArea();

int main()
{
    //freopen("input.txt",  "rt", stdin);
    cin>>n>>m;
    sheet.resize(n+1);

    string s;
    REP(i,1,n)
    {
        cin>>s;
        sheet[i - 1] = s;
    }

    solve();
    return 0;
}

void solve()
{
    int nElem = 0;
    int minDeg = 5;

    REP(i,0,n-1)
    REP(j,0,m-1)
    {
        if(sheet[i][j] == '#')
        {
            nElem++;
            minDeg = min(minDeg, deg(i,j));

        }
    }

    if(nElem <= 2)
        cout<<-1;
    else if(minDeg == 1)
        cout<<1;
    else
    {
        REP(i,0,n-1)
        REP(j,0,m-1)
        {
            if(sheet[i][j] == '#')
            {
                sheet[i][j] = '.';

                if(countConnectedArea() > 1)
                {
                    cout<<1;
                    return;
                }

                sheet[i][j] = '#';
            }
        }

        cout<<2;
    }
}

void go(int x, int y)
{
    int nx,ny;
    visit[x][y] = true;

    REP(i,0,3)
    {
        nx = x + dx[i];
        ny = y + dy[i];

        if(nx >=0  && nx < n && ny >= 0  && ny < m && sheet[nx][ny] == '#' && !visit[nx][ny])
        {
            go(nx,ny);
        }
    }
}

int countConnectedArea()
{
    memset(visit, false, sizeof(visit));

    int nConnectedArea = 0;
    REP(i,0,n-1)
    REP(j,0,m-1)
    {
        if(sheet[i][j] == '#' && !visit[i][j])
        {
            go(i,j);
            nConnectedArea++;
        }
    }

    return nConnectedArea;
}

int deg(int x, int y)
{
    int result = 0 ;

    for(int i = 0;i < 4;i++)
    {
        int vx = x+ dx[i];
        int vy = y+ dy[i];

        if(vx >= 0 && vx < n && vy >= 0 && vy < m && sheet[vx][vy] == '#')
            result++;
    }

    return result;
}
