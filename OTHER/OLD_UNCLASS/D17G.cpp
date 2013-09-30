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

using namespace std;

#define REP(i,a,b) for(int i=a;i<=b;++i)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a) REP(i,0,a);

#define pb  push_back
#define ins insert
#define all(x) begin(x), end(x)
#define sz(x) size(x)
#define ms(arr,val) memset(arr, val, sizeof(arr))

#define ll long long
#define INF 100000000000ll
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>

struct Point
{
    long long x, y;    
    Point(){}
    Point(long long _x, long long _y)
    {
        x = _x;
        y = _y;            
    }
};

long long f[201][201];
bool visit[201][201];
int n;

const int size = (1 << 16);
long long move(Point kng, Point tar);
long long khoang_cach(long long x, long long y);

long long dis[20][20];
long long minMove[size];
Point knight[20], target[20];

void input();
void solve();
void loang(int x, int y);

int r[] = {+2, +2, +1, -1, -2, -2, -1, +1};
int c[] = {-1, +1, +2, +2, +1, -1, -2, -2};
Point q[201 * 201];
bool thoaman(ll x, ll y){
    return (x >= 0 && x <= 200 && y >= 0 && y <= 200);
}

void init(){
    memset(f, -1, sizeof(f));
    f[20][20] = 0;
    int size = 0;
    q[size++] = Point(20, 20);
    REP(i,0, size-1){
        REP(j,0, 7) if(thoaman(q[i].x + r[j], q[i].y + c[j]) && f[q[i].x + r[j]][q[i].y + c[j]] == -1){
            f[q[i].x + r[j]][q[i].y + c[j]] = f[q[i].x][q[i].y] + 1;
            q[size++] = Point(q[i].x + r[j], q[i].y + c[j]);
        }
    }
}
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    init();
    
    int test =0;
    do
    {
        cin >> n;        
        if(n == 0) break;
        
        input();
        test++;
        cout<<test<<". ";        
        
        solve();
    }
    while(true);    
}

void input()
{
    long long x, y;
    REP(i,1,n)
    {
        cin >> x >> y;
        knight[i-1] = Point(x,y);
    }
    
    REP(i,1,n)
    {
        cin >> x >> y;
        target[i-1] = Point(x,y);
    }    
}

void solve()
{
    REP(i,0,n-1)
    REP(j,0,n-1)
    {
        dis[i][j] = move(knight[i],target[j]);    
    }    
    
    REP(i,0,((1<<n) -1 ))
        minMove[i] = INF;
    
    minMove[0] = 0;
    
    REP(i,1,((1<<n) - 1))
    {
        int count = 0;
        REP(j,0,n)
        
        {
            if((i>>j) & 1 != 0)
            {
                count++;
            }
        }
                   
        REP(j,0,n)
        {
            if((i>>j)&1 !=0) //bit thu j la 1
            {
                minMove[i] = min(minMove[i], minMove[i - (1<<j)] + dis[count-1][j]);                
            }    
        }    
    }    
    
    cout<<minMove[(1<<n) - 1]<<endl;
}

long long move(Point kng, Point tar)
{    
    return khoang_cach(abs(tar.x - kng.x), abs(tar.y - kng.y));    
}

long long khoang_cach(long long x, long long y)
{     
	ll res = 0, ret, t;     
	
	if(x <= 140 && y <= 140) 
		return f[x + 20][y + 20];     
	if(x > y) swap(x, y);          
	
	if(y > 2 * x)
    {         
		if(x > 30) t = (x - 30);         
		else t = 0;         
		x -= t; y -= t * 2; 
		res += t;         
		if(y <= 100) return res + f[x + 20][y + 20];         
		else
        {             
    		t = (y - 100) / 4;             
    		y -= t * 4;             
    		res += t * 2;             
    		return res + f[x + 20][y + 20];         
		}     
	}          
	else
    {         
		if(x > 30) t = min(x - 30, y - x);         
		else t = 0;         
		x -= t; y -= t * 2; res += t;         
		
		if(x <= 40) return res + f[x + 20][y + 20];         
		t = (x - 40) / 3;         
		x -= t * 3; y -= t * 3; res += t * 2;         
		
		if( y <= 120) return res + f[x + 20][y + 20];         		
		else
        {             
    		t = (y - 120) / 3;             
    		y -= t * 4;             
    		res += t * 2;             
    		return res + f[x + 20][y + 20];         
		}     
	} 
}

