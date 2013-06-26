#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int dx[4] = {  0 , 0 ,-2 , 2  };
const int dy[4] = { -2 , 2 , 0 , 0  };
const char c[4] = { 'N','S','W','E' };

int Y,X,sy,sx,ey,ex;
vector<string> city, prev;
queue<pair<int,int> > q;

int possible (int y1, int x1, int y2, int x2) 
{
    int y = (y1+y2)/2, x = (x1+x2)/2;
    if (y < 0 || y >= 2*Y-1 || x < 0 || x >= 2*X-1) return 0;
    return city[y][x] == '-' || city[y][x] == '|';
}

int main () 
{

    scanf("%d %d\n", &Y, &X);

    for (int y = 0; y < 2*Y-1; y++) 
    {
        char tmp[2*X+10];
        gets(tmp);
        city.push_back(tmp);
    }

    for (int y = 0; y < 2*Y-1; y++)
        for (int x = 0; x < 2*X-1; x++) 
        {
            if (city[y][x] == 'S') { sy = y; sx = x; }
            if (city[y][x] == 'E') { ey = y; ex = x; }
        }

    prev = vector<string> (2*Y-1, string(2*X-1, '?') );

    prev[sy][sx] = '-';
    q.push(make_pair(sy,sx));

    while (!q.empty()) 
    {
        int y = q.front().first, x = q.front().second;
        q.pop();

        for (int d=0; d<4; d++) 
        {
            int ny = y + dy[d], nx = x + dx[d];
            if (possible(y, x, ny, nx) && prev[ny][nx] == '?') 
            {
	           prev[ny][nx] = d;
	           q.push(make_pair(ny, nx));
            }
        }
    }  
  
    string res = "X";
    while (prev[ey][ex] != '-') 
    {
        int d = prev[ey][ex];
        res = c[d] + res;
        ey -= dy[d];
        ex -= dx[d];
    }

    int cnt = 1;
    for (int i = 0; i < res.size()-1; i++)
        if (res[i+1] != res[i]) 
        {
            printf("%c %d\n", res[i], cnt);
            cnt=1;
        }
        else
            cnt++;
    return 0;
}
