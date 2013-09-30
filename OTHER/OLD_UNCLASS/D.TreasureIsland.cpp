#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FIT(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int) (c).size()
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define SET(a, x) memset(a, x, sizeof(a));

typedef long long LL;
typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<pair<int, int> > VII;


struct point{
    char sym;
    int x,y;
};
bool cmp(point a, point b)
{
    if(a.sym<b.sym) return true;
    return false;    
}
point p[30];
char tr[1005][1005];
int n,m,nPoint,step;
char dir[100005];
int dis[100005];
void solve();
int main()
{
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	scanf("%d%d",&n,&m);
	getchar();
	int i,j,t;
	for(i=0;i<n;i++)
	{
    	for(j=0;j<m;j++)
    	{
            scanf("%c",&tr[i][j]); 
            if(tr[i][j]>='A' && tr[i][j]<='Z')
            {
                nPoint++;
                p[nPoint-1].sym=tr[i][j];
                p[nPoint-1].x=i;
                p[nPoint-1].y=j;
            }   
        }
       getchar();
    }
    scanf("%d",&step);
    getchar();
    for(i=0;i<step;i++)
    {
        scanf("%c %d",&dir[i],&dis[i]);
        if(i!=(step-1)) getchar();    
    }
    /*
    for(i=0;i<step;i++)
    {
        cout<<dir[i]<<" "<<dis[i]<<endl;    
    }
    */
    solve();
}
void solve()
{   
    bool hasSolution=false;
    sort(p,p+nPoint, cmp);
    int i,j,k,dx,dy;
    //xet tung diem
    for(i=0;i<nPoint;i++)
    {   //cout<<p[i].sym<<" "<<p[i].x<<" "<<p[i].y<<endl;
        //cout<<endl<<"TRACE"<<endl;
        //chay tung buoc
        bool isOk=true;
        int sX=p[i].x, sY=p[i].y;
        for(j=0;j<step;j++)
        {
           switch (dir[j])
           {
                case 'N': dx=-1; dy=0; break;
                case 'S': dx=1; dy=0; break;
                case 'E': dx=0; dy=1; break;
                case 'W': dx=0; dy=-1; break;;        
           }
           for(int t=1; t<=dis[j];t++)
           {    
                sX+=dx; sY+=dy;
                //cout<<"step: "<<t<<"  "<<sX<<" "<<sY<<endl;
                if(tr[sX][sY]=='#' || (sX<0) || (sX>=n) || (sY<0) || (sY>=m))
                {
                    isOk=false;
                    break;    
                }         
                
            }
            if(!isOk)     break;
        }
        if(isOk){
             printf("%c",p[i].sym);    
             hasSolution=true;
            }
    }
    if(!hasSolution) printf("no solution");
}
