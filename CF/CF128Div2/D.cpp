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

#define INF 1000000000
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>
const double eps = 1e-7;
double a, b, m;

struct point
{
    double x, y, z;
    
    point(){}
    point(double _x, double _y, double _z)
    {
        x = _x;
        y = _y;
        z = _z;            
    }     
    void operator=(const point& other) 
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }   
};

point ball;
point v;

bool equal(double a, double b)
{
    return abs(a-b) <= 1e-6;    
}

point update(double t)
{
    return point(ball.x + t * v.x , ball.y + t *v.y, ball.z + t*v.z);
}

bool inRightWall(point p)
{
    return equal(p.x,a) && eps + p.y >= 0 && eps +p.z >= 0  && p.z <= b + eps;    
}
bool inLeftWall(point p)
{
    return equal(p.x,0) && eps +p.y >= 0 && eps +p.z >= 0  && p.z <= b +eps;    
}

bool inFloor(point p)
{
    return equal(p.z,0) &&eps + p.x >= 0 && eps +p.x <= a && eps + p.y >= 0;
}

bool inCell(point p)
{
    return equal(p.z,b) && eps +p.x >= 0 && p.x <= a + eps && eps + p.y >= 0;
}

bool inDoor(point p)
{
    return equal(p.y,0)  && eps +p.x >= 0 && p.x <= a + eps  && eps + p.z >= 0 && p.z <= a +eps ;
}
int main()
{
    freopen("D.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    
    double x, y, z;
    cin >> a >> b >> m;
    cin >> x >> y >> z;
        
    ball = point(a/2, m, 0);
    v = point(x,y,z);
            
    do
    {
        double t;
        point tmp;
        //cout <<ball.x <<" "<<ball.y <<" "<<ball.z<<"_____ " << v.x <<" "<<v.y <<" "<<v.z<<endl;        
        //hit leftwall
        t = - ball.x / v.x;
        tmp = update(t);
        
        if(t > 0 && inLeftWall(tmp))
        {
            ball = tmp;
            v.x = - v.x;            
            continue;
        }
        
        //hit rightwall
        t = (a - ball.x) / v.x;
        tmp = update(t);        
        if(t > 0 && inRightWall(tmp) )
        {
            ball = tmp;
            v.x = - v.x;
            continue;
        }
        
        t = (b - ball.z) / v.z;
        tmp = update(t);
        if(t > 0 && inCell(tmp))
        {
            ball = tmp;
            v.z = -v.z;  
            continue;  
        }        
        
        //hit floor
        t = (- ball.z)/ v.z;
        tmp = update(t);        
        if(t > 0 && inFloor(tmp))
        {
            ball = tmp;
            v.z = - v.z;    
            continue;
        }               
         
        //hit door        
        t = -ball.y / v.y;
        tmp = update(t);        
        if( t > 0 && inDoor(tmp))
        {
            ball = tmp;
            v.y = -v.y;
            break;   
        }   
        break;      
    }
    while(true);
    
    printf("%.10lf %.10lf", ball.x , ball.z);
}
